/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:18:09 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 09:36:36 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== Test 1: Valid Form creation ===" << std::endl;
    Form ouiForm("OuiForm", 50, 25, false);
    std::cout << ouiForm << std::endl;

    std::cout << "\n=== Test 2: Bureaucrat Oui signs the form (success) ===" << std::endl;
    Bureaucrat Oui("Oui", 30);
    std::cout << ouiForm << std::endl;

    std::cout << "\n=== Test 3: Bureaucrat Oui tries to sign an already signed form ===" << std::endl;

    std::cout << "\n=== Test 4: Bureaucrat Non too low to sign ===" << std::endl;
    Bureaucrat Non("Non", 60);
    Form nonForm("NonForm", 50, 20, false);
    std::cout << nonForm << std::endl;

    std::cout << "\n=== Test 5: Invalid Form creation (sign grade too high) ===" << std::endl;
    try
    {
        Form illegalForm("IllegalForm", 0, 20, false);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Invalid Form creation (exec grade too low) ===" << std::endl;
    try
    {
        Form illegalForm("IllegalForm", 50, 151, false);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Copy constructor and assignment operator ===" << std::endl;
    Form original("OriginalForm", 42, 24, true);

    Form copy = original;
    std::cout << "Copy (via copy constructor):\n" << copy << std::endl;

    Form assigned("AssignedForm", 100, 100, false);
    assigned = original;
    std::cout << "Assigned (via operator=):\n" << assigned << std::endl;

    return 0;
}

