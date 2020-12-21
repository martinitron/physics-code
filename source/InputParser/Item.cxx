#include "InputParser/Item.h"

#include <regex>
#include <string>

namespace InputParser
{
	std::string keyword("[a-zA-Z_][a-zA-Z_0-9]+");
	std::string integer("[0-9]+");
	std::string real("[0-9]+\\.[0-9]*[f]?");
	std::string string("\"[a-zA-Z_0-9.]+\"");
	std::string line_end(";");
	std::string integer_assignment("(" + keyword + ")" + "\\s*=\\s*(" + integer + ")" + line_end);
	std::string real_assignment("(" + keyword + ")" + "\\s*=\\s*(" + real + ")" + line_end);
	std::string string_assignment("(" + keyword + ")" + "\\s*=\\s*(" + string + ")" + line_end);


	std::regex re_keyword(keyword, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_integer(integer, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_real(real, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_string(string, std::regex_constants::ECMAScript | std::regex_constants::icase);

	std::regex re_integer_assignment(integer_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_real_assignment(real_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_string_assignment(string_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);

	std::regex re_group_open("(" + keyword + ")" + "\\s*\\{(.*)", std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_group_close("\\s*(.*)\\}", std::regex_constants::ECMAScript | std::regex_constants::icase);
}