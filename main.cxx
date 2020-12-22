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
	Meshes::GridPoints gp(10, Meshes::dimension::D3);
	//Meshes::GridPoints::Iterator i;

	for (Meshes::Grid::iterator i = gp.begin(); i != gp.end(); i++)
	{
		std::cout << "New Point!\n";
		for (Meshes::GridPoint::iterator j = i->begin(); j != i->end(); j++)
		{
			std::cout << "    " << *j << "\n";
		}
		std::cout << "\n";
	}

	return 0;
}