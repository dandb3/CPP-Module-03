#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ClapTrap b;
	FragTrap d("d");
	FragTrap c("c");
	ScavTrap e("e");
	ScavTrap f("f");
	c = d;
	b.setName("b");
	c.setName("c");
	if (a.getHitPoints() != 0 && a.getEnergyPoints() != 0) {
		a.attack("b");
		b.takeDamage(a.getDamage());
	}
	d.beRepaired(100);
	a.setDamage(85);
	if (a.getHitPoints() != 0 && a.getEnergyPoints() != 0) {
		a.attack("d");
		d.takeDamage(a.getDamage());
	}
	d.beRepaired(10);
	if (d.getHitPoints() != 0 && d.getEnergyPoints() != 0) {
		d.attack("e");
		e.takeDamage(d.getDamage());
	}
	d.highFivesGuys();
	c.highFivesGuys();
	e.guardGate();
	return 0;
}
