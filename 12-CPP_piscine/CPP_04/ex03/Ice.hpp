#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"
#include "Character.hpp"

class Character;
class AMateria;

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	
	Ice& operator=(const Ice& rhs);

	// Destructor
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif