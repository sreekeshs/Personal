#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <type_traits>

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/ 


template<typename T>
class Graph
{
	static_assert(std::is_base_of<GraphNode, T>::value, L"T must inherit from GraphNode");


   private:
   Set<T> *const nodes;
//JAVA TO C++ CONVERTER WARNING: C++ has no equivalent to a 'final' collection which allows modification of internal state:
//ORIGINAL LINE: private final Map<String, Set<String>> connections;
   std::unordered_map<std::wstring, Set<std::wstring>*> connections;

   public:
   virtual ~Graph()
   {
	   delete nodes;
   }

   Graph(Set<T> *nodes, std::unordered_map<std::wstring, Set<std::wstring>*> &connections) : nodes(nodes), connections(connections)
   {
   }

   virtual T getNode(const std::wstring &id)
   {
	  return nodes->stream().filter([&] (std::any node)
	  {
		  node::getId().equals(id);
	  }).findFirst().orElseThrow([&] ()
	  {
		  std::invalid_argument("No node found with ID");
	  });
   }

   virtual Set<T> *getConnections(T node)
   {
		return connections[node->getId()]->stream().map(this::getNode).collect(Collectors::toSet());
   }
};
