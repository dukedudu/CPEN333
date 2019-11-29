#ifndef __JobSheet__
#define __JobSheet__

#include "rt.h"
//#include "Receptionist.h"
#include "Assert.h"
#define AF 1
#define OI 2
#define OF 3
#define TY 4

class JobSheet {
private:
	int AirFilter;
	int Oil;
	int NumCOF;
	int NumTyre;
	int labourhour;
public:
	//class Recep* theRecep;
	JobSheet();

	void AddItem(int x) {
		if (x == AF) {
			AirFilter++;
		}
		if (x == OI) {
			Oil++;
		}
		if (x == OF) {
			NumCOF++;
		}
		if (x == TY) {
			NumTyre++;
		}
	}

	void AddLabourItem(int x) {
		if (x == AF) {
			labourhour++;
		}
		if (x == OI) {
			labourhour++;
		}
		if (x == OF) {
			labourhour++;
		}
		if (x == TY) {
			labourhour++;
		}
	}

	int ShowJS(int x) {
		if (x == AF) {
			return AirFilter;
		}
		if (x == OI) {
			return Oil;
		}
		if (x == OF) {
			return NumCOF;
		}
		if (x == TY) {
			return NumTyre;
		}
	}
};


JobSheet::JobSheet() {
	AirFilter = 0;
	Oil = 0;
	NumCOF = 0; 
	NumTyre = 0; 
	labourhour = 0;
	cout << "Job Sheet Constuctor being called..\n";
}


class ServiceRecord : public JobSheet {

private:
	int qualified;

public:
	void StampSR(void) {
		qualified = 1;
	}
	int ShowSR(void) {
		return qualified;
	}
	ServiceRecord();

};

ServiceRecord::ServiceRecord() {
	qualified = 0;
	cout << "Service Record Constuctor being called..\n";
}

#endif