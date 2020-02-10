#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
template<typename T>
class Graph;
class Waypoints;
template<typename T>
class RouteFinder;

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/ 


class mapTest
{

   private:
   Graph<Waypoints*> *map;
   RouteFinder<Waypoints*> *routeFinder;

   public:
   virtual ~mapTest()
   {
	   delete map;
	   delete routeFinder;
   }

   virtual void setUp();

   virtual void findRoute(const std::wstring &start, const std::wstring &end);

	static void main(std::vector<std::wstring> &args);
};
