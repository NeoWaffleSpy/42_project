#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_src_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		_src_materia[i] = (other._src_materia[i] ? other._src_materia[i]->clone() : NULL);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_src_materia[i])
			delete _src_materia[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (_src_materia[i])
			delete _src_materia[i];
		_src_materia[i] = (rhs._src_materia[i] ? rhs._src_materia[i]->clone() : NULL);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_src_materia[i])
		{
			_src_materia[i] = m;
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_src_materia[i] && _src_materia[i]->getType() == type)
			return _src_materia[i]->clone();
	return NULL;
}