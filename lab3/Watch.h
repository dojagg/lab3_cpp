#pragma once
#include <iostream>
// Базовый класс
class Watch
{
protected:
	char* brand;                                                        // бренд часов
	float price;                                                        // цена часов

public:
	Watch();
	Watch(const char* brand, float price);
	Watch(const Watch& other);
	virtual ~Watch();                                                   

	float getPrice() const;
	const char* getBrand() const;
	void setPrice(float newPrice);
	void setBrand(const char* newBrand);

	static void printHeader();                                          // метод для шапки таблицы
	virtual void printRow() const;                                      // метод для строки таблицы
	virtual void inputParams();                                         // метод для ввода доп. полей

	friend std::ostream& operator<<(std::ostream& os, const Watch& w);  // перегрузка вывода
	friend std::istream& operator>>(std::istream& is, Watch& w);        // перегрузка ввода
};
