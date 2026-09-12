#include <iostream>

class Transport 
{

private:

	std::string name;
	float speed;
	unsigned short enginecapacity;
	unsigned short wheels;
	unsigned short seats;

public:

	Transport(std::string name, float speed, unsigned short enginecapacity, unsigned short wheels, unsigned short seats) : name(name), speed(speed), enginecapacity(enginecapacity), wheels(wheels), seats(seats) 
	{



	}
	~Transport() {}

};

class Car 
{



};

class Motorcycle 
{



};

class OtherTransport
{



};


class Car : public Transport
{



};

class Motorcycle : public Transport
{



};

class OtherTransport : public Transport
{



};

int main()
{
	
	std::cout << "Nasledovanie!!" << std::endl;
	return 0;

}