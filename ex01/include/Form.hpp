/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:36:10 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/26 15:07:16 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _signed;

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        Form(const std::string &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool isSigned = false);
        Form(const Form &other);

        ~Form();

        Form    &operator=(const Form &other);

        void    beSigned(const Bureaucrat &bureaucrat);

        const std::string   &getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;
};

std::ostream    &operator<<(std::ostream &stream, const Form &form);