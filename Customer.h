#ifndef __Customer__
#define __Customer__

#include "rt.h"
#include "Receptionist.h"
#include "Car.h"


class Customer {
private:
	Car* Cuscar;
	int money;

public:
	class Recep* theRecep; 					


	void AddRecep(Recep* aRecep) 		
	{
		theRecep = aRecep;			
		theRecep->theCustomer = this; 		 	
	}	

	Car* sendCar(void) {
		return Cuscar;
	}
	
	void getCar(Car* car) {
		Cuscar = car;
	}


	void payment(void) {
		printf("Payment is Done\n");
	}
	Customer();
	

	int ShowOil(void) {
		return Cuscar->ShowOil();
	}
	int ShowAirFilter(void) {
		return Cuscar->ShowAirFilter();
	}
	int ShowOilFilter(void) {
		return Cuscar->ShowOilFilter();
	}	
	void initializetyre(int x, int y) {
		Cuscar->initializetyre(x, y);
	}
	void initializeOF(int x) {
		Cuscar->initializeOF(x);
	}
	void Showty(void ) {
		for (int i = 0; i < 4; i++) {
			printf("tyre %d used percentage is %d\n", i, Cuscar->ShowTyre(i));
		}
	}
	int Showmoney(void) {
		printf("The remaining money is: %d\n", money);
		return money;
	}

	void Pay(int x) {
		money -= x;
		assert(money >= 0);
	}
};


Customer::Customer() {
	Cuscar = new Car;
	money = 500;
	cout << "Customer Constuctor being called..\n";

}

#endif