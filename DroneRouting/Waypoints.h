#pragma once

#include "GraphNode.h"
#include <string>

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/  


class Waypoints : public GraphNode
{
   private:
   const std::wstring id;
   const std::wstring name;
   const std::wstring street1;
   const std::wstring street2;
   const double latitude;
   const double longitude;

   public:
   Waypoints(const std::wstring &id, const std::wstring &name, double latitude, double longitude);

   /*public Waypoints(String id, String street1, String street2, double latitude, double longitude) {
      this.id = id; 
      this.street1 = street1; 
      this.street2 = street2; 
      this.latitude = latitude; 
      this.longitude = longitude;
      name = null;
   }*/

   std::wstring getId() override;

	virtual std::wstring getName();

	virtual std::wstring getStreet1();

	virtual std::wstring getStreet2();

	virtual double getLatitude();

	virtual double getLongitude();

	virtual std::wstring toString();
};
