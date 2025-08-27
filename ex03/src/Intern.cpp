/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:38:46 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 15:42:45 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern(void)
{}

Intern  &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

static AForm    *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}


static AForm    *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm    *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm   *Intern::makeForm(const std::string &name, const std::string &target)
{
	const FormMap forms[] = {
		{SC_FORM_NAME, createShrubbery},
		{RR_FORM_NAME, createRobotomy},
		{PP_FORM_NAME, createPardon},
        {NULL, NULL}
	};

	for (size_t i = 0; forms[i].name != NULL; ++i)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cout << "Intern could not create " << name << ": form doesn't exist" << std::endl;
	return NULL;
};