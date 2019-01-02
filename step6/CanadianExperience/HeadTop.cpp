/**
 * \file HeadTop.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "HeadTop.h"
#include "Timeline.h"
#include "Actor.h"

using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** Constructor
 * \param name The drawable name
 * \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) :
	CImageDrawable(name, filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/** Destructor */
CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/** Draw our item.
 * \param  graphics The graphics context to draw on
 */
void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);

	// Draw eyebrows
	Pen eyebrowPen(Color::Black, 2);

	// Right eyebrow
	auto state = graphics->Save();
	Point p1 = TransformPoint(Point(64, 60));
	Point p2 = TransformPoint(Point(82, 61));
	graphics->DrawLine(&eyebrowPen, p1, p2);
	graphics->Restore(state);

	// Left eyebrow
	state = graphics->Save();
	Point p3 = TransformPoint(Point(30, 61));
	Point p4 = TransformPoint(Point(48, 60));
	graphics->DrawLine(&eyebrowPen, p3, p4);
	graphics->Restore(state);

	// Draw eyes

	SolidBrush brush(Color(0, 0, 0));

	float wid = 15.0f;
	float hit = 20.0f;

	// Right eye
	state = graphics->Save();
	graphics->TranslateTransform((Gdiplus::REAL)(p1.X + 7), (Gdiplus::REAL)(p2.Y + 15));
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
	
	// Left eye
	state = graphics->Save();
	graphics->TranslateTransform((Gdiplus::REAL)(p3.X + 11), (Gdiplus::REAL)(p4.Y + 15));
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}

/**
* Set the actor using this drawable
* \param actor Actor using this drawable
*/
void CHeadTop::SetActor(CActor *actor)
{
	CImageDrawable::SetActor(actor);

	// Set the channel name
	mChannel.SetName(actor->GetName() + L":" + GetName() + L":position");

}

/** Add the channels for this drawable to a timeline
* \param timeline The timeline class.
*/
void CHeadTop::SetTimeline(CTimeline *timeline)
{
	CImageDrawable::SetTimeline(timeline);

	timeline->AddChannel(&mChannel);
}

/** Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
	CImageDrawable::SetKeyframe();

	mChannel.SetKeyframe(GetPosition());
}

/** Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
	CImageDrawable::GetKeyframe();

	if (mChannel.IsValid())
		SetPosition(mChannel.GetPoint());
}