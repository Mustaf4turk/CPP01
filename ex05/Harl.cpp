#include "Harl.hpp"

#include <iostream>
#include <algorithm>

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my"
              << " 7XL-double-cheese-triple-pickle-special-ketchup burger."
              << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money."
              << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."
              << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl << std::endl;
}

void Harl::complain(const std::string &level)
{
    typedef void (Harl::*Handler)(void);

    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Handler handlers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    const std::size_t count = sizeof(levels) / sizeof(levels[0]);
    const std::size_t idx = std::find(levels, levels + count, level) - levels;

    switch (idx)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            (this->*handlers[idx])();
            break;
        default:
            break;
    }
}
