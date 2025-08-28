/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:18:09 by calleaum          #+#    #+#             */
/*   Updated: 2025/08/28 09:27:17 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== Test 1: Create and manipulate a Bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat Oui("Oui", 42);
        std::cout << "Created: " << Oui << std::endl;

        std::cout << "-> Increment grade" << std::endl;
        Oui.incrementGrade();
        std::cout << "Result: " << Oui << std::endl;

        std::cout << "-> Decrement grade" << std::endl;
        Oui.decrementGrade();
        std::cout << "Result: " << Oui << std::endl;

        std::cout << "-> Copy Oui into Non" << std::endl;
        Bureaucrat Non = Oui;
        std::cout << "Non: " << Non << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 2: Going above the max grade ===" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        std::cout << "Created: " << top << std::endl;
        std::cout << "-> Increment grade (should fail)" << std::endl;
        top.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 3: Going below the min grade ===" << std::endl;
    try
    {
        Bureaucrat low("Low", 150);
        std::cout << "Created: " << low << std::endl;
        std::cout << "-> Decrement grade (should fail)" << std::endl;
        low.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 4: Invalid grade at construction ===" << std::endl;
    try
    {
        Bureaucrat invalidHigh("InvalidHigh", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat invalidLow("InvalidLow", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}

