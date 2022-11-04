#include <iostream>
#include "application.hpp"
#include "polynomial.hpp"

void print_commands() {
    std::cout << "1 - Enter coefficients\n"
              << "2 - Find roots\n"
              << "3 - Find polynomial value for specific argument\n"
              << "4 - Display polynomial in text form\n"
              << "0 - Exit";
}

Application::Application() {}

int Application::run()
{
    char command = '1';
    Polynomial poly(0, 0, 0);

    while (true)
    {
        print_commands();
        std::cout << '\n';
        std::cin >> command;

        switch (command) {
        case '1':
        {
            number a, b, c;
            std::cout << "Enter a, b and c for ax^2 + bx + c: ";
            if (std::cin >> a >> b >> c)
                poly = Polynomial(a, b, c);
            else {
                std::cout << "Incorrect input\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            break;
        }
        case '2':
        {
            number roots[2];
            switch (poly.findRoots(roots)) {
            case 0:
                std::cout << "Two complex roots exist:";
                // TODO: OUTPUT AND ALSO FIX CALCULATIONS
                break;
            case 1:
                std::cout << "One real root exists: " << roots[0];
                break;
            case 2:
                std::cout << "Two real roots exist: " << roots[0] << "; " << roots[1];
                break;
            default:
                std::cout << "An error has been encountered";
                break;
            }
            std::cout << '\n';
            break;
        }
        case '3':
        {
            number arg;
            std::cout << "Enter a value for the argument x: ";
            if (std::cin >> arg)
                std::cout << "Polynomial value: " << poly.findValue(arg) << '\n';
            else {
                std::cout << "Incorrect input\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            break;
        }
        case '4':
            std::cout << poly << '\n';
            break;
        case '0':
            return 0;
        default:
            std::cout << "Enter a value from 1 to 4 or 0 to exit\n";
            break;
        }
    }
}
