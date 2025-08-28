/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:26 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 10:40:10 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n*-* Intern Tests *-*\n";
	Intern intern;

	AForm* f1 = intern.makeForm(SC_NAME, "tree");
	if (f1)
	{
		Bureaucrat Oui("Oui", 137);
		Oui.signForm(*f1);
		Oui.executeForm(*f1);
		delete f1;
	}

	AForm* f2 = intern.makeForm(RR_NAME, "Pouet");
	if (f2)
	{
		Bureaucrat roboguy("Pwet", 45);
		roboguy.signForm(*f2);
		roboguy.executeForm(*f2);
		delete f2;
	}

	AForm* f3 = intern.makeForm(PP_NAME, "Random");
	if (f3)
	{
		Bureaucrat prez("Guy", 1);
		prez.signForm(*f3);
		prez.executeForm(*f3);
		delete f3;
	}

	AForm* fail = intern.makeForm("FormThatDoesNotExist", "Nobody");
	if (!fail)
		std::cout << "Returned nullptr for unknown form as expected.\n";

	std::cout << "\nAll tests completed.\n";
	return 0;
}
