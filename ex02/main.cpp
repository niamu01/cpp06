/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:05:23 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 20:34:34 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base * generate(void)
{
	int ret = rand() % 3;
	if (ret == 0)
		return (static_cast<Base *>(new A()));
	else if (ret == 1)
		return (static_cast<Base *>(new B()));
	else
		return (static_cast<Base *>(new C()));
}

void identify(Base* p)
{
	A * a = dynamic_cast<A *>(p);
	B * b = dynamic_cast<B *>(p);
	C * c = dynamic_cast<C *>(p);
	if (a)
		a->print();
	else if (b)
		b->print();
	else if (c)
		c->print();
	else
		std::cout << "Can not identify this type" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A & a = dynamic_cast<A &>(p);
		a.print();
	}
	catch (std::exception &e)
	{
	}
	try 
	{
		B & b = dynamic_cast<B &>(p);
		b.print();
	}
	catch (std::exception &e)
	{
	}
	try 
	{
		C & c = dynamic_cast<C &>(p);
		c.print();
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	srand(time(NULL));
	
	Base *basePtr = generate();
	Base &baseRef = *basePtr;

	identify(basePtr);
	identify(baseRef);

	delete basePtr;
	return (0);
}
