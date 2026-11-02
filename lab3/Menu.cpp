#include "Menu.h"
#include "WristWatch.h"
#include "DeskWatch.h"
#include "SmartWatch.h"
#include <iostream>

void showCatalog(Watch* catalog[], int size, int filterType)
{
	std::cout << "\nТЕКУЩИЙ КАТАЛОГ:" << std::endl;
	Watch::printHeader();                                               // шапка
	for (int i = 0; i < size; i++)
	{
		WristWatch* ww = dynamic_cast<WristWatch*>(catalog[i]);
		DeskWatch* dw = dynamic_cast<DeskWatch*>(catalog[i]);
		SmartWatch* sw = dynamic_cast<SmartWatch*>(catalog[i]);

		if (filterType == 1) // Вывод всего каталога
		{
			if (ww) std::cout << *ww << std::endl;
			else if (dw) std::cout << *dw << std::endl;
			else if (sw) std::cout << *sw << std::endl;
		}
		else if (filterType == 2 && ww) // Только наручные
		{
			std::cout << *ww << std::endl;
		}
		else if (filterType == 3 && dw) // Только настольные
		{
			std::cout << *dw << std::endl;
		}
		else if (filterType == 4 && sw) // Только умные
		{
			std::cout << *sw << std::endl;
		}
	}
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
			std::cin.ignore();

			if (type == 1)
			{
				std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Влагозащиту(1/0): ";
				catalog[i] = new WristWatch();
				std::cin >> *catalog[i];
			}
			else if (type == 2)
			{
				std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Будильник(1/0): ";
				catalog[i] = new DeskWatch();
				std::cin >> *catalog[i];
			}
			else
			{
				std::cout << "Введите через пробел: Бренд Цену Заряд(мес) Пульсометр(1/0): ";
				catalog[i] = new SmartWatch();
				std::cin >> *catalog[i];
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
	std::cin.ignore();

	if (type == 1)
	{
		catalog[size] = new WristWatch();
		std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Влагозащиту(1/0): ";
		std::cin >> *(dynamic_cast<WristWatch*>(catalog[size]));
	}
	else if (type == 2)
	{
		catalog[size] = new DeskWatch();
		std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Будильник(1/0): ";
		std::cin >> *(dynamic_cast<DeskWatch*>(catalog[size]));
	}
	else
	{
		catalog[size] = new SmartWatch();
		std::cout << "Введите через пробел: Бренд Цену Заряд(мес) Пульсометр(1/0): ";
		std::cin >> *(dynamic_cast<SmartWatch*>(catalog[size]));
	}

	size++;
	std::cout << "Часы успешно добавлены! Теперь в каталоге: " << size << " шт." << std::endl;
}