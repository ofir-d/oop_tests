
#ifndef SRC_Q2_H_
#define SRC_Q2_H_


#include "covid19.h"
#include <typeinfo>


int deepPositiveCount(Employee* e){
	Manager* m=dynamic_cast<Manager*>(e);
	if(m){
		int p=m->test();
		for(size_t i=0;i<m->getEmpSize();i++)
			p+=deepPositiveCount(m->getEmps()[i]);
		return p;
	}
	else
		return e->test();
}



#endif /* SRC_Q2_H_ */
