#pragma once


class fromDecimal
{
public:
	std::string conversion(int, int);
	
protected:
	std::string toHex(int);
	std::string toBin(int);
	std::string toOctal(int);

};