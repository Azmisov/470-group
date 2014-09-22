#ifndef POLYGON_H
#define	POLYGON_H

#include <vector>
#include <math.h>
#include "Vector2d.h"
#include "Obstacle.h"

#define EPSILON 1e-5
#define PI_2 6.28318530718
//30: 0.86602540378 0.5
//45: 0.70710678118 0.70710678118
#define COS_TANGENTIAL 0.86602540378
#define SIN_TANGENTIAL .5
#define TANG_THRESHOLD .3

class Polygon : public Obstacle {
private:
	double area_cache;
	std::vector<Vector2d> vertices;
	
public:
	Polygon();
	Polygon(const Polygon& orig);
	virtual ~Polygon();
	
	//Add vertex to back of vertex list (clockwise vertex convention)
	void addPoint(Vector2d p);
	void addPoint(double x, double y);
	//Point access
	int size();
	const double& operator[](int idx) const;	
	
	//Does this shape contain this point
	bool contains(const Vector2d &p) const;
	bool contains(double x, double y) const;
	//Compute area of shape
	double area();
	//Bounding box for shape
	void bounds(double bounds[4]);
	//Compute convex hull of polygon
	const Polygon convexHull();
	//Join this poly with another, if they intersect; returns true if they intersect
	bool join(const Polygon &shape);
	//Compute potential field of polygon at point
	const Vector2d potentialField(const Vector2d &station, const Vector2d &dir) const;
};

#endif

