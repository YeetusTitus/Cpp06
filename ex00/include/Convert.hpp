/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:23:32 by jforner           #+#    #+#             */
/*   Updated: 2022/08/18 21:12:26 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <vector>
# include <cstdlib>
# include <limits>
# include <tgmath.h>

class Convert {

private :
	double	value;
	bool	possible;
	
	void	isPossible(std::string str);
	bool isFloat(std::string str);
	bool isDouble(std::string str);

public:
    Convert(std::string val);
    ~Convert(void);
        
    Convert(const Convert &copy);

    Convert& operator=(const Convert &copy);

	double	getValue(void);
	bool	getPossible(void);

	int		toInt(void);
	char	toChar(void);
	float	toFloat(void);
	double	toDouble(void);


	class ImpossibleException : public std::exception
	{
		public:
		const char *	what(void) const throw();
	};
	class NotPrintException : public std::exception
	{
		public:
		const char *	what(void) const throw();
	};

};


#endif