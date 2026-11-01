#include "Menu.h"
#include "WristWatch.h"
#include "DeskWatch.h"
#include "SmartWatch.h"
#include <iostream>

void showCatalog(Watch* catalog[], int size, int filterType)
{
	std::cout << "\nТЕКУЩИЙ КАТАЛОГ:" << std::endl;
	Watch::printHeader();                                               // вывод шапки
	for (int i = 0; i < size; i++)
	{
		bool match = false;
		if (filterType == 1)
			match = true;                                                 // все часы без фильтра
		else if (filterType == 2 && dynamic_cast<WristWatch*>(catalog[i]))
			match = true;                                                 // только наручные
		else if (filterType == 3 && dynamic_cast<DeskWatch*>(catalog[i])) 
			match = true;                                                 // только настольные
		else if (filterType == 4 && dynamic_cast<SmartWatch*>(catalog[i]))
			match = true;                                                 // только умные

		if (match)
			catalog[i]->printRow();                                     // вывод подходящей строки
	}
	std::cout << std::string(93, '-') << std::endl;                     
}

void fillCatalog(Watch* catalog[], int& size, int mode)
{
	if (mode == 1)
	{
		std::cout << "Введите кол-во часов -  ";
		std::cin >> size;

		for (int i = 0; i < size; i++)
		{
			int type;
			std::cout << "\nВыберите тип для часов #" << i + 1 << ":" << std::endl;
			std::cout << "1. Наручные" << std::endl;
			std::cout << "2. Настольные" << std::endl;
			std::cout << "3. Умные" << std::endl;
			std::cout << "Ваш выбор : ";
			std::cin >> type;

			if (type == 1) {
				WristWatch* w = new WristWatch();
				std::cin >> *w;                                         
				catalog[i] = w;
			}
			else if (type == 2) {
				DeskWatch* d = new DeskWatch();
				std::cin >> *d;                                         
				catalog[i] = d;
			}
			else {
				SmartWatch* s = new SmartWatch();
				std::cin >> *s;                                         
				catalog[i] = s;
			}

			std::cin >> *catalog[i];
			catalog[i]->inputParams();
		}
	}
	else
	{
		size = 5;                                                       // подготовленный вариант каталога из 5 штук
		catalog[0] = new WristWatch("Rolex", 8500.0f, 2, true);
		catalog[1] = new WristWatch("Casio", 120.0f, 15, true);
		catalog[2] = new DeskWatch("Hermle", 1450.0f, 5, true);
		catalog[3] = new SmartWatch("Apple", 499.0f, 1, true);
		catalog[4] = new SmartWatch("Xiaomi", 150.0f, 14, false);
	}
}

void editWatchPrice(Watch* catalog[], int size)
{
	showCatalog(catalog, size, 1);                                      

	int id;
	float newPrice;
	std::cout << "Введите номер часов по порядку (от 1 до " << size << "): ";
	std::cin >> id;

	if (id >= 1 && id <= size)
	{
		std::cout << "Введите новую цену для " << catalog[id - 1]->getBrand() << " (руб.): ";
		std::cin >> newPrice;

		catalog[id - 1]->setPrice(newPrice);
		std::cout << "Цена успешно обновлена! Новая цена: " << catalog[id - 1]->getPrice() << " руб." << std::endl;
	}
	else
	{
		std::cout << "Ошибка: неверный номер часов!" << std::endl;
	}
}

void addWatch(Watch* catalog[], int& size)
{
	int type;
	std::cout << "\n ДОБАВЛЕНИЕ НОВЫХ ЧАСОВ" << std::endl;
	std::cout << "Выберите тип: " << std::endl;
	std::cout << "1. Наручные" << std::endl;
	std::cout << "2. Настольные" << std::endl;
	std::cout << "3. Умные" << std::endl;
	std::cout << "Ваш выбор : ";
	std::cin >> type;

	if (type == 1) {
		WristWatch* w = new WristWatch();
		std::cin >> *w;
		catalog[size] = w;
	}
	else if (type == 2) {
		DeskWatch* d = new DeskWatch();
		std::cin >> *d;
		catalog[size] = d;
	}
	else {
		SmartWatch* s = new SmartWatch();
		std::cin >> *s;
		catalog[size] = s;
	}

	std::cin >> *catalog[size];
	catalog[size]->inputParams();

	size++; 
	std::cout << "Часы добавлены! Теперь в каталоге: " << size << " шт." << std::endl;
}