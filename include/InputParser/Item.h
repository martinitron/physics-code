#ifndef INPUT_PARSER_ITEM_H
#define INPUT_PARSER_ITEM_H

#include <regex>
#include <string>

namespace InputParser
{

	extern std::string keyword;
	extern std::string integer;
	extern std::string real;
	extern std::string string;
	extern std::string line_end;
	extern std::string integer_assignment;
	extern std::string real_assignment;
	extern std::string string_assignment;

	extern std::regex re_keyword;
	extern std::regex re_integer;
	extern std::regex re_real;
	extern std::regex re_string;

	extern std::regex re_integer_assignment;
	extern std::regex re_real_assignment;
	extern std::regex re_string_assignment;

	extern std::regex re_group_open;
	extern std::regex re_group_close;

	class Item
	{
	private:
	protected:
	public:
		Item() = default;
		virtual ~Item() = 0;
		virtual std::string getName() = 0;
		virtual void write() = 0;

	}; // class Item

	inline Item::~Item() = default;

} // namespace InputParser

#endif