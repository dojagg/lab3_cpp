#include <iostream>
#include <locale.h>
#include "Menu.h"
#define MAX_SIZE 20

int main()
{
	setlocale(LC_ALL, "Russian");
	char restartChoice;

	do
	{
		int N = 0;                                                      
		Watch* catalog[MAX_SIZE];                                       // массив на 20 элементов

		int fillMode;
		std::cout << "\nРЕЖИМ ЗАПОЛНЕНИЯ (1 - Вручную, 2 - Подготовленный вариант): ";
		std::cin >> fillMode;
		fillCatalog(catalog, N, fillMode);                              // заполняем каталог

		int menuChoice;
		do
		{
			std::cout << "\n МЕНЮ ВЫБОРА" << std::endl;
			std::cout << "1. Все часы" << std::endl;
			std::cout << "2. Наручные часы" << std::endl;
			std::cout << "3. Настольные часы" << std::endl;
			std::cout << "4. Умные часы" << std::endl;
			std::cout << "5. Изменить цену" << std::endl;
			std::cout << "6. Добавить новые часы" << std::endl;
			std::cout << "7. Выход" << std::endl;
			std::cout << "Действие: ";
			std::cin >> menuChoice;
			std::cin.ignore();

			if (menuChoice >= 1 && menuChoice <= 4)
				showCatalog(catalog, N, menuChoice);                    
			
			else if (menuChoice == 5)
				editWatchPrice(catalog, N);                             // изменение цены

			else if (menuChoice == 6)
				addWatch(catalog, N);                                   // добавление новых часов

		} while (menuChoice != 7);                                      

		for (int i = 0; i < N; i++)
			delete catalog[i];                                          // удаляем созданные объекты

		std::cout << "\nПовторить запуск программы? (y/n): ";
		std::cin >> restartChoice;

	} while (restartChoice == 'y' || restartChoice == 'Y');

	return 0;

}

