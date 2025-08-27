/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:39:18 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 15:42:55 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    protected:
        typedef AForm*  (*FormFactory)(const std::string &target);

        struct FormMap {
            const char *name;
            FormFactory create;
        };
        
    public:
        Intern(void);
        Intern(const Intern &other);

        ~Intern(void);

        Intern  &operator=(const Intern &other);

        static AForm    *makeForm(const std::string &name, const std::string &target);
};