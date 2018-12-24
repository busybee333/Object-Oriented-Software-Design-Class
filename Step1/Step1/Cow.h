/**
 * \file Cow.h
 *
 * \author Romi Yun
 *
 * Class that describes a Cow.
 *
 * This class holds the cow's name, type, and 
 * milk production.
 */

#pragma once

#include <string>
#include "Animal.h"

class CCow : public CAnimal
{
public:
	CCow();
	virtual ~CCow();

	/// The types of cow we can have on our farm
	enum Type { Bull, BeefCow, MilkCow };

	std::string GetName() const { return mName; }
	void setName(const std::string &name) { mName = name; }
	void ObtainCowInformation();
	void DisplayAnimal();
	void DisplayProfession();

private:
	/// The cow's name
	std::string mName;

	/// The type of code: Bull, BeefCow, or MilkCow
	Type mType = MilkCow;

	/// The milk production for a cow in gallons per day
	double mMilkProduction = 0;
};

