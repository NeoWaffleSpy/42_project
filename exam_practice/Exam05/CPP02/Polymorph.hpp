#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ASpell.hpp"

class Polymorph : public ASpell
{
private:

public:
	Polymorph();
	~Polymorph();

	virtual ASpell*		clone() const;
};

#endif