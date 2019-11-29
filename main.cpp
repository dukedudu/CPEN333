//#include "../Receptionist.h"
#include "../rt.h"
#include "../Customer.h"


int main(void) {
	cout << "-----------------------------------------------Calling Constructors------------------------------------------------------\n";
		Customer Peter; 		// create an instance of a student called Fred
		Recep    Duke; 		// create an instance of a course
		Tech	Frank;
		cout << "\n--------------------------------------------Test case start------------------------------------------------------\n";
		Peter.initializetyre(1, 100);
		Peter.initializetyre(2, 0);
		Peter.initializetyre(3, 100);
		Peter.initializetyre(4, 0);
		Peter.initializeOF(100);
		printf("Customer's Car condition: \nRemaining perscentage of Oil: %d old, \nRemaining perscentage of Air Filter: %d old.\nUsed perscentage of Oil Filter: %d old. \n", Peter.ShowOil(), Peter.ShowAirFilter(), Peter.ShowOilFilter());
		Peter.Showty();
		cout << "\nConnecting a receptionist...\n";
		Peter.AddRecep(&Duke);
		cout << "\nConnecting a technician..\n";
		Duke.AddTech(&Frank);
		cout << "Customer sends the car to the receptionist..\n";
		Duke.getCar(Peter.sendCar());
		cout << "Receptionist assigns the car to the technician...\n";
		Frank.getCar(Duke.sendCar());
		cout << "\nTechnician starts to check the car\n";
		Frank.ServiceCar();
		cout << "\nInception complete, Technician returns the car to the receptionist..\n";
		Duke.getCar(Frank.sendCar());
		cout << "\nReceptionist generate invoice and update service record..\n";
		Duke.Generateinvoice(4);
		Duke.ShowSR();
		Duke.StampServiceRecord();
		cout << "\nCalculate the total cost for this maintainance..\n";
		Peter.Pay(Duke.SendPayment());
		cout << "\nCustomer pays expense..\n";
		Peter.Showmoney();
		cout << "\nReceptionist returns the car..\n";
		Peter.getCar(Duke.sendCar());
		cout << "\nCustomer's car information after maintainance..\n";
		printf("Now Car: \nRemaining Oil: %d \nRemaining AirFilter: %d \nUsed OilFilter: %d\n", Peter.ShowOil(), Peter.ShowAirFilter(), Peter.ShowOilFilter());
		Peter.Showty();
		cout << "\n--------------------------------------------Test case end------------------------------------------------------\n";
	//////////////////////////////////// Unit Test
		//	Frank.updateindex(5);
		//Frank.ServiceCar();
		

	return 0;
};