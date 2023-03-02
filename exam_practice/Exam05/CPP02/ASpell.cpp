#include "ASpell.hpp"

ASpell::ASpell()
{}

ASpell::ASpell(ASpell& copy)
{
	*this = copy;
}

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects)
{}

ASpell::~ASpell()
{}

ASpell &ASpell::operator=(ASpell &src)
{
	if (this == &src)
		return *this;

	return *this;
}

std::string	const	&ASpell::getName(void)	const
{
	return (this->name);
}

std::string const	&ASpell::getEffects(void)	const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}