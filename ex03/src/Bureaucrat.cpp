/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:24 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 14:22:24 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade too low exception");
}

Bureaucrat::Bureaucrat(std::string name, int grade):    _name(name), _grade(grade)
{
    if (grade < MAX_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    if (grade > MIN_GRADE)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):    _name(other._name), _grade(other._grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->_grade = other._grade;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade <= MAX_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade >= MIN_GRADE)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade++;
}

void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because his grade is too low." << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because : " << e.what() << std::endl;
    }
}

const std::string   &Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}