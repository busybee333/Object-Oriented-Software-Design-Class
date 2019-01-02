/**
 * \file AnimChannelPoint.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "AnimChannelPoint.h"
#include "Timeline.h"

using namespace std;
using namespace Gdiplus;

CAnimChannelPoint::CAnimChannelPoint()
{
}


CAnimChannelPoint::~CAnimChannelPoint()
{
}

/**
 * Compute a point that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframePoint. This function does the
 * tweening.
 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
 * interpolate between.
 */
void CAnimChannelPoint::Tween(double t)
{
	Point kf1 = mKeyframe1->GetPoint();
	Point kf2 = mKeyframe2->GetPoint();

	int x = int((kf2.X - kf1.X)*t
		+ kf1.X);

	int y = int((kf2.Y - kf1.Y)*t
		+ kf1.Y);

	mPoint = Point(x, y);
}

/**
* Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param point Point for the keyframe.
*/
void CAnimChannelPoint::SetKeyframe(Gdiplus::Point point)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	shared_ptr<KeyframePoint> keyframe =
		make_shared<KeyframePoint>(this, point);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}