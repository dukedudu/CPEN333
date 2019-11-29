#ifndef __Tech__
#define __Tech__

#include "rt.h"
#include "Car.h"
#include "Stores.h"
#include "Recycling.h"
#include "Gabage.h"
#include "Tyer.h"
#include "Assert.h"
#define AF 1
#define OI 2
#define OF 3
#define TY 4

class Recep;
class Tech {
private:
	Car* Techcar;
	int AirFilter;
	int Oil;
	//int OilFilter;
	//int Tyre;
	Tyre* TempTyre;
	OilFilter* COF;
	int line;

public:
	class Recep* theRecep; 	
	Store AStore;
	Recycling ARecycling;
	Garbage AGarbage;
 	
	void getCar(Car* car) {
		Techcar = car;
	}

	Car* sendCar(void) {
		return Techcar;
	}

	void SwapAirFilter(void) {
		SendAirFilter(Techcar->GiveAirFilter());
		Techcar->recevAirFilter(AirFilter);
		Techcar->AddItem(AF);
	}
	void SwapOil(void) {
		SendOil(Techcar->GiveOil());
		Techcar->recevOil(Oil);
		Techcar->AddItem(OI);
	}
	void SwapOilFilter(void) {
		SendOilFilter(Techcar->GiveOilFilter());
		getOilFilter();
		Techcar->recevOilFilter(COF);
		Techcar->AddItem(OF);
	}
	void SwapTyre(int x) {
		//TempTyre = aTyre;
		
		SendUsedTyre(Techcar->GiveTyre(x));
		getTyre();
		Techcar->recevTyre(x, TempTyre);
		Techcar->AddItem(TY);
	}

//////////////////////////////////////////////////
	void ServiceCar() {
		if (Techcar->ShowOil() == 0) {
			printf("The car run out of oil. Adding...\n");
			getOil();
			if (Oil == 0) {
				return;
			}
			else {
				SwapOil();
			}
		}
		if (Techcar->ShowOilFilter() >50) {
			printf("The car Oil Filter broken. changing...\n");
			getOilFilter();
			if (COF == NULL) {
				return;
			}
			else {
				SwapOilFilter();
			}
		}
		if (Techcar->ShowAirFilter() == 0) {
			printf("The car Air Filter broken. changing...\n");
			getAirFilter();
			if (AirFilter == 0) {
				return;
			}
			else {
				SwapAirFilter();
			}
		}
	
		for (int i = 0; i < line; i++) {
			checkTyresforwear(i);
		}

	}
////////////////////////////////////////////////////

	void updateindex(int x) {
		line = x;
	}

	void checkTyresforwear(int x) {
		assert(x >= 0 && x <= 3);
		printf("Tyre:%d's used percentage: %d\n", x, Techcar->ShowTyre(x));
		if (Techcar->ShowTyre(x) > 50) {
			printf("Tyre %d is broken...\n", x);
			SwapTyre(x);
			printf("SwapTyre %d succeed...\n", x);
		}
		else {
			printf("Tyre %d is ok, does not need to change..\n", x);
			return;
		}
		
	}

	void getOil(void) {
		Oil = AStore.giveOil();
	}
	void getAirFilter(void) {
		AirFilter = AStore.giveAirFilter();
	}
	void getOilFilter(void) {
		COF = AStore.giveOilFilter();
	}
	void getTyre(void) {
		
		TempTyre = AStore.giveTyre();
	}
	
	void SendUsedTyre(Tyre* aTyre) {
		ARecycling.RecevTyre(aTyre);
	}

	void SendOil(int x) {
		AGarbage.RecevUsedOil(x);
	}
	void SendOilFilter(OilFilter* x) {
		AGarbage.RecevUsedOilFilter(x);
	}
	void SendAirFilter(int x) {
		AGarbage.RecevUsedAirFilter(x);
	}


	
	Tech();
};


Tech::Tech() {
	//Cuscar = new Car;
	AirFilter = 0;
	Oil = 0;
	COF = NULL;
	TempTyre = NULL;
	line = 4;
	cout << "Tech Constuctor being called..\n";

}

#endif