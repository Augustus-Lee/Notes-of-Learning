#include <iostream>

using namespace std;

enum CarType
{
	Benz,
	BMW,
	Adui
};


class Car
{
public:
	virtual void createCar(void) = 0;

	
};

class BenzCar : public Car
{
public:
	BenzCar()
	{
		cout << "BenzCar::BenzCar()..." << endl;
	}
	virtual void createCar(void)
	{
		cout << "BenzCar::createCar()!" << endl;
	}
};


class AudiCar : public Car
{
public:
	AudiCar()
	{
		cout << "AudiCar::AudiCar()..." << endl;
	}
	virtual void createCar(void)
	{
		cout << "AudiCar::createCar()!" << endl;
	}
};


class Factory
{
public:
	virtual Car* createConcreteCar(void) = 0;

	virtual ~Factory()
	{
		cout << "~Factory()" << endl;
	}

};

class BenzFactory : public Factory
{
public:

	virtual Car* createConcreteCar(void)
	{
		return new BenzCar();
	}
	 ~BenzFactory()
	{
		cout << "~BenzFactory()" << endl;
	}

};


class AudiFactory : public Factory
{
public:

	virtual Car* createConcreteCar(void)
	{
		return new AudiCar();
	}

	~AudiFactory()
	{
		cout << "~AudiFactory()" << endl;
	}


};

int main(int argc, char const *argv[])
{
	Factory* fac = new BenzFactory();
	Car* car1 = fac->createConcreteCar();

	fac = new AudiFactory();
	Car* car2 = fac->createConcreteCar();

	delete fac; delete car1; delete car2;


	return 0;
}