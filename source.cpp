#include <iostream>
#include <locale>
#include <string>

class Transport
{
protected:
    std::string name;
    float speed;
    unsigned short enginecapacity;
    unsigned short wheels;
    unsigned short seats;
    unsigned short weight;

public:
    Transport(std::string name, float speed, unsigned short enginecapacity,
        unsigned short wheels, unsigned short seats, unsigned short weight)
        : name(name), speed(speed), enginecapacity(enginecapacity),
        wheels(wheels), seats(seats), weight(weight)
    {
        std::cout << "Transport created: " << name << std::endl;
    }

    virtual ~Transport() {}

    virtual void move() const
    {
        std::cout << "Транспорт (" << name << ") с " << seats
            << " сидениями движется со скоростью " << speed << " км/ч. "
            << "Объем двигателя " << enginecapacity << " см3, вес "
            << weight << " кг, сидений: " << seats << std::endl;
    }
};

class Car : public Transport
{
public:
    Car(std::string name, float speed, unsigned short enginecapacity,
        unsigned short wheels, unsigned short seats, unsigned short weight)
        : Transport(name, speed, enginecapacity, wheels, seats, weight) {
    }

};

class Motorcycle : public Transport
{
public:
    Motorcycle(std::string name, float speed, unsigned short enginecapacity,
        unsigned short wheels, unsigned short seats, unsigned short weight)
        : Transport(name, speed, enginecapacity, wheels, seats, weight) {
    }

    void move() const override
    {
        std::cout << "Мотоцикл (" << name << ") мчится со скоростью "
            << speed << " км/ч, объем двигателя " << enginecapacity
            << " см3, вес " << weight << " кг" << std::endl;
    }
};

class OtherTransport : public Transport
{
public:
    OtherTransport(std::string name, float speed, unsigned short wheels, unsigned short weight)
        : Transport(name, speed, 0, wheels, 1, weight) {
    }

    void move() const override
    {
        std::cout << "Транспорт (" << name << ") без двигателя едет со скоростью "
            << speed << " км/ч, вес " << weight << " кг" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Transport transport("Mustang", 120, 2000, 4, 5, 1500);
    Car car("Toyota_Yaris", 150, 2500, 4, 5, 1200);
    Motorcycle motorcycle("Yamaha", 250, 1000, 2, 2, 150);
    OtherTransport other("Bicycle", 30, 2, 7);


    transport.move();
    car.move();
    motorcycle.move();
    other.move();

    std::cout << "\n--- Полиморфный вызов через указатели на Transport ---\n";
    Transport* fleet[] = { &transport, &car, &motorcycle, &other };
    for (Transport* t : fleet)
    {
        t->move();
    }

    return 0;
}
