#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ClapTrap b;
	ScavTrap d("d");
	ScavTrap c("c");
	c = d;
	b.setName("b");
	c.setName("c");
	if (a.getHitPoints() != 0 && a.getEnergyPoints() != 0) {
		a.attack("b");
		b.takeDamage(a.getDamage());
	}
	d.beRepaired(100);
	a.setDamage(115);
	if (a.getHitPoints() != 0 && a.getEnergyPoints() != 0) {
		a.attack("d");
		d.takeDamage(a.getDamage());
	}
	d.beRepaired(10);
	if (d.getHitPoints() != 0 && d.getEnergyPoints() != 0) {
		d.attack("c");
		c.takeDamage(d.getDamage());
	}
	d.attack("c");
	return 0;
}
