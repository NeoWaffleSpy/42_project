#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_src_materia[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource& other);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
