/**
 * \file BuildingCounter.h
 *
 * \author Romi Yun
 *
 *  Class that implements a concrete visitor to count buildings.
 */

#pragma once
#include "TileVisitor.h"

 /**
 *  A Building counter
 */
class CBuildingCounter :
	public CTileVisitor
{
public:
	/// Constructor
	CBuildingCounter();

	/// Destructor
	virtual ~CBuildingCounter();

	/// Visit a CTileBuilding object
	void VisitBuilding(CTileBuilding * building);

	/** Get the number of buildings
	 * \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

