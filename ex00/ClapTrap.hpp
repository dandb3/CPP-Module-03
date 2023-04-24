#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
private:
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int damage_;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& claptrap);
	~ClapTrap(void);

	ClapTrap& operator=(const ClapTrap& claptrap);

	const std::string& getName(void) const;
	const unsigned int getHitPoints(void) const;
	const unsigned int getEnergyPoints(void) const;
	const unsigned int getDamage(void) const;
	void setName(std::string name);
	void setDamage(unsigned int damage);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
