/**
 * \file Bear.cpp
 *
 * \author Romi Yun
 */

#include "pch.h"
#include <iostream>
#include "Bear.h"

using namespace std;

/** Constructor.
 */
CBear::CBear()
{
}

/** Destructor.
 */
CBear::~CBear()
{
}

/** Obtain information from the user about this bear.
 *
 * Asks the user for the information that describes a bear.
 */
void CBear::ObtainBearInformation()
{
	cout << endl;
	cout << "Input information about the bear" << endl;

	// Obtain the name. This is easy, since it's just a
	// string.
	cout << "Name: ";
	cin >> mName;

	// Obtain the profession. This is easy, since it's just a
	// string.
	cout << "Profession: ";
	cin >> mProfession;
}

/** Display information about this bear.
 */
void CBear::DisplayAnimal()
{
	cout << "Bear: " << mName << endl;
	cout << "Profession: " << mProfession << endl;
}

/** Display profession of this bear.
 */
void CBear::DisplayProfession()
{
	cout << mName << " the Bear is a " << mProfession << endl;
}