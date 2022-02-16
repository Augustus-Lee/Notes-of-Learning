#include <iostream>

using namespace std;


enum CarType
{
	Benz,
	BMW,
	Adui
};

//抽象产品角色  提供接口
class Car
{
public:
	virtual void createCar(void) = 0;

};


//具体实现类
class BenzCar: public Car
{
public:
	BenzCar()
	{
		cout << "BenzCar::BenzCar()!" << endl;
	}

	virtual void createCar(void)
	{
		cout << "BenzCar::createCar()" << endl;
	}
};


class BMWCar : public Car
{
public:
	BMWCar()
	{
		cout << "BMWCar::BMWCar()!" << endl;
	}

	virtual void createCar(void)
	{
		cout << "BMWCar::createCar()" << endl;
	}


};


class AudiCar : public Car
{
public:
	AudiCar()
	{
		cout << "AudiCar::AudiCar()!" << endl;
	}

	virtual void createCar(void)
	{
		cout << "AudiCar::createCar()" << endl;
	}


};

//工厂类
class Factory
{
public:
	Car* createSpecificCar(CarType type)
	{
		switch(type)
		{
			case Benz:
				return new BenzCar();
				break;
			case BMW:
				return new BMWCar();
				break;
			case Adui:
				return new AudiCar();
				break;
			defualt:
				return NULL;
				break;

		}
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */

	Factory fac;
	Car* carA = fac.createSpecificCar(Benz);
	Car* carB = fac.createSpecificCar(BMW);

	delete carA; delete carB;
	return 0;
}