/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:07:44 by jforner           #+#    #+#             */
/*   Updated: 2022/08/19 10:57:46 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <cstdlib>

class Base {

public:
	virtual ~Base(){};
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif