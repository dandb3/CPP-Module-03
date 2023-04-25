#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
: ClapTrap("default_clap_name", 100, 50, 30)
, FragTrap()
, ScavTrap()
, name_("default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name", 100, 50, 30)
, FragTrap()
, ScavTrap()
, name_(name)
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
: ClapTrap(diamondtrap)
, FragTrap()
, ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	DiamondTrap::name_ = diamondtrap.getDiaName();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	std::cout << "DiamondTrap copy assignment constructor called" << std::endl;
	ClapTrap::operator=(diamondtrap);
	DiamondTrap::name_ = diamondtrap.getDiaName();
	return *this;
}

const std::string& DiamondTrap::getDiaName(void) const
{
	return DiamondTrap::name_;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	unsigned int dealt = (hitPoints_ < amount) ? hitPoints_ : amount;

	this->hitPoints_ -= dealt;
	std::cout << "DiamondTrap " << DiamondTrap::name_ << "'s HP has decreased " \
		<< dealt << " points, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "DiamondTrap " << DiamondTrap::name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;

	unsigned int healed = (hitPoints_ + amount > 100) ? 100 - hitPoints_ : amount;
	this->hitPoints_ += healed;
	std::cout << "DiamondTrap " << DiamondTrap::name_ << " heals itself " \
		<< healed << " points of HP, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I'm " << DiamondTrap::name_ << " and also " << ClapTrap::name_ << std::endl;
}
