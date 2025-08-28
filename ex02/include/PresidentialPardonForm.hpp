/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:13 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 10:41:18 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PP_NAME    "Presidential Pardon"

class PresidentialPardonForm : public AForm
{
    protected:
        std::string _target;
        
        void    doAction(void) const;

    public:
        PresidentialPardonForm(const std::string &target = "nobody");
        PresidentialPardonForm(const PresidentialPardonForm &other);

        ~PresidentialPardonForm(void);

        PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);

};