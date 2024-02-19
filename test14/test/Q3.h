
#ifndef SRC_Q3_H_
#define SRC_Q3_H_

#include "covid19.h"

class BrCovid20: virtual public Covid19{
	double ph;
public:
	BrCovid20(int id, double ph) : Covid19(id), ph(ph) {}
};

class SaCovid20: virtual public Covid19{
	char m;
public:
	SaCovid20(int id, char m): Covid19(id), m(m){}
};

class IlCovid21: public SaCovid20, public BrCovid20{
	int x;
public:
	IlCovid21(int x) : Covid19(972), SaCovid20(972, 's'), BrCovid20(972, 2.0), x(x) {}
};


#endif /* SRC_Q3_H_ */
