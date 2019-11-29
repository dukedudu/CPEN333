#ifndef __Car__
#define __Car__

#include "rt.h"
#include "Tyer.h" //parts.h
#include "Job Sheet.h"
class Car
{
	/*
	Engine* MyEngine;			           
	Gearbox* MyGearbox;	
		Engine* GetEngine() { return MyEngine; }	            
	void      AddEngine(Engine* theNewEngine) {	            
		MyEngine = theNewEngine;	             
	}
	Engine* ExchangeEngine(Engine* theNewEngine) {        
		Engine* temp = MyEngine;	            
		MyEngine = theNewEngine;	           
		return temp;		            
	}		
	*/
private:
	//int Jobsheet;
	int Invoice;
	ServiceRecord* SR;
	int AirFilter;
	int Oil;
	OilFilter* COF;
	Tyre*	CTyre[4];
	JobSheet* JS;
public:
	Car();

	void updateinvoice( int x ) {
		Invoice = x;
	}
	void updateSR(void) {
		SR->StampSR();
	}

	int showInvoice(void) {
		return Invoice;
	}

	void showSR(void) {
		if (JS->ShowJS(AF)) {
			printf("Air Filter has been Added to Service Record.\n");
		}
		if (JS->ShowJS(OF)) {
			printf("Oil Filter has been Added to Service Record.\n");
		}
		if (JS->ShowJS(OI)) {
			printf("Oil has been Added to Service Record.\n");
		}
		if (JS->ShowJS(TY)) {
			printf("Tyre has been Added to Service Record.\n");
		}
	}



	int ShowOil(void) {
		return Oil;
	}
	int ShowAirFilter(void) {
		return AirFilter;
	}
	int ShowOilFilter(void) {
		return COF->ShowUsedPercent();
	}
	int ShowTyre(int x) {
		return CTyre[x]->ShowUsedPercent();
	}


	void recevOil(int x) {
		Oil = x;
	}

	void recevOilFilter(OilFilter* x) {
		COF = x;
	}

	void recevAirFilter(int x) {
		AirFilter = x;
	}
	

	void recevTyre(int x, Tyre* aTyre) {
		CTyre[x] = aTyre;
	}

	Tyre* GiveTyre(int x) {
		return CTyre[x];
	}
	int GiveOil(void) {
		return Oil;
	}
	OilFilter* GiveOilFilter(void) {
		return COF;
	}
	int GiveAirFilter(void) {
		return AirFilter;
	}

	void initializetyre(int x, int y) {
		CTyre[x-1]->updateUsedPercent(y);
	}
	void initializeOF(int x) {
		COF->updateUsedPercent(x);
	}

	void AddItem(int x) {
		JS->AddItem(x);
		JS->AddLabourItem(x);
	}

	int ShowJS(int x) {
		return JS->ShowJS(x);
	}

};

Car::Car() {
	//Jobsheet = 2;
	AirFilter =0;
	Oil = 0;
	COF = new OilFilter();
	CTyre[0] = new Tyre();
	CTyre[1] = new Tyre();
	CTyre[2] = new Tyre();
	CTyre[3] = new Tyre();
	JS = new JobSheet();
	SR = new ServiceRecord();
	cout << "Car Constuctor being called..\n";

}

#endif