/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:06:11 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 20:34:08 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base 
{
public: 
    virtual ~Base(void)
    {
    }
};

class A : public Base
{
public:	A()
    {
        std::cout << "A" << std::endl;
    } 
    void print()
    {
        std::cout << "AA" << std::endl;
    }
};

class B : public Base
{
public:	B()
    {
        std::cout << "B" << std::endl;
    } 
    void print()
    {
        std::cout << "BB" << std::endl;
    }
};

class C : public Base
{
public:	C()
    {
        std::cout << "C" << std::endl;
    } 
    void print()
    {
        std::cout << "CC" << std::endl;
    }
};
