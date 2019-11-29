#ifndef __Store__
#define __Store__

#include "rt.h"
#include "Tyer.h"
//#include "Receptionist.h"


class Store {
private:
	int AirFilter;
	int Oil;
	int OilFilterStorage=10;
	int TyreStorage = 10;
	Tyre* CTyre[10];
	OilFilter* COF[10];

public:
	//class Recep* theRecep;
	Store();
	int giveAirFilter(void){
		if (AirFilter > 0) {
			AirFilter--;
			return 100;
		}
		else {
			printf("Air Filter not enough!\n");
			return 0;
		}
	}

	int giveOil(void) {
		if (Oil > 0) {
			Oil--;
			return 100;
		}
		else {
			printf("Oil not enough!\n");
			return 0;
		}
	}

	OilFilter* giveOilFilter(void) {
		if (OilFilterStorage > 0) {
			OilFilterStorage--;
			return COF[OilFilterStorage-1];
		}
		else {
			printf("Oil Filter not enough!\n");
			return NULL;
		}
	}

	Tyre* giveTyre(void) {
		if (TyreStorage > 0) {
			TyreStorage--;
			return CTyre[TyreStorage-1];
		}
		else {
			printf("Tyre not enough!\n");
			return NULL;
		}
	}
	




};


Store::Store() {
	//Cuscar = new Car;
	AirFilter = 10;
	Oil = 10;
	OilFilterStorage = 10;
	CTyre[0] = new Tyre();
	CTyre[1] = new Tyre();
	CTyre[2] = new Tyre();
	CTyre[3] = new Tyre();
	CTyre[4] = new Tyre();
	CTyre[5] = new Tyre();
	CTyre[6] = new Tyre();
	CTyre[7] = new Tyre();
	CTyre[8] = new Tyre();
	CTyre[9] = new Tyre();
	for (int i = 0; i < 10; i++) {
		COF[i] = new OilFilter();
	}
	cout << "Store Constuctor being called..\n";

}

#endif