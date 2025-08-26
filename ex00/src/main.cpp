/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:18:09 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/26 11:38:33 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n--- Valid Bureaucrat creation ---" << std::endl;
	Bureaucrat alice("Alice", 42);
	std::cout << alice << std::endl;

	std::cout << "\n--- Incrementing grade ---" << std::endl;
	alice.incrementGrade();
	std::cout << alice << std::endl;

	std::cout << "\n--- Decrementing grade ---" << std::endl;
	alice.decrementGrade();
	std::cout << alice << std::endl;

	std::cout << "\n--- Copy constructor ---" << std::endl;
	Bureaucrat bob = alice;
	std::cout << "Bob copied from Alice: " << bob << std::endl;

	std::cout << "\n--- Assignment operator ---" << std::endl;
	Bureaucrat charlie("Charlie", 100);
	std::cout << "Before assignment: " << charlie << std::endl;
	charlie = alice;
	std::cout << "After assignment from Alice: " << charlie << std::endl;

	std::cout << "\n--- Exception: incrementing too far ---" << std::endl;
	
	try
	{
		Bureaucrat top("Top", MAX_GRADE);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Exception: decrementing too far ---" << std::endl;
	try
	{
		Bureaucrat low("Low", MIN_GRADE);
		std::cout << low << std::endl;
		low.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Exception: invalid grade at construction (0) ---" << std::endl;
	try
	{
		Bureaucrat invalidHigh("InvalidHigh", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Exception: invalid grade at construction (151) ---" << std::endl;
	try 
	{
		Bureaucrat invalidLow("InvalidLow", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}