#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream> 
#include <algorithm>

#pragma region Using and Define Declarations

using std::endl;
using std::cout;
using std::cin;
using std::string;

using std::stoi;

#define cls system("cls");
#define second(x) 1000 * x
#define tab "\t"

#pragma endregion

#pragma region Header Objects

#include "fromDecimal.h"
#include "fromBinary.h"
#include "fromOctodecimal.h"
#include "fromHexadecimal.h"

fromDecimal from_Decimal;
fromBinary from_Binary;
fromOctal from_Octal;
fromHexadecimal from_Hexadecimal;

#pragma endregion

#pragma region Function Declaration

int StringFilter(int limit);
void Error();
void Title();

#pragma endregion

int main() 
{
	Title();

	while (true)
	{

#pragma region Variable Declaration

	int valueType, convertType, convertTo, length;
	string placeholder;

	char available_l[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	string choices("\n\tOptions of Convertion:\n\n\t"), option_r;
	bool invalidKey = true;

#pragma endregion

#pragma region Main option

		while (invalidKey)
		{
			cout
				<< endl
				<< tab << tab << "Main Menu" << endl
				<< endl
				<< tab << "1. Decimal" << endl
				<< tab << "2. Binary" << endl
				<< tab << "3. Octal/Octodecimal" << endl
				<< tab << "4. Hexadecimal" << endl
				<< endl
				<< tab << "Enter What Type of Value it came from." << endl
				<< tab << "According to corresponding number above: ";
			valueType = StringFilter(4);

			invalidKey = (valueType == 0) ? true : false;
		}
		cls;

#pragma endregion

#pragma region Conversion type

		invalidKey = true;
		while (invalidKey)
		{
			cout
				<< endl
				<< tab << tab << "Conversion Type" << endl
				<< endl
				<< tab << "1. Linear Conversion" << endl
				<< tab << "2. Multi Conversion" << endl
				<< endl
				<< tab << "Enter What Type of Conversion." << endl
				<< tab << "According to corresponding number above: ";
			convertType = StringFilter(2);

			invalidKey = (convertType == 0) ? true : false;
		}
		cls;

#pragma endregion

#pragma region Linear Options

		if (convertType == 1)
		{
			invalidKey = true;

			while (invalidKey)
			{
				int opt = 0;
				if (valueType != 1)
				{
					opt++;
					choices.append(std::to_string(opt));
					choices.append(". Decimal\n\t");
				}

				if (valueType != 2)
				{
					opt++;
					choices.append(std::to_string(opt));
					choices.append(". Binary\n\t");
				}

				if (valueType != 3)
				{
					opt++;
					choices.append(std::to_string(opt));
					choices.append(". Octal/Octodecimal\n\t");
				}

				if (valueType != 4)
				{
					opt++;
					choices.append(std::to_string(opt));
					choices.append(". Hexadecimal\n\t");
				}

				cout << choices
					<< endl
					<< tab << "Enter What Type of Value to convert." << endl
					<< tab << "According to corresponding number above: ";
				convertTo = StringFilter(3);

				invalidKey = (convertType == 0) ? true : false;
			}
		}
		else
			convertTo = 0;

		cls;

#pragma endregion

#pragma region Convert

		invalidKey = true;
		while (invalidKey)
		{
			cout << endl
				<< tab << "Enter what to Convert: ";
			cin >> placeholder;

			cls;

#pragma endregion

#pragma region Improper Input Filter

			switch (valueType)
			{
			case 1:
				length = 10;
				break;
			case 2:
				length = 2;
				break;
			case 3:
				length = 8;
				break;
			case 4:
				length = 16;
				break;
			}

			for (int i = 0; i < placeholder.length(); i++)
			{
				bool error = true;
				for (int a = 0; a < length; a++)
				{
					if (a >= 10)
					{
						if (std::toupper(placeholder[i]) == available_l[a - 10])
						{
							error = false;
							break;
						}
					}
					else
					{
						char b = (char)a + '0';
						if (placeholder[i] == b)
						{
							error = false;
							break;
						}
					}
				}

				if (error)
				{
					invalidKey = true;

					Error();

					break;
				}
				else
					invalidKey = false;
			}

		}

#pragma endregion

#pragma region Process

		switch (valueType)
		{
		case 1:
			cout << from_Decimal.conversion(stoi(placeholder), convertTo);
			break;
		case 2:
			cout << from_Binary.conversion(stoi(placeholder), convertTo);
			break;
		case 3:
			cout << from_Octal.conversion(stoi(placeholder), convertTo);
			break;
		case 4:
			std::transform(placeholder.begin(), placeholder.end(), placeholder.begin(), ::toupper);
			cout << from_Hexadecimal.conversion(placeholder, convertTo);
			break;
		}

#pragma endregion
	
#pragma region Retry

		cout << endl
			<< endl
			<< tab << "Exit [y/n]: ";
		cin >> option_r;

		if (std::tolower(option_r[0]) == 'y')
			break;

		cls;
#pragma endregion

	}
}

int StringFilter(int limit)
{
	string placeholder("");

	cin >> placeholder;


	int i_placeholder;
	try
	{
		i_placeholder = stoi(placeholder) + 0;
	}
	catch (const std::exception&)
	{
		std::stringstream geek(placeholder);
		geek >> i_placeholder;
	}
	
	if (i_placeholder > 0 && i_placeholder <= limit)
	{
		return i_placeholder;
	}
	
	Error();

	return 0;
}

void Error()
{
	cls;

	cout << endl << tab << "User Input Invalid!";
	Sleep(second(3));

	cls;
}

void Title()
{
	cout
		<< tab << "This Program is created to Convert:" << endl
		<< tab << tab << " - Decimal" << endl
		<< tab << tab << " - Binary" << endl
		<< tab << tab << " - Hexadecimal" << endl
		<< tab << tab << " - Octodecimal" << endl
		<< endl
		<< tab << " With Additional Features:" << endl
		<< tab << tab << "- Two Types of Conversion: Multi and Linear" << endl
		<< tab << tab << "- Exit/Retry option" << endl
		<< tab << tab << "- Error Trapping: Auto Capslock" << endl
		<< tab << tab << "                  Typographic Error;" << endl
		<< tab << tab << tab << "- Into Choices" << endl
		<< tab << tab << tab << "- Into Declaring Conversion" << endl;

	Sleep(second(5));
	cls;
}