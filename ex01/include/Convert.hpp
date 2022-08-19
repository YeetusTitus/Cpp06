/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:23:32 by jforner           #+#    #+#             */
/*   Updated: 2022/08/18 18:25:38 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <stdint.h>

typedef struct data_s {
int 		nbr;
std::string	str;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);


#endif