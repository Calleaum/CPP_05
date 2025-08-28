/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:26 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 11:20:38 by calleaum         ###   ########.fr       */
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
	std::cout << "\n*-* Testing ShrubberyCreationForm *-*" << std::endl;
	try
	{
		Bureaucrat Oui("Oui", 130); // can sign & execute
		ShrubberyCreationForm shrub("yes");

		Oui.signForm(shrub);
		Oui.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cerr << " Error: " << e.what() << std::endl;
	}

	std::cout << "\n*-* Testing RobotomyRequestForm *-*" << std::endl;
	try
	{
		Bureaucrat Aguy("A guy", 45);
		RobotomyRequestForm robot("OUI");

		Aguy.signForm(robot);
		for (int i = 0; i < 3; ++i)
			Aguy.executeForm(robot);
	} catch (const std::exception &e)
	{
		std::cerr << " Error: " << e.what() << std::endl;
	}

	std::cout << "\n*-* Testing PresidentialPardonForm *-*" << std::endl;
	try
	{
		Bureaucrat Random("Random", 1);
		PresidentialPardonForm pardon("Guy");

		Random.signForm(pardon);
		Random.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << " Error: " << e.what() << std::endl;
	}

	std::cout << "\n*-* Testing form not signed *-*" << std::endl;
	try
	{
		Bureaucrat NON("NON", 1);
		PresidentialPardonForm unsignedForm("Nobody");
		NON.executeForm(unsignedForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << " Error: " << e.what() << std::endl;
	}

	std::cout << "\n*-* Testing insufficient execution grade *-*" << std::endl;
	try
	{
		Bureaucrat Head("Head", 150);
		ShrubberyCreationForm shrub("bang");

		Head.signForm(shrub);       // allowed
		Head.executeForm(shrub);    // should fail
	}
	catch (const std::exception &e)
	{
		std::cerr << " Error: " << e.what() << std::endl;
	}

	return 0;
}