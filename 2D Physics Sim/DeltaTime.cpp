#pragma once
#include <iostream>
#include "DeltaTime.h"

DeltaTime::DeltaTime() : times{0.016667f,0.016667f}, dT(0.016667f) {}

DeltaTime::~DeltaTime() {}

void DeltaTime::NewTime(float t)
{
	times[0] = times[1];
	times[1] = t;
	dT = (times[0] + times[1]) / 2.0f;
}