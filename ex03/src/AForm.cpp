/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:21 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 14:22:18 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception");
}

const char  *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed exception");
}

AForm::AForm(const std::string &name, int signGrade, int execGrade, bool isSigned):   _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(isSigned)
{
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw (AForm::GradeTooHighException());
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw (AForm::GradeTooLowException());    
}

AForm::AForm(const AForm &other):  _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed)
{
}

AForm::~AForm()
{
}

AForm    &AForm::operator=(const AForm &other)
{
    this->_signed = other._signed;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const AForm &form)
{
    stream << "form " << form.getName() << std::endl
    << "is signed : " << form.getSigned() << std::endl
    << "minimum grade to sign : " << form.getSignGrade() << std::endl
    << "minimum grade to execute : " << form.getExecGrade();
    return (stream);
}

void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void    AForm::execute(const Bureaucrat &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    this->doAction();
}

const std::string   &AForm::getName() const
{
    return (this->_name);
}

bool                AForm::getSigned() const
{
    return (this->_signed);
}

int                 AForm::getSignGrade() const
{
    return (this->_signGrade);
}

int                 AForm::getExecGrade() const
{
    return (this->_execGrade);
}