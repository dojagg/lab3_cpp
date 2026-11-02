#pragma once
#include "ElectronicWatch.h"
class SmartWatch : public ElectronicWatch
{
private:
	bool hasHeartRate;                                                  // наличие пульсометра

public:
	SmartWatch();
	SmartWatch(const char* brand, float price, int batteryLife, bool hasHeartRate);
	~SmartWatch();

	bool getHeartRate() const;
	void setHeartRate(bool heartRate);

	friend std::ostream& operator<<(std::ostream& os, const SmartWatch& w);
	friend std::istream& operator>>(std::istream& is, SmartWatch& w);

	void inputParams() override;
};