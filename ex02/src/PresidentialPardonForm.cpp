/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:29 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 14:22:36 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):  AForm(PP_FORM_NAME, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):    AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->_target = other._target;
    return (*this);
}

void    PresidentialPardonForm::doAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}