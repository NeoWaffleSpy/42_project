#include "Character.hpp"

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(Character& npc): _name(npc._name)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = (npc._materia[i] ? npc._materia[i]->clone() : NULL);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

Character& Character::operator=(const Character& rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
		_materia[i] = (rhs._materia[i] ? rhs._materia[i]->clone() : NULL);
	}
	return *this;
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (_materia[idx])
	{
		delete _materia[idx];
		_materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (_materia[idx])
		_materia[idx]->use(target);
}