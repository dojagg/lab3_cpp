#pragma once
#include "MechanicalWatch.h"
class DeskWatch : public MechanicalWatch
{
private:
	bool hasAlarm;                                                      // наличие будильника

public:
	DeskWatch();
	DeskWatch(const char* brand, float price, int accuracy, bool hasAlarm);
	~DeskWatch();

	bool getAlarm() const;
	void setAlarm(bool alarm);

	friend std::ostream& operator<<(std::ostream& os, const DeskWatch& w);
	friend std::istream& operator>>(std::istream& is, DeskWatch& w);

	void inputParams() override;
};