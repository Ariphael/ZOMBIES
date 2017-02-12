#include "time.h"
#include <chrono>


Time::Time()
{
}

float Time::Get()
{
	exit = std::chrono::steady_clock::now();
	std::chrono::duration<float> local = exit-_ELAPSED  ;
	return local.count();
}

void Time::Point()
{
	_ELAPSED = std::chrono::steady_clock::now();
}


Time::~Time()
{
}
