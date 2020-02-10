#pragma once

#include "Scorer.h"
#include <cmath>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
class Waypoints;

/*
* Sample from 
* https://www.baeldung.com/java-a-star-pathfinding
*/

class HaversineScorer : public Scorer<Waypoints*>
{
public:
	double computeCost(Waypoints *from, Waypoints *to) override;
};
