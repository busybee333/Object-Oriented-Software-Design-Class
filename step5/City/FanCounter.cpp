/**
 * \file FanCounter.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "FanCounter.h"
#include "MichiganFan.h"

 /**
  * Constructor
  */
CFanCounter::CFanCounter()
{
}

/**
 * Destructor
 */
CFanCounter::~CFanCounter()
{
}

/** Visit a CPlayCounter object
* \param fan Fan we are visiting */
void CFanCounter::VisitFan(CMichiganFan *fan)
{
	mNumFans++;
}
