#include "Waypoints.h"

Waypoints::Waypoints(const std::wstring &id, const std::wstring &name, double latitude, double longitude) : id(id), name(name), street1(std::wstring()), street2(std::wstring()), latitude(latitude), longitude(longitude)
{
}

std::wstring Waypoints::getId()
{
   return id;
}

std::wstring Waypoints::getName()
{
  return name;
}

std::wstring Waypoints::getStreet1()
{
  return street1;
}

std::wstring Waypoints::getStreet2()
{
  return street2;
}

double Waypoints::getLatitude()
{
  return latitude;
}

double Waypoints::getLongitude()
{
  return longitude;
}

std::wstring Waypoints::toString()
{
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
	StringJoiner tempVar(L", ", Waypoints::class->getSimpleName() + L"[", L"]");
	return (&tempVar)->add(L"id='" + id + L"'")->add(L"name='" + name + L"'")->add(L"latitude=" + std::to_wstring(latitude))->add(L"longitude=" + std::to_wstring(longitude))->toString();
}
