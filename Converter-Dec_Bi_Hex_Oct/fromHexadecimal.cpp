#include <string>

#include "fromHexadecimal.h"

#define bar "\n\t________________________________________"

std::string fromHexadecimal::conversion(std::string hex, int state)
{
	std::string result("\n\tHexadecimal: 0x");
	result.append(hex);

	result.append(bar);

	//Converting to Decimal
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Decimal: ");
		result.append(std::to_string(toDec(hex)));
	}

	//Converting to Binary
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Binary: 0b");
		result.append(this->toBin(toDec(hex)));
	}

	//Converting to Octal
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Octodecimal: 0o");
		result.append(this->toOctal(toDec(hex)));
	}

	result.append(bar);

	return result;
}

int fromHexadecimal::toDec(std::string num) {
	int len = num.length();
	int base = 1;
	int temp = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			temp += (num[i] - 48) * base;
			base = base * 16;
		}
		else if (num[i] >= 'A' && num[i] <= 'F') {
			temp += (num[i] - 55) * base;
			base = base * 16;
		}
	}
	return temp;
}