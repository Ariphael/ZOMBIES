#pragma once
#include <chrono>
class Time
{
public:
	Time();
	float Get();
	void Point();
	~Time();
private:
	std::chrono::steady_clock::time_point exit;
	std::chrono::steady_clock::time_point _ELAPSED;
};

