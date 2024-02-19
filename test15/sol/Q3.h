
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

double dist(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void sortPoints(vector<Point>& ps){
	Point avg;
	for(Point pi : ps){
		avg.x+=pi.x;
		avg.y+=pi.y;
	}
	avg.x/=(int)ps.size();
	avg.y/=(int)ps.size();

	sort(ps.begin(),ps.end(),[&avg](Point a, Point b){
		return dist(a,avg) < dist(b,avg);
	});
}


#endif /* SRC_Q3_H_ */
