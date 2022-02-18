//----------------------------------------
//--------    Author: AA
//--------    DateTime: 2022-02-18
//--------    Description: Singleton
//----------------------------------------

#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* getObject()
	{

	}
private:
	Singleton()
	{
		cout << "Singleton::Singleton()" << endl;
	}
	~Singleton();

	
};
	


int main(int argc, char const *argv[])
{
	
	return 0;
}