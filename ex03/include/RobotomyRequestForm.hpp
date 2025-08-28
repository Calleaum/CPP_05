/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:15 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 10:24:34 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "AForm.hpp"

#define RR_NAME    "Robotomy Request"

class RobotomyRequestForm: public AForm
{
    protected:
        std::string _target;

        void    doAction(void) const;

    public:
        RobotomyRequestForm(const std::string &target = "nobody");
        RobotomyRequestForm(const RobotomyRequestForm &other);

        ~RobotomyRequestForm(void);

        RobotomyRequestForm  &operator=(const RobotomyRequestForm &other);
};