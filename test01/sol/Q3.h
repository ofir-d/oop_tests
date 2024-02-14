#include <iostream>
#include <fstream>

using namespace std;

class Point{
public:
	char color;
	virtual char dim() const = 0;
	virtual void save(ostream& out) const{
		// write the color to the ostream
		out.write(&color, 1);
	}
	virtual void load(ifstream& in){
		in.read(&color, 1);
	}
};

class Point1D : public Point{
public:
	int x;
	virtual char dim() const { return 1; }
	virtual void save(ostream& out) const{
		Point::save(out);
		out.write((char*)&x, sizeof(x));
	}
	virtual void load(ifstream& in){
		Point::load(in);
		in.read((char*)&x, sizeof(x));
	}
};

class Point2D : public Point{
public:
	int x,y;
	virtual char dim() const { return 2; }
	virtual void save(ostream& out) const{
		Point::save(out);
		out.write((char*)&x, sizeof(x));
		out.write((char*)&y, sizeof(x));
	}
	virtual void load(ifstream& in){
		Point::load(in);
		in.read((char*)&x, sizeof(x));
		in.read((char*)&y, sizeof(y));
	}
};

class Point3D : public Point{
public:
	int x, y,z;
	virtual char dim() const { return 3; }
	virtual void save(ostream& out) const{
		Point::save(out);
		out.write((char*)&x, sizeof(x));
		out.write((char*)&y, sizeof(x));
		out.write((char*)&z, sizeof(x));
	}
	virtual void load(ifstream& in){
		Point::load(in);
		in.read((char*)&x, sizeof(x));
		in.read((char*)&y, sizeof(y));
		in.read((char*)&z, sizeof(z));
	}
};

void savePoint(const Point& p,ofstream& out){
	char dim = p.dim();
	out.write(&dim, 1);
	p.save(out);
}

Point* loadPoint(ifstream& in){
	Point *p=NULL;
	char dim;
	in.read(&dim, 1);
	switch (dim){
	case 1:p = new Point1D(); break;
	case 2:p = new Point2D(); break;
	case 3:p = new Point3D(); break;
	}
	p->load(in);
	return p;
}

void testQ3API(){
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
