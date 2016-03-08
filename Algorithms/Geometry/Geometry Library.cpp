#include <bits/stdc++.h>

//PS.: PI = acos(-1)
const double PI = 3.1415926535897932384626433832795028841971693993751058;

//Epsylon
const double EPS = 1e-7;

//Converts DEGREE angle to RADIAN angle
#define DEG_TO_RAD(theta) (theta * PI / 180.0)

//Converts RADIAN angle to DEGREE angle
#define RAD_TO_DEG(theta) (theta * 180.0 / PI)

using namespace std;

/** 
*** Simple Entitys 
**/

//Point
struct point{
	double x, y;
	point() {}
	point(double x, double y):
		x(x), y(y) {}
};

//Line
struct line{
	double a, b, c;
	point p, q;
	line() {}
	line(point p, point q) {
		a = p; b = q;
		if (fabs(p.x - q.x) < EPS) { //Vertical Line
			a = 1.0; b = 0.0; c = -p.x;
		} else {
			a = -(double)(p.y - q.y) / (p.x - q.x);
			b = 1.0;
			c = -(double)(a * p.x) - p.y;
		}
	}
};

//Vector
struct vec{
	double x, y;
	point a, b;
	vec() {}
	vec(double x, double y):
		x(x), y(y) {}	
	vec(point p, point q) {
		x = b.x - a.x;
		y = b.y - a.y);
	}
};

/** 
*** Basic Operations
**/

//Distance between two points
double distPointToPoint(point p, point q) {
	return hypot(p.x - q.x, p.y - q.y);
}

//Rotate a point by theta degress in Counter Clockwise around Origin(0, 0)
double rotatePoint(point p, double theta) {
	double rad = DEG_TO_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
				 p.x * sin(rad) + p.y * cos(rad));
}

bool areParallel(line m, line n) {
	return (fabs(m.a - n.a) < EPS && fabs(m.b - n.b) < EPS);
}

bool areSame(line m, line n) {
	return (areParallel(m, n) && fabs(m.c - n.c) < EPS);
}

bool areIntersect(line m, line n) {
	return !areParallel(m, n);
}

//CALL THIS IF, AND ONLY IF areInsersect(m, n) == true
point getLineIntersection(line m, line n) {
	point res;
	ret.x = (n.b * m.c - m.b * n.c) / (n.a * m.b - m.a * n.b);
	if (fabs(m.b) > EPS) 
		ret.y = -(m.a * ret.x + m.c);
	else 
		ret.y = -(n.a * ret.x + n.c)
	return res;
}

//Scalar Product
vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

//Translate Point p by Vector v
point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

//Dot Product
double dot(vec a, vec b) {
	return a.x * b.x + a.y * b.y;
}

//Norm Squared
double norm(vec v) {
	return v.x * v.x + v.y * v.y;
}

double distPointToLine(line l, point p) {
	vec ap = vec(l.p, p), ab = vec(l.p, l.q);
	double u = dot(ap, ab) / norm(ab);
	c = translate(l.a, scale(ab, u));
	return distPointToPoint(p, c);
}



int main() {
	return 0;
}