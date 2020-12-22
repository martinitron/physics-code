#include <iostream>

#include "InputParser/InputParser.h"
#include "Meshes/Meshes.h"
#include "Meshes/GridPoints.h"

int
main(int argc, char** argv)
{
	std::cout << "Hello world!\n";

	InputParser::InputParser ip;
	ip.readFile("C:\\Users\\kateb\\MartinBlick\\Source\\Repos\\physics-code\\input.txt");

	Meshes::Meshes m;
	Meshes::GridPoints gp(100, Meshes::dimension::D2);
	Meshes::GridPoints::Iterator i;

	return 0;
}