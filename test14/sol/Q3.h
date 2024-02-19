
#ifndef SRC_Q3_H_
#define SRC_Q3_H_

#include "covid19.h"

class BrCovid20: virtual public Covid19{
	double ph;
public:
	BrCovid20(int id,double ph):Covid19(id),ph(ph){}
	virtual ~BrCovid20(){}
};

class SaCovid20:virtual public Covid19{
	char m;
public:
	SaCovid20(int id,char m):Covid19(id),m(m){}
	virtual ~SaCovid20(){}
};

class IlCovid21:public BrCovid20, public SaCovid20{
	int x;
public:
	IlCovid21(int x):Covid19(972),BrCovid20(0,2.0),SaCovid20(0,'s'),x(x){}
	virtual ~IlCovid21(){}
};


#endif /* SRC_Q3_H_ */
