#pragma once
#include "Watch.h"
class MechanicalWatch : public Watch
{
protected:
	int accuracy;                                                       // точность (сек/сут)

public:
	MechanicalWatch();
	MechanicalWatch(const char* brand, float price, int accuracy);
	virtual ~MechanicalWatch();

	int getAccuracy() const;
	void setAccuracy(int newAccuracy);

	friend std::ostream& operator<<(std::ostream& os, const MechanicalWatch& w);
	friend std::istream& operator>>(std::istream& is, MechanicalWatch& w);

	void printRow() const override;
};

