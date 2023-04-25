#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
protected:
	ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int dmg);
	ClapTrap(unsigned int hp, unsigned int ep, unsigned int dmg);

	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int damage_;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& claptrap);
	virtual ~ClapTrap(void);

	ClapTrap& operator=(const ClapTrap& claptrap);

	const std::string& getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getDamage(void) const;
	void setName(std::string name);
	void setDamage(unsigned int damage);

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

};

#endif
