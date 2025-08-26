/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:49:11 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/26 15:10:34 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception");
}

Form::Form(const std::string &name, int signGrade, int execGrade, bool isSigned):   _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(isSigned)
{
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw (Form::GradeTooHighException());
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw (Form::GradeTooLowException());    
}

Form::Form(const Form &other):  _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed)
{
}

Form::~Form(void)
{
}

Form    &Form::operator=(const Form &other)
{
    this->_signed = other._signed;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const Form &form)
{
    stream << "form " << form.getName() << std::endl
    << "is signed : " << form.getSigned() << std::endl
    << "minimum grade to sign : " << form.getSignGrade() << std::endl
    << "minimum grade to execute : " << form.getExecGrade();
    return (stream);
}

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

const std::string   &Form::getName(void) const
{
    return (this->_name);
}

bool                Form::getSigned(void) const
{
    return (this->_signed);
}

int                 Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

int                 Form::getExecGrade(void) const
{
    return (this->_execGrade);
}