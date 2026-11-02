#include <iostream>
#include <iomanip>
#include <string>
#include "DeskWatch.h"

// КЛАСС DeskWatch
DeskWatch::DeskWatch() : MechanicalWatch()
{
	std::cout << "Конструктор - DeskWatch" << std::endl;
	this->hasAlarm = false;
}

DeskWatch::DeskWatch(const char* brand, float price, int accuracy, bool hasAlarm)
	: MechanicalWatch(brand, price, accuracy)
{
	std::cout << "Конструктор - DeskWatch" << std::endl;
	this->hasAlarm = hasAlarm;
}

DeskWatch::~DeskWatch() 
{
	std::cout << "Деструктор - DeskWatch" << std::endl;
}

bool DeskWatch::getAlarm() const
{
	return this->hasAlarm;
}
void DeskWatch::setAlarm(bool alarm)
{
	this->hasAlarm = alarm;
}

//void DeskWatch::printRow() const
//{
//	MechanicalWatch::printRow();
//	std::string spec = "Точность: " + std::to_string(accuracy) + " с/д, " + (hasAlarm ? "С будильником" : "Без будильника");
//	std::cout << std::setw(43) << spec << std::endl;
//}

void DeskWatch::inputParams()
{
	int acc, alarm;
	std::cout << "Точность (сек/сут): "; std::cin >> acc; 
	setAccuracy(acc);
	std::cout << "Будильник (1-да, 0-нет): "; std::cin >> alarm; 
	hasAlarm = (alarm == 1);
}

std::ostream& operator<<(std::ostream& os, const DeskWatch& w)
{
	os << static_cast<const MechanicalWatch&>(w)
		<< "Точность: " << w.accuracy << " с/д, " << (w.hasAlarm ? "С будильником" : "Без будильника");
	return os;
}

std::istream& operator>>(std::istream& is, DeskWatch& w)
{
	is >> static_cast<MechanicalWatch&>(w);                             // вводим бренд, цену и точность
	int alarm;
	is >> alarm;
	w.hasAlarm = (alarm == 1);
	return is;
}