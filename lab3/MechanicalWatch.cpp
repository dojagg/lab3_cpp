#include "MechanicalWatch.h"
#include <iostream>
#include <iomanip>
#include <string>

// КЛАСС MechanicalWatch
MechanicalWatch::MechanicalWatch() : Watch()                            // конструктор 
{
	std::cout << "Конструктор - MechanicalWatch" << std::endl;
	this->accuracy = 0;
}

MechanicalWatch::MechanicalWatch(const char* brand, float price, int accuracy)
	: Watch(brand, price)
{
	std::cout << "Конструктор - MechanicalWatch" << std::endl;
	this->accuracy = accuracy;
}

MechanicalWatch::~MechanicalWatch() 
{
	std::cout << "Деструктор - MechanicalWatch" << std::endl;
}

int MechanicalWatch::getAccuracy() const                                 // геттер точности
{
	return this->accuracy;
}
void MechanicalWatch::setAccuracy(int newAccuracy)                       // сеттер точности
{
	this->accuracy = newAccuracy;
}

std::ostream& operator<<(std::ostream& os, const MechanicalWatch& w)
{
	os << static_cast<const Watch&>(w) << ", Точность: " << w.accuracy << " с/д";
	return os;
}

std::istream& operator>>(std::istream& is, MechanicalWatch& w)
{
	is >> static_cast<Watch&>(w);                                       
	std::cout << "Точность хода (сек/сут): ";
	is >> w.accuracy;
	return is;
}

void MechanicalWatch::printRow() const
{
	Watch::printRow();                                                 
	std::cout << "| " << std::left << std::setw(16) << "Механические"; 
}