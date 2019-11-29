#ifndef __OilFilter__
#define __OilFilter__

#include "rt.h"
#include "Tyer.h"
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