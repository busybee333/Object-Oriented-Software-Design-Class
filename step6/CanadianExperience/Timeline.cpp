/**
 * \file Timeline.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "Timeline.h"
#include "AnimChannel.h"


CTimeline::CTimeline()
{
}


CTimeline::~CTimeline()
{
}

/** Adds channel
* \param channel Channel to be added
*/
void CTimeline::AddChannel(CAnimChannel *channel)
{
	mChannels.push_back(channel);
	channel->SetTimeline(this);
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
*
* \param t Time to be set
*/
void CTimeline::SetCurrentTime(double t)
{
	// Set the time
	mCurrentTime = t;

	for (auto channel : mChannels)
	{
		channel->SetFrame(GetCurrentFrame());
	}
}
