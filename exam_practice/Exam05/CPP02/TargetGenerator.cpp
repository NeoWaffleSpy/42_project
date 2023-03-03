#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::TargetGenerator(TargetGenerator& copy)
{
	*this = copy;
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it = targetMap.begin();
	while (it != targetMap.end())
	{
		delete it->second;
		it++;
	}
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator &src)
{
	if (this == &src)
		return *this;

	return *this;
}

void TargetGenerator::learnTargetType(ATarget* target) 
{
	targetMap.insert(std::make_pair(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &targetName)
{
	std::map<std::string, ATarget*>::iterator it = targetMap.find(targetName);
	if (it != targetMap.end())
	{
		delete it->second;
		targetMap.erase(targetName);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &targetName)
{
	std::map<std::string, ATarget*>::iterator it = targetMap.find(targetName);
	if (it != targetMap.end())
		return (it->second);
	return NULL;
}