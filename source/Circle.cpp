#include "Circle.h"

Circle::Circle(){}
Circle::Circle(bool attract) : Field(attract){}
Circle::Circle(const Circle& orig){}
Circle::Circle(Vector2d l, double r, bool attract){loc = l; radius = r; attractive = attract;}
Circle::~Circle(){}

double Circle::area(){
	return PI * radius * radius;
}
void Circle::bounds(double bounds[4]){
	bounds[1] = loc[0] + radius;
	bounds[0] = loc[0] - radius;
	bounds[4] = loc[1] + radius;
	bounds[3] = loc[1] - radius;
}
//Compute potential field of polygon at point; it adds a tangential field based on point direction
const Vector2d Circle::potentialField(const Vector2d &station, const Vector2d &dir) const{
	
	Vector2d force = Vector2d(0);
	double dx = station[0]-loc[0];
	double dy = station[1]-loc[1];
	
	double distance = sqrt(pow(dx,2) + pow(dy,2));
	double spread = 10*radius;
	double alpha = 2;
	if (attractive){
		/*
		if (distance < radius)
			return force;
		else if (distance > spread){
			//force.setData(dx/distance, dy/distance);
			force.setData(dx, dy);
			force *= spread*alpha;
		}
		else{
			//double ratio = distance/(10*radius);
			force.setData(dx, dy);
			force *= alpha*(distance-radius);
			//force.setData(dx*ratio/distance, dy*ratio/distance);
		}
		*/
		force.setData(dx, dy);
		force /= distance;
		//TODO: linear decay inside of circle
	}
	else{
		if (distance > 10 * radius)
			force.setData(0, 0);
		else{
			double ratio = distance/(10*radius);
			ratio = 1-ratio;
			force.setData(dx*ratio/distance, dy*ratio/distance);
		}
	}
	
    return force;
}
