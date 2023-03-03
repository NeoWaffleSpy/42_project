#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::SpellBook(SpellBook& copy)
{
	*this = copy;
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it = spellMap.begin();
	while (it != spellMap.end())
	{
		delete it->second;
		it++;
	}
}

SpellBook &SpellBook::operator=(SpellBook &src)
{
	if (this == &src)
		return *this;

	return *this;
}

void SpellBook::learnSpell(ASpell* spell) 
{
	spellMap.insert(std::make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end())
	{
		delete it->second;
		spellMap.erase(spellName);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end())
		return (it->second);
	return NULL;
}