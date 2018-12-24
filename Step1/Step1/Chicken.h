/**
 * \file Chicken.h
 *
 * \author Romi Yun
 *
 * Class that describes a chicken.
 */

#pragma once

#include <string>
#include "Animal.h"

class CChicken : public CAnimal
{
public:
	CChicken();
	virtual ~CChicken();

	void ObtainChickenInformation();
	void DisplayAnimal();

private:
	//! The chicken's ID
	std::string mId;
};