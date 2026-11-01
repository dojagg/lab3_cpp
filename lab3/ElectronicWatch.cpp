#include <iostream>
#include <iomanip>
#include <string>
#include "ElectronicWatch.h"

// КЛАСС  ElectronicWatch
ElectronicWatch::ElectronicWatch() : Watch()                            // конструктор
{
	std::cout << "Конструктор - ElectronicWatch" << std::endl;
	this->batteryLife = 0;
}

ElectronicWatch::ElectronicWatch(const char* brand, float price, int batteryLife)
	: Watch(brand, price)
{
	std::cout << "Конструктор - ElectronicWatch" << std::endl;
	this->batteryLife = batteryLife;
}

ElectronicWatch::~ElectronicWatch()                                         // деструктор 
{
	std::cout << "Деструктор - ElectronicWatch" << std::endl;
}                                     

int ElectronicWatch::getBatteryLife() const                                 // геттер времени работы
{
	return this->batteryLife;
}

void ElectronicWatch::setBatteryLife(int newBatteryLife)                  // сеттер с проверкой
{
	if (newBatteryLife > 0)
		this->batteryLife = newBatteryLife;
}

void ElectronicWatch::printRow() const                                  
{
	Watch::printRow();
	std::cout << "| " << std::left << std::setw(16) << "Электронные";
}

std::ostream& operator<<(std::ostream& os, const ElectronicWatch& w)
{
	os << static_cast<const Watch&>(w) << ", Срок батареи: " << w.batteryLife << " мес.";
	return os;
}

std::istream& operator>>(std::istream& is, ElectronicWatch& w)
{
	is >> static_cast<Watch&>(w);                                       
	std::cout << "Срок службы батареи (мес): ";
	is >> w.batteryLife;
	return is;
}