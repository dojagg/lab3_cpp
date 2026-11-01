#include <iostream>
#include <iomanip>
#include <string>
#include "WristWatch.h"

// КЛАСС WristWatch
WristWatch::WristWatch() : MechanicalWatch()                            // конструктор
{
	std::cout << "Конструктор - WristWatch" << std::endl;
	this->isWaterproof = false;
}

WristWatch::WristWatch(const char* brand, float price, int accuracy, bool isWaterproof)
	: MechanicalWatch(brand, price, accuracy)
{
	std::cout << "Конструктор - WristWatch" << std::endl;
	this->isWaterproof = isWaterproof;

}

WristWatch::~WristWatch() 
{
	std::cout << "Деструктор - WristWatch" << std::endl;
}

bool WristWatch::getWaterproof() const
{
	return this->isWaterproof;
}

void WristWatch::setWaterproof(bool waterproof)
{
	this->isWaterproof = waterproof;
}

void WristWatch::printRow() const                                       
{
	MechanicalWatch::printRow();                                        
	std::string spec = "Точность: " + std::to_string(accuracy) + " с/д, " + (isWaterproof ? "Влагозащита" : "Боится воды");
	std::cout << "| " << std::left << std::setw(43) << spec << "|" << std::endl;
}

void WristWatch::inputParams()                                          // ввод специфичных параметров
{
	int acc, water;
	std::cout << "Точность (сек/сут): "; std::cin >> acc; setAccuracy(acc);
	std::cout << "Влагозащита (1-да, 0-нет): "; std::cin >> water; isWaterproof = (water == 1);
}

std::ostream& operator<<(std::ostream& os, const WristWatch& w)
{
	os << static_cast<const MechanicalWatch&>(w)
		<< ", " << (w.isWaterproof ? "Влагозащита" : "Боится воды");
	return os;
}

std::istream& operator>>(std::istream& is, WristWatch& w)
{
	is >> static_cast<MechanicalWatch&>(w);                             // вводим бренд, цену и точность
	std::cout << "Влагозащита (1-да, 0-нет): ";
	int water;
	is >> water;
	w.isWaterproof = (water == 1);
	return is;
}
