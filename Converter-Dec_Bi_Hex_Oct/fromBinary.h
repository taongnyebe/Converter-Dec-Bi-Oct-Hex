#pragma once

#include "fromDecimal.h"

class fromBinary : public fromDecimal
{
public:
	std::string conversion(int, int);

private:
	int toDec(int);

};