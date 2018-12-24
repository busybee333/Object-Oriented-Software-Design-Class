/**
 * \file Farm.h
 *
 * \author Romi Yun
 *
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#pragma once

#include <vector>
#include "Animal.h"

class CFarm
{
public:
	CFarm();
	virtual ~CFarm();

	void AddAnimal(CAnimal *animal);
	void DisplayInventory();
	void DisplayProfessions();

private:
	/// A list with the inventory of all animals on the farm
	std::vector<CAnimal *> mInventory;
};