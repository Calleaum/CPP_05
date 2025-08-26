/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:18:09 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/26 15:10:47 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n--- Valid Form creation ---" << std::endl;
	Form taxForm("TaxForm", 50, 25, false);
	std::cout << taxForm << std::endl;

	std::cout << "\n--- Bureaucrat signs the form (success) ---" << std::endl;
	Bureaucrat alice("Alice", 30);
	alice.signForm(taxForm);
	std::cout << taxForm << std::endl;

	std::cout << "\n--- Bureaucrat tries to sign already signed form (should still work) ---" << std::endl;
	alice.signForm(taxForm);

	std::cout << "\n--- Bureaucrat too low to sign ---" << std::endl;
	Bureaucrat bob("Bob", 60);
	Form ndaForm("NDAForm", 50, 20, false);
	bob.signForm(ndaForm);
	std::cout << ndaForm << std::endl;

	std::cout << "\n--- Invalid Form creation (sign grade too high) ---" << std::endl;
	try {
		Form illegalForm("IllegalForm", 0, 20, false);
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid Form creation (exec grade too low) ---" << std::endl;
	try {
		Form illegalForm("IllegalForm", 50, 151, false);
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Copy constructor and assignment operator ---" << std::endl;
	Form original("OriginalForm", 42, 24, true);
	Form copy = original;
	std::cout << "Copy (via copy constructor):\n" << copy << std::endl;

	Form assigned("AssignedForm", 100, 100, false);
	assigned = original;
	std::cout << "Assigned (via operator=):\n" << assigned << std::endl;

	return 0;
}