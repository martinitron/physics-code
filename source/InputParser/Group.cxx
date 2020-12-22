#include "InputParser/Group.h"

#include <iostream>
#include <string>

#include "InputParser/Item.h"

namespace
{
	std::string 
	prefix(int n, std::string s)
	{
		std::string r;
		while (n--)
		{
			r += s;
		}
		return r;
	}
}

namespace InputParser
{
	Group::Group(std::string name, Group* parent, int level) : name(name), parent(parent), level(level)
	{

	}

	Group::~Group()
	{
		for (auto i = children.begin(); i != children.end(); i++)
		{
			delete (*i);
		}
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

	int Group::getLevel()
	{
		return level;
	}

	std::string 
	Group::getName()
	{
		return name;
	}

	void 
	Group::write(std::string indent)
	{
		std::string p = "";
		if (level > 0) p = indent + "    ";
		
		if (level > 0) std::cout << indent << getName() << " {\n";

		if (children.size() != 0)
		{

			for (auto i = children.begin(); i != children.end(); i++)
			{
				(*i)->write(p);
			}

		}
		else
		{
			std::cout << "Children empty!!!\n";
		}

		if (level > 0) std::cout << indent << "}\n";
	}

	std::string 
	Group::getPath(std::string parent_path)
	{
		return parent_path + name + "/";
	}

} // namespace InputParser