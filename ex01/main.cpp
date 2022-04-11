/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:06:37 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 19:45:09 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	int		i;
	unsigned long int		ul;
	bool	b;
	char	c;
	double	d;
	float	f;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data data;
	
	Data *ptr;
	uintptr_t raw;

	data.i = 42;
	data.ul = 4294967295;
	data.b = true;
	data.c = 'c';
	data.d = 12.43;
	data.f = 0.123f;

	std::cout << data.i << std::endl;
	std::cout << data.ul << std::endl;
	std::cout << data.c << std::endl;
	std::cout << data.b << std::endl;
	std::cout << data.f << std::endl;
	std::cout << data.d << std::endl;
	std::cout << "-----------------------" << std::endl;
	raw = serialize(&data);
	ptr = deserialize(raw);
	std::cout << "-----------------------" << std::endl;
	std::cout << ptr->i << std::endl;
	std::cout << ptr->ul << std::endl;
	std::cout << ptr->c << std::endl;
	std::cout << ptr->b << std::endl;
	std::cout << data.f << std::endl;
	std::cout << data.d << std::endl;

	return (0);
}