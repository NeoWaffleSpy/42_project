#ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"
#include "Character.hpp"

class Character;
class AMateria;

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	
	Cure& operator=(const Cure& rhs);

	// Destructor
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif