//----------------------------------------
//--------    Author: AA
//--------    DateTime: 2022-02-18
//--------    Description: AbstractFactory
//----------------------------------------


#include<iostream>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "Car::Car()" << endl;
	}
	virtual ~Car()
	{
		cout << "Car::~Car()" << endl;
	}
	virtual void createCar(void) = 0;
	
};

class Audi : public Car
{
public:
	Audi()
	{
		cout << "Audi::Audi()" << endl;
	}
	virtual void createCar(void)
	{
		cout << "Audi::createCar()" << endl;
	}

	~Audi()
	{
		cout << "Audi::~Audi()" << endl;
	}
	
};

class PremiumCar
{
public:
	
	virtual ~PremiumCar(){ }
	virtual void createPremiumCar(void) = 0;

};

class HighAudi : public PremiumCar
{
public:
	HighAudi()
	{
		cout << "HighAudi::HighAudi()" << endl;
	}
	virtual void createPremiumCar(void)
	{
		cout << "HighAudi::createPremiumCar()" << endl;
	}
	~HighAudi(){ }	
	

};

class AbstractFactory
{
public:
	virtual Car* createSpecificCar(void) = 0;
	virtual PremiumCar* createSpecificPreCar(void) = 0;
	virtual ~AbstractFactory(){ }
	
};

//concrete factory
class AudiFac : public AbstractFactory
{
public:
	AudiFac()
	{
		cout << "AudiFac::AudiFac()" << endl;
	}
	virtual Car* createSpecificCar(void)
	{
		return new Audi();
	}

	virtual PremiumCar* createSpecificPreCar(void)
	{
		return new HighAudi();
	}
	
	
};


int main(int argc, char const *argv[])
{
	AbstractFactory *fac = new AudiFac();
	Car *car1 = fac->createSpecificCar();
	PremiumCar *car2 = fac->createSpecificPreCar();

	delete fac; delete car1; delete car2;

	return 0;
}