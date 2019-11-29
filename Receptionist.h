#ifndef __Recep__
#define __Recep__

#include "rt.h"
#include "Technician.h"
#include "Car.h"
#define AF 1
#define OI 2
#define OF 3
#define TY 4

class Customer;

class Recep {
private:
	Car* RecepCar;
	int TotalPayment;
public:
	 class Customer* theCustomer; 							
	 class Tech* theTech;

	 void AddTech(Tech* aTech)
	 {
		 theTech = aTech;
		 theTech->theRecep = this;
	 }	

	 void getCar(Car* car) {
		 RecepCar = car;
	 }

	 Car* sendCar(void) {
		 return RecepCar;
	 }

	 int ShowInvoice(void) {
		return RecepCar->showInvoice();
	 }

	 void ShowSR(void) {
		  RecepCar->showSR();
	 }

	 void Generateinvoice(int x) {
		 RecepCar->updateinvoice(x);
	 }
	 void StampServiceRecord(void) {
		 RecepCar->updateSR();
	 }

	 int SendPayment(void) {
		 for (int i = 1; i < 5; i++) {
			
			 if (i == AF) {
				TotalPayment  = TotalPayment + 10*RecepCar->ShowJS(i);
				printf("Air Filter has been changed. Cost is %d.\n", 10 * RecepCar->ShowJS(i));
			 }
			 if (i == OI) {
				 TotalPayment = TotalPayment + 20 * RecepCar->ShowJS(i);
				 printf("Oil has been changed. Cost is %d.\n", 20 * RecepCar->ShowJS(i));
			 }
			 if (i == OF) {
				 TotalPayment = TotalPayment + 30 * RecepCar->ShowJS(i);
				 printf("Oil Filter has been changed. Cost is %d.\n", 30 * RecepCar->ShowJS(i));
			 }
			 if (i == TY) {
				 TotalPayment = TotalPayment + 40 * RecepCar->ShowJS(i);
				 printf("Tyre has been changed. Cost is %d.\n", 40 * RecepCar->ShowJS(i));
			 }
		 }
		 printf("Total Payment is: %d\n", TotalPayment);
		 return TotalPayment;
	 }


	 Recep();
};

Recep::Recep() {
	TotalPayment = 0;
	cout << "Receptionist Constuctor being called..\n";
}


#endif