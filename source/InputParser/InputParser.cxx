#include "InputParser/InputParser.h"

#include <fstream>
#include <iostream>
#include <locale> // toupper
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
		else if (std::regex_search(line, rm, re_boolean_assignment))
		{
			//std::cout << "Boolean found.\n";

			std::string result = rm[2].str();
			std::string conversion;
			for (auto i : result) 
			{
				conversion += toupper(i);
			}
			Variable<bool>* temp = new Variable(rm[1], conversion == "TRUE" || conversion == "T" ? true : false);
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_group_open))
		{
			//std::cout << "Group started.\nGroup name: " << rm[1].str() << "\n";
			Group* temp = new Group(rm[1].str(), cur_state, cur_state->getLevel() + 1);
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
		else if (std::regex_search(line, rm, re_integer_list_assignment))
		{
			std::string result = rm[2].str();
			result = result.substr(result.find('[') + 1, (result.find(']') - 1) - result.find('['));
			std::vector<int> list;
			
			size_t pos_s = 0;
			size_t pos_e = result.find(',');
			if (pos_e == std::string::npos && result.size() > 0)
			{
				list.push_back( stoi(result) );
			}
			else
			{
				while (pos_e != std::string::npos)
				{
					list.push_back(stoi(result.substr(pos_s, pos_e - pos_s)));
					pos_s = pos_e + 1;
					pos_e = result.find(',', pos_s);
					if (pos_e == std::string::npos && result.size() > 0)
					{
						list.push_back(stoi(result.substr(pos_s, std::string::npos)));
					}
				}
			}
			
			Variable<std::vector<int>>* temp = new Variable(rm[1], list);
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_real_list_assignment))
		{
			std::string result = rm[2].str();
			result = result.substr(result.find('[') + 1, (result.find(']') - 1) - result.find('['));
			std::vector<float> list;

			size_t pos_s = 0;
			size_t pos_e = result.find(',');
			if (pos_e == std::string::npos && result.size() > 0)
			{
				list.push_back(stof(result));
			}
			else
			{
				while (pos_e != std::string::npos)
				{
					list.push_back(stof(result.substr(pos_s, pos_e - pos_s)));
					pos_s = pos_e + 1;
					pos_e = result.find(',', pos_s);
					if (pos_e == std::string::npos && result.size() > 0)
					{
						list.push_back(stof(result.substr(pos_s, std::string::npos)));
					}
				}
			}

			Variable<std::vector<float>>* temp = new Variable(rm[1], list);
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_string_list_assignment))
		{
			std::string result = rm[2].str();
			result = result.substr(result.find('[') + 1, (result.find(']') - 1) - result.find('['));
			std::vector<std::string> list;

			size_t pos_s = 0;
			size_t pos_e = result.find(',');
			if (pos_e == std::string::npos && result.size() > 0)
			{
				list.push_back(result);
			}
			else
			{
				while (pos_e != std::string::npos)
				{
					list.push_back(result.substr(pos_s, pos_e - pos_s));
					pos_s = pos_e + 1;
					pos_e = result.find(',', pos_s);
					if (pos_e == std::string::npos && result.size() > 0)
					{
						list.push_back(result.substr(pos_s, std::string::npos));
					}
				}
			}	

			Variable<std::vector<std::string>>* temp = new Variable(rm[1], list);
			cur_state->addItem(temp);
		}
		else if (std::regex_search(line, rm, re_boolean_list_assignment))
		{
			std::string result = rm[2].str();
			result = result.substr(result.find('[') + 1, (result.find(']') - 1) - result.find('['));
			std::vector<bool> list;

			size_t pos_s = 0;
			size_t pos_e = result.find(',');

			if (pos_e == std::string::npos && result.size() > 0)
			{
				std::string conversion;
				for (auto i : result)
				{
					conversion += toupper(i);
				}
				list.push_back(conversion == "TRUE" || conversion == "T" ? true : false);
			}
			else
			{
				while (pos_e != std::string::npos)
				{
					std::string conversion;
					for (auto i : result.substr(pos_s, pos_e - pos_s))
					{
						conversion += toupper(i);
					}
					list.push_back(conversion == "TRUE" || conversion == "T" ? true : false);
					pos_s = pos_e + 1;
					pos_e = result.find(',', pos_s);
					if (pos_e == std::string::npos && result.size() > 0)
					{
						std::string conversion;
						for (auto i : result.substr(pos_s, std::string::npos))
						{
							conversion += toupper(i);
						}
						list.push_back(conversion == "TRUE" || conversion == "T" ? true : false);
					}	
				}
			}

			Variable<std::vector<bool>>* temp = new Variable(rm[1], list);
			cur_state->addItem(temp);
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