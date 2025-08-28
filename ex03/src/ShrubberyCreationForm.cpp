/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:34 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 10:25:18 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):    AForm(SC_NAME, 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):   AForm(other), _target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->_target = other._target;
    return (*this);
}

void    ShrubberyCreationForm::doAction() const
{
    std::string     filename(this->_target + "_shrubbery");
    std::ofstream   file;

    file.open(filename.c_str());
    if (!file.is_open())
        std::cerr << "shrubbery: " << filename << ": " << std::strerror(errno) << std::endl;
    else
        file << ASCII_TREE;
}