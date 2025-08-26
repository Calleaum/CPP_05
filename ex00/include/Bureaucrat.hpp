/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:15:50 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/26 11:38:34 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    class GradeTooHighException : public std::exception
    {
        public:
            char const  *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            char const  *what() const throw();
    };

    protected:
        const std::string   _name;
        int                 _grade;

    public:

        Bureaucrat(std::string name = "unnamed", int grade = MIN_GRADE);
        Bureaucrat(const Bureaucrat &other);

        ~Bureaucrat(void);

        Bureaucrat          &operator=(const Bureaucrat &other);
		
        void                incrementGrade(void);
        void                decrementGrade(void);
        const std::string   &getName(void) const;
        int                 getGrade(void) const;
        
};

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);