#include "Cure.hpp"

Cure::Cure() : AMateria("cure") { }
Cure::Cure(const Cure& other) : AMateria(other) { }
Cure::~Cure() { }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

Cure& Cure::operator=(const Cure& rhs)
{
	this->_type = rhs._type;
	return *this;
}

