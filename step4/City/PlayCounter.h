/**
 * \file CPlayCounter.h
 *
 * \author Romi Yun
 *
 *  Class that implements a concrete visitor to count plays.
 */

#pragma once
#include "TileVisitor.h"

 /**
 *  A play counter counter
 */
class CPlayCounter :
	public CTileVisitor
{
public:
	/// Constructor
	CPlayCounter();

	/// Destructor
	virtual ~CPlayCounter();

	/// Visitor function
	virtual void VisitMichiganFan(CMichiganFan * fan) override;

};
