
#ifndef SRC_Q3_H_
#define SRC_Q3_H_

#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

///// DO NOT CHANGE /////////////
struct Point{
	int x,y;
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}

};
/////////////////////////////////
Point getAverage(vector<Point>& ps)
{
	int x = 0;
	int y = 0;
	for (Point p : ps)
	{
		x += p.x;
		y += p.y;
	}
	return Point(x / ps.size(), y / ps.size());
}

int distance(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// you may add helper functions and types

void sortPoints(vector<Point>& ps){
	Point avg = getAverage(ps);
	sort(ps.begin(), ps.end(), [&](Point x, Point y) {
		return distance(avg, x) < distance(avg, y);
	});
}


#endif /* SRC_Q3_H_ */
