/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:26 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 15:41:50 by calleaum         ###   ########.fr       */
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
	// std::cout << "\n=== Bureaucrat Tests ===\n";
	// try {
	// 	Bureaucrat hero("Jean-Michel", 1);
	// 	std::cout << hero << std::endl;
	// 	hero.incrementGrade(); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat zero("FailGuy", 0); // Invalid grade
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat loser("Intern", 150);
	// 	std::cout << loser << std::endl;
	// 	loser.decrementGrade(); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }


	// std::cout << "\n=== AForm Signing Tests ===\n";
	// try {
	// 	Bureaucrat signer("Boss", 50);
	// 	ShrubberyCreationForm form("garden");
	// 	std::cout << form << std::endl;
	// 	signer.signForm(form); // Should succeed
	// 	std::cout << form << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat weak("LowRank", 150);
	// 	RobotomyRequestForm robot("Fridge");
	// 	weak.signForm(robot); // Should fail
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// std::cout << "\n=== Execution Tests ===\n";
	// try {
	// 	Bureaucrat exec("ExecGuy", 1);
	// 	PresidentialPardonForm pardon("Ford Prefect");
	// 	exec.signForm(pardon);
	// 	exec.executeForm(pardon); // Should succeed
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat justEnough("RobotTech", 45);
	// 	RobotomyRequestForm r("Bender");
	// 	justEnough.signForm(r);
	// 	for (int i = 0; i < 4; i++)
	// 		justEnough.executeForm(r); // 50% success
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat newbie("Newbie", 150);
	// 	ShrubberyCreationForm shrub("Office");
	// 	newbie.signForm(shrub);
	// 	newbie.executeForm(shrub); // Should fail on exec
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat signer("Signer", 20);
	// 	PresidentialPardonForm unsignedForm("Noob");
	// 	signer.executeForm(unsignedForm); // Not signed
	// } catch (const std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }


	std::cout << "\n=== Intern Tests ===\n";
	Intern intern;

	AForm* f1 = intern.makeForm(SC_FORM_NAME, "tree");
	if (f1)
	{
		Bureaucrat gardener("Gardener", 137);
		gardener.signForm(*f1);
		gardener.executeForm(*f1);
		delete f1;
	}

	AForm* f2 = intern.makeForm(RR_FORM_NAME, "Marvin");
	if (f2)
	{
		Bureaucrat roboguy("Robo", 45);
		roboguy.signForm(*f2);
		roboguy.executeForm(*f2);
		delete f2;
	}

	AForm* f3 = intern.makeForm(PP_FORM_NAME, "Zoidberg");
	if (f3)
	{
		Bureaucrat prez("Prez", 1);
		prez.signForm(*f3);
		prez.executeForm(*f3);
		delete f3;
	}

	AForm* fail = intern.makeForm("FormThatDoesNotExist", "Nobody");
	if (!fail)
		std::cout << "Returned nullptr for unknown form as expected.\n";

	std::cout << "\n✅ All tests completed.\n";
	return 0;
}
