#include <bitset>
#include <string>

#include "fromDecimal.h"

#define bar "\n\t________________________________________"

std::string fromDecimal::conversion(int dec, int state) 
{
	std::string result("\n\tDecimal: ");
	result.append(std::to_string(dec));

	result.append(bar);

	//Converting to Binary
	if (state == 0 || state == 1)
	{
		result.append("\n\t- Binary: 0b");
		result.append(toBin(dec));
	}

	//Converting to Octal
	if (state == 0 || state == 2)
	{
		result.append("\n\t- Octodecimal: 0o");
		result.append(toOctal(dec));
	}

	//Converting to Hex
	if (state == 0 || state == 3)
	{
		result.append("\n\t- Hexadecimal: 0x");
		result.append(toHex(dec));
	}

	result.append(bar);

	return (std::move(result));
}

std::string fromDecimal::toBin(int dec) 
{
	return std::move((std::bitset<8>(dec).to_string()));
}

std::string fromDecimal::toOctal(int dec) 
{
	std::string octalNum("");

	while (dec > 0) 
	{
		int total = dec % 8;
		dec /= 8;
		octalNum.append(std::to_string(total));
	}

	std::reverse(octalNum.begin(), octalNum.end());

	return (std::move(octalNum));
}

std::string fromDecimal::toHex(int dec) 
{
	std::string hexNumber("");

	while (dec > 0) 
	{
		int rem = dec % 16;
		if (rem > 9) 
		{
			switch (rem) 
			{
			case 10: hexNumber.append("A"); break;
			case 11: hexNumber.append("B"); break;
			case 12: hexNumber.append("C"); break;
			case 13: hexNumber.append("D"); break;
			case 14: hexNumber.append("E"); break;
			case 15: hexNumber.append("F"); break;
			}
		}
		else
			hexNumber.append(std::to_string(rem));
		dec /= 16;
	}

	std::reverse(hexNumber.begin(), hexNumber.end());

	return(std::move(hexNumber));
}