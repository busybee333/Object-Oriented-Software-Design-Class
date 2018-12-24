/**
 * \file FanCounter.h
 *
 * \author Romi Yun
 *
 *  Class that implements a concrete visitor to count plays.
 */

#pragma once
#include "TileVisitor.h"

 /**
 *  A fan counter counter
 */
class CFanCounter :
	public CTileVisitor
{
public:
	/// Constructor
	CFanCounter();

	/// Destructor
	virtual ~CFanCounter();

	/// Visitor function
	virtual void VisitFan(CMichiganFan * fan) override;

	/** Get the number of fans
	 * \returns Number of fans */
	int GetNumFans() const { return mNumFans; }

private:
	/// Number of fans
	int mNumFans = 0;
};