#pragma once

#include "Graph.h"
#include "Scorer.h"
#include "RouteNode.h"
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>
#include "exceptionhelper.h"
#include <type_traits>

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/ 


template<typename T>
class RouteFinder
{
	static_assert(std::is_base_of<GraphNode, T>::value, L"T must inherit from GraphNode");

private:
	Graph<T> *const graph;
	Scorer<T> *const nextNodeScorer;
	Scorer<T> *const targetScorer;

public:
	virtual ~RouteFinder()
	{
		delete graph;
		delete nextNodeScorer;
		delete targetScorer;
	}

	RouteFinder(Graph<T> *graph, Scorer<T> *nextNodeScorer, Scorer<T> *targetScorer) : graph(graph), nextNodeScorer(nextNodeScorer), targetScorer(targetScorer)
	{
	}

	virtual std::vector<T> findRoute(T from, T to)
	{
		std::unordered_map<T, RouteNode<T>*> allNodes;
		std::list<RouteNode*> openSet = new PriorityQueue<RouteNode*>();

		RouteNode<T> *start = new RouteNode<T>(from, nullptr, 0, targetScorer->computeCost(from, to));
		allNodes.emplace(from, start);
		openSet.push_back(start);

		while (!openSet.empty())
		{
			std::wcout << L"Open Set contains: " << openSet.stream().map(RouteNode::getCurrent).collect(Collectors::toSet()) << std::endl;
			RouteNode<T> *next = openSet.pop_front();
			std::wcout << L"Looking at node: " << next << std::endl;

			if (next->getCurrent().equals(to))
			{
				std::wcout << L"Found our destination!" << std::endl;

				std::vector<T> route;
				RouteNode<T> *current = next;
				do
				{
					route.push_back(0, current->getCurrent());
					current = allNodes[current->getPrevious()];
				} while (current != nullptr);

				std::wcout << L"Route: " << route << std::endl;

//JAVA TO C++ CONVERTER TODO TASK: A 'delete start' statement was not added since start was passed to a method or constructor. Handle memory management manually.
				return route;
			}

			graph->getConnections(next->getCurrent())->forEach([&] (std::any connection)
			{
				double newScore = next->getRouteScore() + nextNodeScorer->computeCost(next->getCurrent(), connection);
				RouteNode<T> tempVar(connection);
				RouteNode<T> *nextNode = allNodes.getOrDefault(connection, &tempVar);
				allNodes.emplace(connection, nextNode);
				if (nextNode->getRouteScore() > newScore)
				{
					nextNode->setPrevious(next->getCurrent());
					nextNode->setRouteScore(newScore);
					nextNode->setEstimatedScore(newScore + targetScorer->computeCost(connection, to));
					openSet.push_back(nextNode);
					std::wcout << L"Found a better route to node: " << nextNode << std::endl;
				}
			});
		}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete start' statement was not added since start was passed to a method or constructor. Handle memory management manually.
		throw IllegalStateException(L"No route found");
	}

};
