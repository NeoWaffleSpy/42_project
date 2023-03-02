#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { }
Ice::Ice(const Ice& other) : AMateria(other) { }
Ice::~Ice() { }

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

Ice& Ice::operator=(const Ice& rhs)
{
	this->_type = rhs._type;
	return *this;
}

