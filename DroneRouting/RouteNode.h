#pragma once

#include <string>
#include <limits>
#include <type_traits>

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/  


template<typename T>
class RouteNode : public Comparable<RouteNode*>
{
	static_assert(std::is_base_of<GraphNode, T>::value, L"T must inherit from GraphNode");

   private:
   const T current;
   T previous;
   double routeScore = 0;
   double estimatedScore = 0;

   public:
   virtual ~RouteNode()
   {
	   delete current;
	   delete previous;
   }

   RouteNode(T current) : RouteNode(current, nullptr, std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity())
   {
   }

   RouteNode(T current, T previous, double routeScore, double estimatedScore) : current(current)
   {
	  this->previous = previous;
	  this->routeScore = routeScore;
	  this->estimatedScore = estimatedScore;
   }

   virtual T getCurrent()
   {
	  return current;
   }

   virtual T getPrevious()
   {
	  return previous;
   }

   virtual double getRouteScore()
   {
	  return routeScore;
   }

   virtual double getEstimatedScore()
   {
	  return estimatedScore;
   }

   virtual void setPrevious(T previous)
   {
	  this->previous = previous;
   }

   virtual void setRouteScore(double routeScore)
   {
	  this->routeScore = routeScore;
   }

   virtual void setEstimatedScore(double estimatedScore)
   {
	  this->estimatedScore = estimatedScore;
   }

   int compareTo(RouteNode *other) override
   {
	  if (this->estimatedScore > other->estimatedScore)
	  {
		 return 1;
	  }
	  else if (this->estimatedScore < other->estimatedScore)
	  {
		 return -1;
	  }
	  else
	  {
		 return 0;
	  }
   }

   virtual std::wstring toString()
   {
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
		StringJoiner tempVar(L", ", RouteNode::class->getSimpleName() + L"[", L"]");
		return (&tempVar)->add(L"current=" + current)->add(L"previous=" + previous)->add(L"routeScore=" + std::to_wstring(routeScore))->add(L"estimatedScore=" + std::to_wstring(estimatedScore))->toString();
   }
};
