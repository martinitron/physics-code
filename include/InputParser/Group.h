#ifndef INPUT_PARSER_GROUP_H
#define INPUT_PARSER_GROUP_H

#include "InputParser/Item.h"

#include <vector>

namespace InputParser
{

	class Group : public Item
	{
	private:
		std::string name;
		Group* parent;
		std::vector<Item*> children;
	protected:
	public:
		Group() = delete;
		Group(std::string name, Group* parent = nullptr);
		~Group();

		void addItem(Item* item);
		Group* getParent();
		Item* getChild(int idx);
		Item* getChild(std::string name);
		std::string getName();
		void write();
		std::string getPath(std::string parent_path = "/");
	}; // class Group

} // namespace InputParser

#endif