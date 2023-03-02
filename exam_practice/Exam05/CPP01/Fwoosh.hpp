#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ASpell.hpp"

class Fwoosh : public ASpell
{
private:

public:
	Fwoosh();
	~Fwoosh();

	virtual ASpell*		clone() const;
};

#endif