#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ClapTrap b;
	FragTrap d("d");
	FragTrap c("c");
	ScavTrap e("e");
	ScavTrap f("f");
	DiamondTrap g("g");
	DiamondTrap h("h");
	c = d;
	f = g;
	b.setName("b");
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
	if (h.getHitPoints() != 0 && h.getEnergyPoints() != 0) {
		h.attack("g");
		g.takeDamage(h.getDamage());
	}
	h.whoAmI();
	return 0;
}
