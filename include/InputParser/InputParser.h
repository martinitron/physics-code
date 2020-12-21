#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>

namespace InputParser
{

	class InputParser
	{
	private:
		void parseLine(std::string line);
	protected:
	public:
		InputParser();
		~InputParser();

		void readFile(std::string filename);
	}; // class InputParser

} // namespace InputParser
#endif