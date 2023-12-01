#include <iostream>
#include <fstream>
#include <string>

constexpr const char* one = "one";
constexpr const char* two = "two";
constexpr const char* three = "three";
constexpr const char* four = "four";
constexpr const char* five = "five";
constexpr const char* six = "six";
constexpr const char* seven = "seven";
constexpr const char* eight = "eight";
constexpr const char* nine = "nine";

short getNumber(std::string& line)// this is probably much better served by either a state machine or a graph of some sort
{
	char first{ 0 }, second{ 0 }, temp{ 0 };
	bool found = false;
	bool foundSecond = false;
	auto convertTextToDigit = [&line](size_t i) -> char {
		auto result = line.find(one, i);
		if (result == i)
		{
			return '1';
		}
		result = line.find(two, i);
		if (result == i)
		{
			return '2';
		}
		result = line.find(three, i);
		if (result == i)
		{
			return '3';
		}
		result = line.find(four, i);
		if (result == i)
		{
			return '4';
		}
		result = line.find(five, i);
		if (result == i)
		{
			return '5';
		}
		result = line.find(six, i);
		if (result == i)
		{
			return '6';
		}
		result = line.find(seven, i);
		if (result == i)
		{
			return '7';
		}
		result = line.find(eight, i);
		if (result == i)
		{
			return '8';
		}
		result = line.find(nine, i);
		if (result == i)
		{
			return '9';
		}
		return 0;
	};

	char result{ 0 };
	for (size_t i = 0; i < line.size(); ++i)
	{
		temp = line.at(i);
		
		switch (temp)// giga lazy solution
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (!found)
			{
				first = temp;
				found = true;
			}
			else
			{
				second = temp;
				foundSecond = true;
			}
			break;
		case 'o':
		case 't':
		case 'f':
		case 'e':
		case 'n':
		case 's':
			result = convertTextToDigit(i);
			if (result != 0)
			{
				if (!found)// really stupid code duplication
				{
					first = result;
					found = true;
				}
				else
				{
					second = result;
					foundSecond = true;
				}
			}
			break;
		default:
			continue;
		}
	}

	// real damn dumb way to do it, but it works
	if (foundSecond)
	{
		return ((first - 48) * 10 + (second - 48));
	}
	else
	{
		short tempFirst = (first - 48);
		return (tempFirst * 10 + tempFirst);
	}

	return 0;
}

int main()
{
	std::cout << "Hello there!\n";
	std::string inputFileName{ "input.txt" };
	std::ifstream inputFile(inputFileName);
	if (inputFile.is_open())
	{
		std::string line;
		long long sum{ 0 };
		while (std::getline(inputFile, line))
		{
			short temp = getNumber(line);
			std::cout << "result for line: \"" << line << "\" is: \t\t"<< temp  << '\n';
			sum += temp;
		}

		std::cout << "The sum is: " << sum << '\n';
		system("pause");
	}
	else
	{
		std::cerr << "Could not open file \"" << inputFileName << "\"\n";
		return 1;
	}

	return 0;
}