/**
 * \file ViewTimeline.cpp
 *
 * \author Romi Yun
 */


#include "stdafx.h"
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "Picture.h"
#include "Actor.h"
#include "MainFrm.h"
#include <sstream>

using namespace std;
using namespace Gdiplus;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;

/** Constructor */
CViewTimeline::CViewTimeline()
{
	mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
	assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}

/**
 * Force an update of this window when the picture changes.
 */
void CViewTimeline::UpdateObserver()
{
	Invalidate();
	UpdateWindow();
}

/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
	// Get the timeline
	CTimeline *timeline = GetPicture()->GetTimeline();

	// Set the scroll system correctly
	CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
	SetScrollSizes(MM_TEXT, sizeTotal);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

    // TODO: Drawing code goes here
	//Pen pen(Color(0, 128, 0), 1);
	//graphics.DrawRectangle(&pen, 10, 10, 200, 60);

	//FontFamily fontFamily(L"Arial");
	//Gdiplus::Font font(&fontFamily, 16);

	//SolidBrush brush(Color(0, 0, 0));
	//graphics.DrawString(L"Timeline!",  // String to draw
	//	-1,         // String length, -1 means it figures it out 
	//	&font,      // The font to use
	//	PointF(15, 15),   // Where to draw
	//	&brush);    // The brush to draw the text with

	//CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
	//graphics.DrawString(time,  // String to draw
	//	-1,         // String length, -1 means it figures it out 
	//	&font,      // The font to use
	//	PointF(15, 40),   // Where to draw
	//	&brush);    // The brush to draw the text with

	CRect rect;
	GetClientRect(&rect);
	int hit = rect.Height();
	int wid = rect.Width();

	Pen pen(Color(0, 128, 0), 1);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 8);

	//// Draw a line
	Pen tickpen(Color::Black, 1);
	//int x1 = 100;
	//int x2 = 500;
	//int y1 = 100;
	//int y2 = 500;
	//graphics.DrawLine(&tickpen, x1, y1, x2, y2);

	for (int tickNum = 0; tickNum <= timeline->GetNumFrames(); tickNum++)
	{
		// Convert the tick number to seconds in a string
		std::wstringstream str;
		str << tickNum / timeline->GetFrameRate();
		std::wstring wstr = str.str();

		RectF size;
		PointF origin(0.0f, 0.0f);
		graphics.MeasureString(wstr.c_str(), wstr.size(),
			&font, origin, &size);

		bool onSecond = (tickNum % timeline->GetFrameRate()) == 0;

		if (onSecond)
		{
			// Find position of numbers
			auto num_orig_pos = BorderLeft + TickSpacing * tickNum;
			auto num_center_pos = num_orig_pos - size.Width/2 + 1;

			// Draw the numbers
			SolidBrush brush(Color(0, 0, 0));
			graphics.DrawString(wstr.c_str(),  // String to draw
				-1,         // String length, -1 means it figures it out on its own
				&font,      // The font to use
				PointF(num_center_pos, BorderTop + TickLong),   // Where to draw
				&brush);    // The brush to draw the text with

			//graphics.DrawLine(&tickpen, x1, y1, x2, y2);
			
			// Draw long ticks
			graphics.DrawLine(&tickpen, 
				BorderLeft + TickSpacing * tickNum,
				BorderTop, 
				BorderLeft + TickSpacing * tickNum,
				BorderTop + TickLong);
		}
		else
		{
			// Draw short ticks
			graphics.DrawLine(&tickpen, 
				BorderLeft + TickSpacing * tickNum,
				BorderTop, 
				BorderLeft + TickSpacing * tickNum,
				BorderTop + TickShort);
		}
	}

	// Draw the pencil pointer
	graphics.DrawImage(mPointer.get(), 
		BorderLeft + TickSpacing * timeline->GetCurrentTime()*timeline->GetFrameRate() - 4, 
		BorderTop,
		mPointer->GetWidth(), 
		mPointer->GetHeight());


}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle a press of the keyframe set button on the toolbar
*/
void CViewTimeline::OnEditSetkeyframe()
{
	for (auto actor : *GetPicture())
	{
		actor->SetKeyframe();
	}
}


 /** Handle the Edit>Delete Keyframe menu option */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     // TODO: Add your command handler code here
 }


 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	 ON_WM_CREATE()
	 ON_WM_ERASEBKGND()
	 ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
	 ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
	 ON_WM_LBUTTONDOWN()
	 ON_WM_MOUSEMOVE()
 END_MESSAGE_MAP()

 /** Handle a left button mouse press event
 * \param nFlags flags associated with the mouse press
 * \param point The location of the mouse press
 */
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);

	 int x = point.x;

	 // Get the timeline
	 CTimeline *timeline = GetPicture()->GetTimeline();
	 int pointerX = (int)(timeline->GetCurrentTime() *
		 timeline->GetFrameRate() * TickSpacing + BorderLeft);

	 mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
		 x <= pointerX + (int)mPointer->GetWidth() / 2;
	 

	 __super::OnLButtonDown(nFlags, point);
 }

 /** Handle a mouse move event
* \param nFlags flags associated with the mouse press
* \param point The location of the mouse press
*/
 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);

	 // Get the timeline
	 CTimeline *timeline = GetPicture()->GetTimeline();
	 if (mMovingPointer && nFlags & MK_LBUTTON)
	 {
		 auto time = (point.x - BorderLeft) / (double)(timeline->GetFrameRate() * TickSpacing);
		 if (time >= 0 && time <= timeline->GetDuration())
		 {
			 GetPicture()->SetAnimationTime(time);
			 UpdateWindow();
		 }
	 }
	 else
	 {
		 mMovingPointer = false;
	 }
	 __super::OnMouseMove(nFlags, point);
 }
