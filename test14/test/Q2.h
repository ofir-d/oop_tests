
#ifndef SRC_Q2_H_
#define SRC_Q2_H_


#include "covid19.h"
#include <typeinfo>


int deepPositiveCount(Employee* e){
	int sum = 0;
	Manager* man = dynamic_cast<Manager*>(e);
	if (man)
	{
		Employee** emps = man->getEmps();
		int emps_size = man->getEmpSize();
		for (int i=0; i< emps_size; i++)
		{
			sum += deepPositiveCount(emps[i]);
		}
	}
	if (e->test())
	{
		sum++;
	}
	return sum;
}



#endif /* SRC_Q2_H_ */
