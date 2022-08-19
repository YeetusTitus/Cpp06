/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:33:39 by jforner           #+#    #+#             */
/*   Updated: 2022/08/19 11:05:52 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base * generate(void)
{
    Base *baz;
    switch (rand() % 3)
    {
        case 0:
            baz = new A;
            break;
        case 1:
            baz = new B;
            break;
        case 2:
            baz = new C;
            break;
    }
    return (baz);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Type : A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "Type : B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "Type : C" << std::endl;
		return ;
	}
}

void identify(Base& p)
{

	try{
	(void)dynamic_cast<A&>(p);
		std::cout << "Type : A" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
		(void)e;
	}
	try{
	(void)dynamic_cast<B&>(p);
		std::cout << "Type : B" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
		(void)e;
	}
	try{
	(void)dynamic_cast<C&>(p);
		std::cout << "Type : C" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
		(void)e;
	}
}



int	main()
{
	srand(time(NULL));
	Base *baz = generate();
	Base *bas = generate();

	identify(baz);
	identify(*bas);

	// system("leaks convert");
	return 0;
}