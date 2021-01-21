#pragma once

#include "fromDecimal.h"

class fromOctal : public fromDecimal
{
public:
	std::string conversion(int, int);

private:
	int toDec(int);

};