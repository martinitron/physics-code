#include <iostream>

#include "InputParser/InputParser.h"

int
main(int argc, char** argv)
{
	std::cout << "Hello world!\n";

	InputParser::InputParser ip;
	ip.readFile("C:\\Users\\kateb\\MartinBlick\\Source\\Repos\\physics-code\\input.txt");

	return 0;
}