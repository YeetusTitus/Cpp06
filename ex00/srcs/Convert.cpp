/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:23:07 by jforner           #+#    #+#             */
/*   Updated: 2022/08/19 10:01:04 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

//constructor & destructor

Convert::Convert(std::string val)
{
	isPossible(val);
	if (val.length() == 1 && !isdigit(val[0]))
		this->value = static_cast<double>(val[0]);
	else
		this->value = static_cast<double>(atof(val.c_str()));
  // std::cout << value << " Convert created !" << std::endl;
}

Convert::Convert(const Convert &copy) : value(copy.value)
{

  // std::cout << "Convert created from a copy!" << std::endl;
}

Convert::~Convert(void)
{

  // std::cout << "Convert destroyed!" << std::endl;
}

//operation overloader

Convert&  Convert::operator=(const Convert &copy)
{
	value = copy.value;

	return *this;
  // std::cout << "Convert copied!" << std::endl;
}
//getter & setter

double	Convert::getValue(void)
{
	return this->value;
}
bool	Convert::getPossible(void)
{
	return this->possible;	
}
//other

//bonus
int		Convert::toInt(void)
{
	if (value > INT_MAX || value < INT_MIN || value != value || !possible)
		throw Convert::ImpossibleException();
	return (static_cast<int>(value));
}

char	Convert::toChar(void)
{
	if (value > CHAR_MAX || value < CHAR_MIN || value != value || !possible)
		throw Convert::ImpossibleException();
	if (!isprint(value))
		throw Convert::NotPrintException();
	return (static_cast<char>(value));
}

float	Convert::toFloat(void)
{
	if (!possible)
		throw Convert::ImpossibleException();
	return (static_cast<float>(value));
}

double	Convert::toDouble(void)
{
	if (!possible)
		throw Convert::ImpossibleException();
	return (static_cast<double>(value));
}

void	Convert::isPossible(std::string str)
{
	if (str.length() == 1 || isFloat(str) || isDouble(str))
		possible = true;	
	else
		possible = false;
}


bool	Convert::isFloat(std::string str)
{
	bool	dot = false;

	if (!str.compare("inff") || !str.compare("-inff"))
		return (true);
	if (str[str.length() - 1] == '.')
		return (false);
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == 'f' && (!dot || (i > 0 && !isdigit(str[i - 1]))))
			return (false);
		if (str[i] == '-' && i > 0)
			return (false);
		if (str[i] == '.' && (dot || (i > 0 && !isdigit(str[i - 1])) || i == 0))
			return (false);
		if (!isdigit(str[i]) && str[i] != '.'  && str[i] != 'f' && str[i] != '-')
			return (false);
		if (i > 0 && isdigit(str[i]) && str[i - 1] == 'f')
			return (false);
		if (str[i] == '.')
			dot = true;
	}
	return (true);
}

bool	Convert::isDouble(std::string str)
{
	if (!str.compare("inf") || !str.compare("-inf") || !str.compare("nan"))
		return (true);
	return (false);
}

//exceptions
const char *	Convert::ImpossibleException::what(void) const throw()
{
	return ("Impossible");

}

const char *	Convert::NotPrintException::what(void) const throw()
{
	return ("Non displayable");
}