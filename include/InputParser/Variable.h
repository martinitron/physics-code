#ifndef INPUT_PARSER_VARIABLE_H
#define INPUT_PARSER_VARIABLE_H

#include <iostream>
#include <string>
#include <vector>

#include "InputParser/Item.h"

namespace InputParser
{
	void
	write_T(std::string indent, std::string kw, bool d)
	{
		std::cout << indent << kw << " = ";
		if (d)
		{
			std::cout << "True" << line_end << "\n";
		}
		else
		{
			std::cout << "False" << line_end << "\n";
		}
	}

	void
	write_T(std::string indent, std::string kw, std::vector<bool> d)
	{
		std::cout << indent << kw << " = [";

		for (auto i = d.begin(), j = --d.end(); i != j; i++)
		{
			if (*i)
			{
				std::cout << "True, ";
			}
			else
			{
				std::cout << "False, ";
			}
		}
		std::string last = *(--d.end()) ? "True":"False" ;
		std::cout << last << "]" << line_end << "\n";
	}

	template <class T>
	void
	write_T(std::string indent, std::string kw, T d)
	{
		std::cout << indent << kw << " = " << d << line_end << "\n";
	}

	template <class T>
	void
	write_T(std::string indent, std::string kw, std::vector<T> d)
	{
		std::cout << indent << kw << " = [";

		for (auto i = d.begin(), j = --d.end(); i != j; i++)
		{
			std::cout << *i << ", ";
		}
		std::cout << *(--d.end()) << "]" << line_end << "\n";
	}

	template <class T>
	class Variable : public Item

	{
	private:
		std::string kw;
		T d;
	protected:
	public:
		Variable(std::string keyword, T data) : kw(keyword), d(data) {};
		//Variable(std::string keyword, std::vector<T> data) : kw(keyword), d(data) {};
		~Variable() = default;


		void
		write(std::string indent = " ") override
		{
			write_T(indent, kw, d);
		}

		T 
		getData() 
		{
			return d;
		}

		std::string
		getName() override
		{
			return kw;
		}
	};
/*
	template<class T*>
	class Variable : public Item
	{
	private:
		std::string kw;
		T* d;
	protected:
	public:
		Variable(std::string keyword, T data) : kw(keyword), d(data) {};
		~Variable() = default;

		void
		write(std::string indent = " ") override
		{
			std::cout << indent << kw << "=" << *d << line_end << "\n";
		}

		T*
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
*/
} // namespace InputParser

#endif