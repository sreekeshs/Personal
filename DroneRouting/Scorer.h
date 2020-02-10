#pragma once

#include <type_traits>

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/ 

template<typename T>
class Scorer
{
	static_assert(std::is_base_of<GraphNode, T>::value, L"T must inherit from GraphNode");

   public:
   virtual double computeCost(T from, T to) = 0;
};
