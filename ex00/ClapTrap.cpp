#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: name_("default")
, hitPoints_(10)
, energyPoints_(10)
, damage_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: name_(name)
, hitPoints_(10)
, energyPoints_(10)
, damage_(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name_ = claptrap.getName();
	this->hitPoints_ = claptrap.getHitPoints();
	this->energyPoints_ = claptrap.getEnergyPoints();
	this->damage_ = claptrap.getDamage();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name_ = claptrap.getName();
	this->hitPoints_ = claptrap.getHitPoints();
	this->energyPoints_ = claptrap.getEnergyPoints();
	this->damage_ = claptrap.getDamage();
	return *this;
}

const std::string& ClapTrap::getName(void) const
{
	return this->name_;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->hitPoints_;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return this->energyPoints_;
}

unsigned int ClapTrap::getDamage(void) const
{
	return this->damage_;
}

void ClapTrap::setName(std::string name)
{
	this->name_ = name;
}

void ClapTrap::setDamage(unsigned int damage)
{
	this->damage_ = damage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "ClapTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;
	std::cout << "ClapTrap " << this->name_ << " attacks " \
		<< target << ", causing " << this->damage_ \
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int dealt = (hitPoints_ < amount) ? hitPoints_ : amount;

	this->hitPoints_ -= dealt;
	std::cout << "ClapTrap " << this->name_ << "'s HP has decreased " \
		<< dealt << " points, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0) {
		std::cout << "ClapTrap " << this->name_ << " is inactive" << std::endl;
		return;
	}
	--this->energyPoints_;

	unsigned int healed = (hitPoints_ + amount > 10) ? 10 - hitPoints_ : amount;
	this->hitPoints_ += healed;
	std::cout << "ClapTrap " << this->name_ << " heals itself " \
		<< healed << " points of HP, and its HP is now " << this->hitPoints_ \
		<< "!" << std::endl;
}
