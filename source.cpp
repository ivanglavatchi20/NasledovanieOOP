#include <iostream>
#include <locale>



class Transport 
{

private:

	std::string name;
	float speed;
	unsigned short enginecapacity;
	unsigned short wheels;
	unsigned short seats;
	unsigned short weight;

public:

	Transport(std::string name, float speed, unsigned short enginecapacity, unsigned short wheels, unsigned short seats, unsigned short weight) : name(name), speed(speed), enginecapacity(enginecapacity), wheels(wheels), seats(seats), weight(weight)
	{
		std::cout << "Transport created: " << name << std::endl;
	}
	~Transport() {}
	
	void move(std::string name, float speed, unsigned short enginecapacity, unsigned short wheels, unsigned short seats, unsigned short weight)
	{
		std::cout << "Эта херня(" << name << ") с " << seats << " сидениями движется со скоростью " << speed << " км/ч. При объеме двигателя " << enginecapacity << " см³" << "весом " << weight << "кг" << " и количеством сидений " << seats << std::endl;
		std::cout << "Это чудо, как эта херня вообще поехала. Ведь утром она не заводилась/не ехала" << std::endl;
	}
	void moveElectric(std::string name, float speed, unsigned short wheels, unsigned short weight)
	{
		std::cout << "Эта херня(" << name << ") с " << seats << " сидениями движется со скоростью " << speed << " км/ч. Весом " << weight << "кг" << std::endl;
		std::cout << "Это чудо, как эта херня вообще поехала. Ведь утром она не заводилась/не ехала" << std::endl;
	}

};
class Car : public Transport
{
private:
	std::string name;
	float speed;
	unsigned short enginecapacity;
	unsigned short wheels;
	unsigned short seats;
	unsigned short weight;
public:
	Car(std::string name, float speed, unsigned short enginecapacity, unsigned short wheels, unsigned short seats, unsigned short weight) : Transport(name, speed, enginecapacity, wheels, seats, weight) {}

};

class Motorcycle : public Transport
{
private:
	std::string name;
	float speed;
	unsigned short enginecapacity;
	unsigned short wheels;
	unsigned short seats;
	unsigned short weight;
public:
	Motorcycle(std::string name, float speed, unsigned short enginecapacity, unsigned short wheels, unsigned short seats, unsigned short weight) : Transport(name, speed, enginecapacity, wheels, seats, weight) {}

	
};

class OtherTransport : public Transport
{
private:
	std::string name;
	float speed;
	unsigned short wheels;
	unsigned short weight;
public:
	OtherTransport(std::string name, float speed, unsigned short wheels, unsigned short weight) : Transport(name, speed, 0, wheels, 1, weight) {}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	Transport transport("Mustang", 120, 2000, 4, 5, 1500);
	Car car("Toyota_Yaris", 150, 2500, 4, 5, 1200);
	Motorcycle motorcycle("Yamaha", 250, 1000, 2, 2, 150);
	OtherTransport other("Bicycle", 30  , 2, 7);

	transport.move("Mustang", 120, 2000, 4, 5, 1500);
	car.move("Toyota_Yaris", 150, 2500, 4, 5, 1200);
	motorcycle.move("Yamaha", 250, 1000, 2, 2, 150);
	other.moveElectric("Bicycle", 30, 2, 7);

	return 0;
}