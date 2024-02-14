#include "Student.h"

class MAStudent : virtual public Student {
	bool wThesis;
public:
	MAStudent(const char name, int age, bool wThesis) : Student::Student(name, age), wThesis(wThesis) {}
	virtual void print(ostream& out) {
		Student::print(out);
		if (wThesis)
		{
			out << "with thesis" << endl;
		}
		else
		{
			out << "without thesis" << endl;
		}
	}
};

class PhdStudent : virtual public Student {
protected:
	int publications;
public:
	PhdStudent(const char name, int age, int publications) : Student::Student(name, age), publications(publications) {}
	virtual void print(ostream& out) {
		Student::print(out);
		out << "publications: " << publications << endl;
	}
};

class DirectPhdStudent : public PhdStudent, public MAStudent {
	int year;
public:
	DirectPhdStudent(const char name, int age, int publications, int year) : Student::Student(name, age), PhdStudent::PhdStudent(name, age, publications),
		MAStudent(name, age, true), year(year) {}

	virtual void print(ostream& out) {
		MAStudent::print(out);
		out << "publications: " << this->publications << endl;
		out << "year: " << year << endl;
	}
};

void testQ2API() { // ============ do not change ===============
	Student s('A', 20);
	s.print(cout);
	cout << "---" << endl;
	Student* s2 = new MAStudent('B', 21, false);
	s2->print(cout);
	cout << "---" << endl;
	Student* s3 = new MAStudent('C', 22, true);
	s3->print(cout);
	cout << "---" << endl;
	Student* s4 = new PhdStudent('D', 23, 2);
	s4->print(cout);
	cout << "---" << endl;
	Student* s5 = new DirectPhdStudent('E', 24, 2, 3);
	s5->print(cout);
	cout << "---" << endl;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
	/* expected output:
	name: A
	age: 20
	---
	name: B
	age: 21
	without thesis
	---
	name: C
	age: 22
	with thesis
	---
	name: D
	age: 23
	publications: 2
	---
	name: E
	age: 24
	with thesis
	publications: 2
	year: 3
	---
	*/
}
