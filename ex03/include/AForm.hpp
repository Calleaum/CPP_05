/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:08 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 10:37:38 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _signed;

    protected:
        virtual void        doAction(void) const = 0;
        
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

        class FormNotSignedException : public std::exception
        {
            public:
                const char  *what() const throw();  
        };

        AForm(const std::string &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool isSigned = false);
        AForm(const AForm &other);

        virtual ~AForm(void);

        AForm               &operator=(const AForm &other);

        void                beSigned(const Bureaucrat &bureaucrat);
        void                execute(const Bureaucrat &executor) const;

        const std::string   &getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;
};

std::ostream    &operator<<(std::ostream &stream, const AForm &form);