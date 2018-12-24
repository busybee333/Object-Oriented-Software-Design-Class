/**
 * \file Bear.h
 *
 * \author Romi Yun
 *
 * Class that describes a Bear.
 *
 * This class holds the bear's name and profession.
 */

#pragma once

#include <string>
#include "Animal.h"

class CBear : public CAnimal
{
public:
	CBear();
	virtual ~CBear();

	void ObtainBearInformation();
	void DisplayAnimal();
	void DisplayProfession();

private:
	/// The bear's name
	std::string mName;

	/// The bear's profession
	std::string mProfession;
};

