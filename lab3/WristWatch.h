#pragma once
#include "MechanicalWatch.h"
class WristWatch : public MechanicalWatch
{
private:
	bool isWaterproof;                                                  // водонепроницаемость

public:
	WristWatch();
	WristWatch(const char* brand, float price, int accuracy, bool isWaterproof);
	~WristWatch();

	bool getWaterproof() const;
	void setWaterproof(bool waterproof);

	friend std::ostream& operator<<(std::ostream& os, const WristWatch& w);
	friend std::istream& operator>>(std::istream& is, WristWatch& w);

	void inputParams() override;
};
