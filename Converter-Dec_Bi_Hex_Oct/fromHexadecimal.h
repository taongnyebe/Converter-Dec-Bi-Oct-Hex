#pragma once

#include "fromDecimal.h"

class fromHexadecimal : public fromDecimal
{
public:
	std::string conversion(std::string, int);

private:
	int toDec(std::string);

};