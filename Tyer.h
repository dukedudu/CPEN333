#ifndef __Tyre__
#define __Tyre__

#include "rt.h"
//#include "Receptionist.h"
#include "Assert.h"

class Tyre {
private:
	int UsedPercent;

public:
	//class Recep* theRecep;
	Tyre();
	
	void updateUsedPercent(int x) {
		assert(x >= 0 && x <= 100);
		UsedPercent = x;
	}

	int ShowUsedPercent(void) {
		assert(UsedPercent >= 0 && UsedPercent <= 100);
		return UsedPercent;
	}


};


Tyre::Tyre() {
	UsedPercent = 0;
	cout << "Tyre Constuctor being called..\n";
}



class OilFilter : public Tyre {
private:
	int UsedPercent;
public:
	OilFilter();
};

OilFilter::OilFilter() {
	UsedPercent = 0;
	cout << "OilFilter Constuctor being called..\n";
}


#endif