/**
 * \file Animal.h
 *
 * \author Romi Yun
 *
 * Declaration of the CAnimal class.
 */

#pragma once

class CAnimal
{
public:
	CAnimal();
	virtual ~CAnimal();

	/** Display an animal. */
	virtual void DisplayAnimal() {}

	/** Display an animal's name and profession. */
	virtual void DisplayProfession() {}
};

