#include "Warlock.hpp"

Warlock::Warlock()				{}
Warlock::Warlock(Warlock& copy)	{ *this = copy; }

Warlock &Warlock::operator=(Warlock &src)
{
	if (this == &src)
		return *this;

	return *this;
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

std::string const & Warlock::getName()		const	{ return _name;		}
std::string const & Warlock::getTitle()		const	{ return _title;	}
void Warlock::setTitle(std::string const & title)	{ _title = title;	}