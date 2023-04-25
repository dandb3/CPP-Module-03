#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
: ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
: ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(fragtrap);
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "FragTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;
	std::cout << "FragTrap " << this->name_ << " attacks " \
		<< target << ", causing " << this->damage_ \
		<< " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	unsigned int dealt = (hitPoints_ < amount) ? hitPoints_ : amount;

	this->hitPoints_ -= dealt;
	std::cout << "FragTrap " << this->name_ << "'s HP has decreased " \
		<< dealt << " points, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "FragTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;

	unsigned int healed = (hitPoints_ + amount > 100) ? 100 - hitPoints_ : amount;
	this->hitPoints_ += healed;
	std::cout << "FragTrap " << this->name_ << " heals itself " \
		<< healed << " points of HP, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "FragTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name_ << " says: \"High Five, Guys!\"" << std::endl;
}
