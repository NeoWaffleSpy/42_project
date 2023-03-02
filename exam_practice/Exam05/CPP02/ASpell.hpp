#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string name;
	std::string effects;

public:
	ASpell();
	ASpell(ASpell& copy);
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();
	ASpell &operator=(ASpell &src);

	std::string	const	&getName(void)	const;
	std::string	const	&getEffects(void)	const;

	virtual ASpell*		clone() const = 0;

	void	launch(ATarget const &target) const;
};

#endif