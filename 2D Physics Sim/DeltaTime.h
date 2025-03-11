#pragma once
class DeltaTime
{
private:
	float times[2];
public:
	DeltaTime();
	~DeltaTime();
	float dT;
	void NewTime(float t);
};
