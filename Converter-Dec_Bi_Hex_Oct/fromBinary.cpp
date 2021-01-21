#include <string>

#include "fromBinary.h"

#define bar "\n\t________________________________________"

std::string fromBinary::conversion(int bin, int state)
{
	std::string result("\n\tBinary: 0b");
	result.append(std::to_string(bin));

	result.append(bar);

	//Converting to Decimal
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Decimal: ");
		result.append(std::to_string(toDec(bin)));
	}

	//Converting to Octal
	if (state == 0 || state == 2)
	{
		result.append("\n\t- Octodecimal: 0o");
		result.append(this->toOctal(toDec(bin)));
	}

	//Converting to Hex
	if (state == 0 || state == 3)
	{
		result.append("\n\t- Hexadecimal: 0x");
		result.append(this->toHex(toDec(bin)));
	}

	result.append(bar);
	
	return (std::move(result));
}

int fromBinary::toDec(int bin)
{
	int decimalNumber = 0, i = 0, remainder;
	while (bin != 0)
	{
		remainder = bin % 10;
		bin /= 10;
		decimalNumber += (double)remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}