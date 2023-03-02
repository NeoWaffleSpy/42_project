#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <map>
# include "ASpell.hpp"

class SpellBook
{
private:
	std::map<std::string, ASpell*> spellMap;

	SpellBook(SpellBook& copy);
	SpellBook &operator=(SpellBook &src);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const &spellName);
	ASpell* createSpell(std::string const &spellName);
};

#endif