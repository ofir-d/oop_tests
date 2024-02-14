#include <iostream>
#include <fstream>
using namespace std;

class Point{
public:
	char color;
	virtual char dim() const = 0;
	virtual void save(ostream& out) const{
		out << color;
	}
	virtual void load(ifstream& in){
		in >> color;
	}
};

class Point1D : public Point{
public:
	int x;
	Point1D() : x(0) {}
	char dim() const { return 0; }
	virtual void save(ostream& out) const {
		out << '1';
		Point::save(out);
		out << x;
	}
	virtual void load(ifstream& in) {
		Point::load(in);
		char a;
		in >> a;
		x = a - 48;

	}
};

class Point2D : public Point{
public:
	int x,y;
	Point2D() : x(0), y(0) {}
	char dim() const { return 0; }
	virtual void save(ostream& out) const {
		out << '2';
		Point::save(out);
		out << x << y;
	}
	virtual void load(ifstream& in) {
		Point::load(in);
		char a, b;
		in >> a >> b;
		x = a - 48;
		y = b - 48;
	}
};

class Point3D : public Point{
public:
	int x, y,z;
	Point3D() : x(0), y(0), z(0) {}
	char dim() const { return 0; }
	virtual void save(ostream& out) const {
		out << '3';
		Point::save(out);
		out << x << y << z;
	}
	virtual void load(ifstream& in) {
		Point::load(in);
		char a, b, c;
		in >> a >> b >> c;
		x = a - 48;
		y = b - 48;
		z = c - 48;
	}
};

void savePoint(const Point& p,ofstream& out){
	const Point3D *p3 = dynamic_cast<const Point3D*>(&p);
	if (p3)
	{
		p3->save(out);
		return;
	}
	const Point2D* p2 = dynamic_cast<const Point2D*>(&p);
	if (p2)
	{
		p2->save(out);
		return;
	}
	const Point1D* p1 = dynamic_cast<const Point1D*>(&p);
	if (p1)
	{
		p1->save(out);
		return;
	}
}

Point* loadPoint(ifstream& in){
	char type;
	in >> type;
	switch (type)
	{
		case '1':
		{
			Point1D* p1 = new Point1D();
			p1->load(in);
			return p1;
		}
		case '2':
		{
			Point2D* p2 = new Point2D();
			p2->load(in);
			return p2; 
		}
		case '3':
		{
			Point3D * p3 = new Point3D();
			p3->load(in);
			return p3;
		}
		default:
			throw "no point found";
	}
}

void testQ3API(){ // ============ do not change ===============
	Point3D p;
	p.color = 'r';
	p.x = 3;
	p.y = 4;
	p.z = 5;
	ofstream out("p3d.dat", ios::binary);
	savePoint(p, out);
	out.close();

	ifstream in("p3d.dat", ios::binary);
	Point* pd = loadPoint(in);
	in.close();
	Point3D * p3d = dynamic_cast<Point3D*>(pd);
	if (p3d && p3d->color == 'r' && p3d->x == 3 && p3d->y == 4 && p3d->z == 5)
		cout << "great! :)" << endl;
	else
		cout << "not great! :(" << endl;	

	delete p3d;
}
