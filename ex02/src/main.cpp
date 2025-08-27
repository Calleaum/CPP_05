/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:26 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 15:03:30 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 130); // can sign & execute
		ShrubberyCreationForm shrub("home");

		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	try
	{
		Bureaucrat technician("Technician", 45);// just enough to sign and execute
		RobotomyRequestForm robot("Bender");

		technician.signForm(robot);
		for (int i = 0; i < 3; ++i)
			technician.executeForm(robot);
	} catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	try
	{
		Bureaucrat president("President", 1); // very high grade
		PresidentialPardonForm pardon("Ford Prefect");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing form not signed ---" << std::endl;
	try
	{
		Bureaucrat junior("Junior", 1);
		PresidentialPardonForm unsignedForm("Nobody");
		junior.executeForm(unsignedForm); // not signed!
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing insufficient execution grade ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("office");

		intern.signForm(shrub);       // allowed
		intern.executeForm(shrub);    // should fail
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	return 0;
}