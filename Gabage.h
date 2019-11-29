#ifndef __Garbage__
#define __Garbage__

#include "rt.h"
#include "Tyer.h"
//#include "Receptionist.h"


class Garbage {
private:
	int UsedAirFilter;
	int UsedOil;
	//int UsedOilFilter;
	int UsedOFStorage;
	OilFilter* COF[10];
public:
	//class Recep* theRecep;
	Garbage();

	void RecevUsedAirFilter(int x) {
		UsedAirFilter = x;
		printf("Garbage: used Air Filter received.\n");
	}
	int ShowUsedAirFilter(void) {
		return UsedAirFilter;
	}

	void RecevUsedOil(int x) {
		UsedOil = x;
		printf("Garbage: Used Oil received.\n");
	}
	int ShowUsedOil(void) {
		return UsedOil;
	}

	void RecevUsedOilFilter(OilFilter* x) {
		assert(UsedOFStorage >= 0 && UsedOFStorage <= 10);
		UsedOFStorage++;
		COF[UsedOFStorage-1] = x;
		printf("Garbage: Used Oil Filter received.\n");
	}
	int ShowUsedOilFilter(void) {
		return UsedOFStorage;
	}



};


Garbage::Garbage() {
	UsedAirFilter = 0;
	UsedOil = 0;
	UsedOFStorage = 0;
	cout << "Garbage Constuctor being called..\n";
}

#endif#include "rt.h"
