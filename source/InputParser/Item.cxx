#include "InputParser/Item.h"

#include <regex>
#include <string>

namespace InputParser
{
	std::string keyword("[a-zA-Z_][a-zA-Z_0-9]+");
	std::string integer("[0-9]+");
	std::string real("[0-9]+\\.[0-9]*[f]?");
	std::string string("\"[a-zA-Z_0-9. ]+\"");
	std::string boolean("([Tt]([Rr][Uu][Ee])?|[Ff]([Aa][Ll][Ss][Ee])?)");
	
	std::string line_end(";");

	std::string integer_list("\\[\\s*" + integer + "\\s*(,\\s*" + integer + "\\s*)*\\]");
	std::string real_list("\\[\\s*" + real + "\\s*(,\\s*" + real + "\\s*)*\\]");
	std::string string_list("\\[\\s*" + string + "\\s*(,\\s*" + string + "\\s*)*\\]");
	std::string boolean_list("\\[\\s*" + boolean + "\\s*(,\\s*" + boolean + "\\s*)*\\]");

	std::string integer_assignment("(" + keyword + ")" + "\\s*=\\s*(" + integer + ")\\s*" + line_end);
	std::string real_assignment("(" + keyword + ")" + "\\s*=\\s*(" + real + ")\\s*" + line_end);
	std::string string_assignment("(" + keyword + ")" + "\\s*=\\s*(" + string + ")\\s*" + line_end);
	std::string boolean_assignment("(" + keyword + ")" + "\\s*=\\s*(" + boolean + ")\\s*" + line_end);
	
	std::string integer_list_assignment("(" + keyword + ")" + "\\s*=\\s*(" + integer_list + ")\\s*" + line_end);
	std::string real_list_assignment("(" + keyword + ")" + "\\s*=\\s*(" + real_list + ")\\s*" + line_end);
	std::string string_list_assignment("(" + keyword + ")" + "\\s*=\\s*(" + string_list + ")\\s*" + line_end);
	std::string boolean_list_assignment("(" + keyword + ")" + "\\s*=\\s*(" + boolean_list + ")\\s*" + line_end);

	std::regex re_keyword(keyword, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_integer(integer, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_real(real, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_string(string, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_boolean(boolean, std::regex_constants::ECMAScript | std::regex_constants::icase);

	std::regex re_integer_assignment(integer_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_real_assignment(real_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_string_assignment(string_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_boolean_assignment(boolean_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);

	std::regex re_integer_list_assignment(integer_list_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_real_list_assignment(real_list_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_string_list_assignment(string_list_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_boolean_list_assignment(boolean_list_assignment, std::regex_constants::ECMAScript | std::regex_constants::icase);

	std::regex re_group_open("(" + keyword + ")" + "\\s*\\{(.*)", std::regex_constants::ECMAScript | std::regex_constants::icase);
	std::regex re_group_close("\\s*(.*)\\}", std::regex_constants::ECMAScript | std::regex_constants::icase);
}