#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ASpell.hpp"

class Fireball : public ASpell
{
private:

public:
	Fireball();
	~Fireball();

	virtual ASpell*		clone() const;
};

#endif