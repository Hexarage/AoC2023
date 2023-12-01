#include <iostream>
#include <fstream>
#include <string>

long getDigits(std::string& line)
{
	char first{ 0 }, second{ 0 }, temp{ 0 };
	bool found = false;
	bool foundSecond = false;
	for (size_t i = 0; i < line.size(); ++i)
	{
		temp = line.at(i);// digits in ascii are from 48 to 57
		if (temp > 47 && temp < 58)
		{
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
		}
	}

	// real damn dumb way to do it, but it works
	if (foundSecond)
	{
		return ((first - 48) * 10 + (second - 48));
	}
	else
	{
		long tempFirst = (first - 48);
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
			long temp = getDigits(line);
			std::cout << "result for line: \"" << line << "\" is: \t"<< temp  << '\n';
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