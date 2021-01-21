#include <string>

#include "fromOctodecimal.h"

#define bar "\n\t________________________________________"

std::string fromOctal::conversion(int oct, int state) 
{
	std::string result("\n\tOctodecimal: 0o");
	result.append(std::to_string(oct));

	result.append(bar);

	//Converting to Decimal
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Decimal: ");
		result.append(std::to_string(toDec(oct)));
	}

	//Converting to Binary
	if (state == 0 || state == 2)
	{
		result.append("\n\t- Binary: 0b");
		result.append(this->toBin(toDec(oct)));
	}

	//Converting to Hex
	if (state == 0 || state == 3)
	{
		result.append("\n\t- Hexadecimal: 0x");
		result.append(this->toHex(toDec(oct)));
	}

	result.append(bar);

	return (std::move(result));
}

int fromOctal::toDec(int octal) {
	int decimalNumber = 0, i = 0, rem;
	while (octal != 0)
	{
		rem = octal % 10;
		octal /= 10;
		decimalNumber += rem * pow(8, i);
		++i;
	}
	return decimalNumber;
}