/**
 * \file ChildView.h
 *
 * \author Romi Yun
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#pragma once
#include "Aquarium.h"

/**
 * The child window our program draws in.
 */

/// Frame duration in milliseconds
const int FrameDuration = 30;

class CChildView : public CWnd
{
public:
	/// Constructor
	CChildView();

	/// Destructor
	virtual ~CChildView();

	/// Called when there is a left mouse button press
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	/// Called when the left mouse button is released
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	/// Called when the mouse is moved
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

	/// Erase the background
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	/// Add a beta fish
	afx_msg void OnAddFishBetaFish();

	/// Add a magikarp
	afx_msg void OnAddFishMagikarp();

	/// Add a nemo
	afx_msg void OnAddFishNemo();

	/// Add a carp
	afx_msg void OnAddFishCarp();

	/// Adds a castle
	afx_msg void OnAddDecorCastle();

	/// Handler for the File/Save As menu option
	afx_msg void OnFileSaveAs();

	/// It loads the aquarium from a file
	afx_msg void OnFileOpen();

	/// Handle timer events
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	/// This function is called before the window is created
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	/// This function is called to draw in the window.
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;

	/// True until the first time we draw
	bool mFirstDraw = true;

	/// Last time we read the timer
	long long mLastTime;

	/// Rate the timer updates
	double mTimeFreq;       
};

