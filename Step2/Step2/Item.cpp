/**
 * \file Item.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "Item.h"
#include "Aquarium.h"

/** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CAquarium *aquarium) : mAquarium(aquarium)
{
}

/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
 *Tells if the item (fish) is a predator
 *\returns false if function not overwritten/predator
 */
bool CItem::Predator()
{
	return false;
}