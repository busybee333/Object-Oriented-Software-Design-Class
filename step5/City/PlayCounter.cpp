/**
 * \file PlayCounter.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "PlayCounter.h"
#include "MichiganFan.h"

 /**
  * Constructor
  */
CPlayCounter::CPlayCounter()
{
}

/**
 * Destructor
 */
CPlayCounter::~CPlayCounter()
{
}

/** Visit a CPlayCounter object
* \param fan Fan we are visiting */
void CPlayCounter::VisitMichiganFan(CMichiganFan *fan)
{
	if (fan->GetRunAway() == true)
	{
		fan->ChangeState();
		fan->SetToThree();
	}
	else if (fan->GetNewSeason() == true)
	{
		fan->ResetPosition();
	}
	else {
		fan->IncrementPlay();
		fan->ChangeState();
	}
}
