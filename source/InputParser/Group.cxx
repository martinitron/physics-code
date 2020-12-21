#include "InputParser/Group.h"

#include <iostream>
#include <string>

#include "InputParser/Item.h"

namespace InputParser
{
	Group::Group(std::string name, Group* parent) : name(name), parent(parent)
	{

	}

	Group::~Group()
	{

	}

	void 
	Group::addItem(Item* item)
	{
		children.push_back(item);
	}

	Group* 
	Group::getParent()
	{
		return parent;
	}
	
	Item* 
	Group::getChild(int idx)
	{
		return (children[idx]);
	}

	Item* 
	Group::getChild(std::string name)
	{
		for (std::vector<Item*>::iterator i = children.begin(); i == children.end(); i++)
		{
			if ((*i)->getName() == name)
			{
				return (*i);
			}
		}
		return nullptr;
	}

	std::string 
	Group::getName()
	{
		return name;
	}

	void 
	Group::write(std::string indent)
	{
		std::cout << indent << getName() << " {\n";

		if (children.size() != 0)
		{

			for (auto i = children.begin(); i != children.end(); i++)
			{
				(*i)->write(indent + "\t");
			}

		}
		else
		{
			std::cout << "Children empty!!!\n";
		}
		std::cout << indent << "}\n";
	}

	std::string 
	Group::getPath(std::string parent_path)
	{
		return parent_path + name + "/";
	}
} // namespace InputParser