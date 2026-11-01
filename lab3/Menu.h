#pragma once
#include "Watch.h"

void fillCatalog(Watch* catalog[], int& size, int mode);                // заполнить каталог
void showCatalog(Watch* catalog[], int size, int filterType);           // вывести каталог
void editWatchPrice(Watch* catalog[], int size);                        // изменить цену
void addWatch(Watch* catalog[], int& size);                             // добавление часов в массив