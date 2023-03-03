#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string type;

public:
	ATarget();
	ATarget(ATarget& copy);
	ATarget(std::string  type);
	virtual ~ATarget();
	ATarget &operator=(ATarget &src);

	std::string	const	&getType(void) const;

	virtual ATarget*		clone() const = 0;

	void	getHitBySpell(ASpell const &spell) const;
};

#endif