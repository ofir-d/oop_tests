
#include <list>
#include <string.h>
#include "Student.h"

using namespace std;

template <class E>
class Map {
	class Entry {
	public:
		const char* key;
		E value;
		Entry(const char* k, const E& val) :key(k), value(val) {}
	};

	list<Entry> data;
public:
	void put(const char* key, const E& value) {
		data.push_front(Entry(key, value));
	}

	E& operator[](const char* key) {
		typename list<Entry>::iterator it = data.begin();
		while (it != data.end() && strcmp(key, (*it).key) != 0) it++;
		if (it != data.end()) {
			E ret = (*it).value;
			data.erase(it);
			put(key, ret);
			return (*data.begin()).value;
		}
		throw "key not found";
	}

	template<class func>
	func forEachValue(func f) {
		typename list<Entry>::iterator it = data.begin();
		
		while (it != data.end()) {
			f((*it).value);
			it++;
		}
		return f;
	}
};

void testQ1API() {
	Map<Student> map;
	map.put("A", Student('A', 25));
	map.put("B", Student('B', 22));
	map.put("C", Student('C', 26));

	map.forEachValue([](const Student& s) {
		cout << s.getName();
	});
	cout << endl; // expected output: CBA

	cout << map["B"].getAge() << endl; // expected output: 22

	map.forEachValue([](const Student& s) {
		cout << s.getName();
	});
	cout << endl; // expected output: BCA

	map["B"].setAge(27);
	cout << map["B"].getAge() << endl; // expected output: 27

	try {
		cout << map["D"].getAge() << endl; // throws exception
	}
	catch (const char* msg) {
		cout << msg << endl; // "key not found"
	}
}

