#ifndef __Recycling__
#define __Recycling__

#include "rt.h"
#include "Tyer.h"
//#include "Receptionist.h"


class Recycling {
private:
	int UsedTyreStorage;
	Tyre* CTyre[10];
public:
	//class Recep* theRecep;
	Recycling();



	void RecevTyre( Tyre* ATyre) {
		assert(UsedTyreStorage >= 0 && UsedTyreStorage <= 10);
		UsedTyreStorage++;
		CTyre[UsedTyreStorage-1] = ATyre;
		printf("Recycling: Used Tyre received.\n");
	}
	Tyre* ShowTyre(int x) {
		return CTyre[x];
	}



};


Recycling::Recycling() {
	UsedTyreStorage = 0;
	cout << "Recycling Constuctor being called..\n";
}

#endif