#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::ATarget(ATarget& copy)
{
	*this = copy;
}


ATarget::ATarget(std::string type): type(type)
{}

ATarget::~ATarget()
{}

ATarget &ATarget::operator=(ATarget &src)
{
	if (this == &src)
		return *this;

	return *this;
}

std::string	const	&ATarget::getType(void) const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}