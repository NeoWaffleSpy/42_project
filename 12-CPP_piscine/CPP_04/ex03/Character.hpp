#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Character : public ICharacter
{
public:
	Character(std::string name);
	Character(Character& npc);
	~Character();

	Character& operator=(const Character& rhs);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
protected:
	std::string	_name;
	AMateria*	_materia[4];
};

#endif