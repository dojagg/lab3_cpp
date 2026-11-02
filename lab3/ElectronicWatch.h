#pragma once
#include "Watch.h"
class ElectronicWatch : public Watch
{
protected:
	int batteryLife;                                                    // срок службы батареи (мес€цев)

public:
	ElectronicWatch();
	ElectronicWatch(const char* brand, float price, int batteryLife);
	virtual ~ElectronicWatch();

	int getBatteryLife() const;
	void setBatteryLife(int newBatteryLife);

	friend std::ostream& operator<<(std::ostream& os, const ElectronicWatch& w);
	friend std::istream& operator>>(std::istream& is, ElectronicWatch& w);

};