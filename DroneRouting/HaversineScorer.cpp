#include "HaversineScorer.h"
#include "Waypoints.h"

double HaversineScorer::computeCost(Waypoints *from, Waypoints *to)
{
	//double R = 6372.8; // Earth's radius in kilometers
	double R = 3958.8; //Earth's radius in miles

	double dLat = Math::toRadians(to->getLatitude() - from->getLatitude());
	double dLon = Math::toRadians(to->getLongitude() - from->getLongitude());
	double lat1 = Math::toRadians(from->getLatitude());
	double lat2 = Math::toRadians(to->getLatitude());

	double a = std::pow(std::sin(dLat / 2),2) + std::pow(std::sin(dLon / 2),2) * std::cos(lat1) * std::cos(lat2);
	double c = 2 * std::asin(std::sqrt(a));
	return R * c;
}
