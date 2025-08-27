/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:13 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/27 09:15:55 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PP_FORM_NAME    "Presidential Pardon"

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