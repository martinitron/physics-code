#ifndef INPUT_PARSER_VARIABLE_H
#define INPUT_PARSER_VARIABLE_H

#include "InputParser/Item.h"

namespace InputParser
{

	template <class T>
	class Variable : public Item

	{
	private:
		std::string kw;
		T d;
	protected:
	public:
		Variable(std::string keyword, T data) : kw(keyword), d(data) {};
		~Variable() = default;

		void 
		write()
		{
			std::cout << kw << "=" << d << line_end << "\n";
		}

		T 
		getData()
		{
			return d;
		}

		std::string
		getName()
		{
			return kw;
		}
	};

} // namespace InputParser

#endif