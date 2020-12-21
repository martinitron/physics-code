#include "InputParser/InputParser.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "InputParser/Item.h"
#include "InputParser/Variable.h"
#include "InputParser/Group.h"

namespace
{
	InputParser::Group* cur_state = nullptr;
	InputParser::Group* head_state = nullptr;
}

namespace InputParser
{

	InputParser::InputParser()
	{

	}

	InputParser::~InputParser()
	{

	}

	void InputParser::parseLine(std::string line)
	{
		std::smatch rm;

		if (head_state == nullptr)
		{
			head_state = new Group("");
			cur_state = head_state;
		}

		if (std::regex_search(line, rm, re_integer_assignment))
		{
			//std::cout << "Integer found.\n";
			Variable<int>* temp = new Variable( rm[1], stoi(rm[2].str()) );
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_real_assignment))
		{
			//std::cout << "Real found.\n";
			Variable<float>* temp = new Variable(rm[1], stof(rm[2].str()));
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_string_assignment))
		{
			//std::cout << "String found.\n";
			Variable<std::string>* temp = new Variable(rm[1], rm[2].str());
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_group_open))
		{
			//std::cout << "Group started.\nGroup name: " << rm[1].str() << "\n";
			Group* temp = new Group(rm[1].str(), cur_state);
			cur_state->addItem(temp);
			cur_state = temp;
			//cur_state->write();
		}
		else if (std::regex_search(line, rm, re_group_close))
		{
			//std::cout << "Group finished.\n";
			cur_state = cur_state->getParent();
			//cur_state->write();
		}
	}

	void InputParser::readFile(std::string filename)
	{
		std::ifstream fh;
		std::string line;
		
		fh.open(filename, std::ios::in);

		if (fh.is_open())
		{
			while (getline(fh, line))
			{
				parseLine(line);
			}
			fh.close();
			head_state->write();
		}
		else
		{
			std::cout << "Error opening file: " << filename << ".\n";
		}
	}

} // namespace InputParser