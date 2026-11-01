#include "Watch.h"
#include <iostream>
#include <iomanip>
#include <string>

// КЛАСС Watch
Watch::Watch()                                                          // конструктор
{
	std::cout << "Конструктор - Watch" << std::endl;
	this->price = 0;
	this->brand = new char[1];                                         
	this->brand[0] = '\0';
}

Watch::Watch(const Watch& other)                                        // конструктор копирования
{
	std::cout << "Конструктор - Watch" << std::endl;
	this->price = other.price;

	size_t len = strlen(other.brand);
	this->brand = new char[len + 1];                                    
	std::copy(other.brand, other.brand + len + 1, this->brand);
}

Watch::Watch(const char* brand, float price)                            // конструктор с параметрами
{
	std::cout << "Конструктор - Watch" << std::endl;
	this->price = price;

	size_t len = strlen(brand);
	this->brand = new char[len + 1];
	std::copy(brand, brand + len + 1, this->brand);
}

Watch::~Watch()                                                         // деструктор базового класса
{
	std::cout << "Деструктор - Watch" << std::endl;
	delete[] this->brand;                                               
	this->brand = nullptr;
}

float Watch::getPrice() const                                           // геттер цены
{
	return this->price;
}

const char* Watch::getBrand() const                                     // геттер бренда
{
	return this->brand;
}

void Watch::setPrice(float newPrice)                                    // сеттер цены 
{
	if (newPrice >= 0)
		this->price = newPrice;
}

void Watch::setBrand(const char* newBrand)                              // сеттер бренда 
{
	delete[] this->brand;                                               

	size_t len = strlen(newBrand);
	this->brand = new char[len + 1];
	std::copy(newBrand, newBrand + len + 1, this->brand);
}

void Watch::printHeader()                                               // метод отрисовки шапки таблицы
{
	std::cout << std::string(93	, '-') << std::endl;
	std::cout << std::left
		<< std::setw(16) << "| Бренд"
		<< std::setw(13) << "| Цена (руб.)"
		<< std::setw(18) << "| Тип механизма"
		<< std::setw(45) << "| Доп. характеристики" << "|" << std::endl;
	std::cout << std::string(93, '-') << std::endl;
}

void Watch::printRow() const                                            // метод вывода полей базового класса
{
	std::cout << std::left << "| "
		<< std::setw(14) << this->brand
		<< "| " << std::setw(11) << this->price;
}

void Watch::inputParams() {}                                           

std::ostream& operator<<(std::ostream& os, const Watch& w)              // функция перегрузка вывода
{
	os << "Бренд: " << w.brand << ", Цена: " << w.price << " руб.";
	return os;
}

std::istream& operator>>(std::istream& is, Watch& w)                    // функция перегрузка ввода
{
	char buffer[256];
	std::cout << "Введите бренд: ";
	is >> buffer;
	w.setBrand(buffer);                                                 

	std::cout << "Введите цену: ";
	is >> w.price;
	return is;
}











