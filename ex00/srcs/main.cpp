/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:33:39 by jforner           #+#    #+#             */
/*   Updated: 2022/08/18 21:12:05 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "The numbers of arguments is not correct !" << std::endl;
		return 0;
	}
	std::string	str;
	str = argv[1];
	Convert conv(str);
	try
	{
		std::cout << " char : " << conv.toChar() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << " int : " << conv.toInt() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << " float : " << conv.toFloat() ;
		if (fmod(conv.getValue(), 1) == 0 && conv.getValue() < 100000 && conv.getValue() > -100000)
			std::cout << ".0";
		if (conv.getValue() < 100000 && conv.getValue() > -100000)
			std::cout << "f";
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << " double : " << conv.toDouble() ;
		if (fmod(conv.getValue(), 1) == 0 && (conv.getValue() < 100000 && conv.getValue() > -100000))
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// system("leaks convert");
	return 0;
}