#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class Warlock
{
private:
	std::string	_name;
	std::string	_title;
	SpellBook necronomicon;
	
	Warlock();
	Warlock(Warlock& copy);
	Warlock &operator=(Warlock &src);

public:
	Warlock(std::string name, std::string title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;
	void setTitle(std::string const & title);
	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget& target);
};

#endif