#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <map>
# include "ATarget.hpp"
# include "Dummy.hpp"
# include "BrickWall.hpp"

class TargetGenerator
{
private:
	std::map<std::string, ATarget*> targetMap;

	TargetGenerator(TargetGenerator& copy);
	TargetGenerator &operator=(TargetGenerator &src);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const &targetName);
	ATarget* createTarget(std::string const &targetName);
};

#endif