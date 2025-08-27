/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:31 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 14:22:40 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):    AForm(RR_FORM_NAME, 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->_target = other._target;
    return (*this);
}

void    RobotomyRequestForm::doAction() const
{
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomy has failed" << std::endl;
}