/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:33:39 by jforner           #+#    #+#             */
/*   Updated: 2022/08/18 16:46:09 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

int	main()
{
	Data	dat;

	dat.nbr = 3;
	dat.str = "Test";

	uintptr_t i = serialize(&dat);
	
	Data* d = deserialize(i);

	std::cout << "nbr = " << d->nbr << " string = " << d->str << "!" << std::endl;

	// system("leaks convert");
	return 0;
}