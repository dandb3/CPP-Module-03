#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
: ClapTrap(100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
: ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(scavtrap);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "ScavTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;
	std::cout << "ScavTrap " << this->name_ << " attacks " \
		<< target << ", causing " << this->damage_ \
		<< " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int dealt = (hitPoints_ < amount) ? hitPoints_ : amount;

	this->hitPoints_ -= dealt;
	std::cout << "ScavTrap " << this->name_ << "'s HP has decreased " \
		<< dealt << " points, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "ScavTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;

	unsigned int healed = (hitPoints_ + amount > 100) ? 100 - hitPoints_ : amount;
	this->hitPoints_ += healed;
	std::cout << "ScavTrap " << this->name_ << " heals itself " \
		<< healed << " points of HP, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "ScavTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name_ << " is in Gate keeper mode" << std::endl;
}
