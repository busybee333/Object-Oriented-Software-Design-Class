/**
 * \file ViewEdit.h
 *
 * \author Romi Yun
 *
 * View class the provides a window for editing our pixture
 */

#pragma once

#include "PictureObserver.h"

class CMainFrame;
class CActor;
class CDrawable;

/** View class the provides a window for editing our pixture */
class CViewEdit : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewEdit)

public:
	/// Constructor
	CViewEdit();           // protected constructor used by dynamic creation
	
	/// Destructor
	virtual ~CViewEdit();

	/**
	* Force an update of this window when the picture changes.
	*/
	virtual void UpdateObserver() override;

	/**
	 * Set the mainFrame pointer
	 * \param mainFrame Pointer to the CMainFrame window
	 */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;

	/// The selected actor
	std::shared_ptr<CActor> mSelectedActor;

	/// The selected drawable
	std::shared_ptr<CDrawable> mSelectedDrawable;

	/// The last mouse position
	Gdiplus::Point mLastMouse = Gdiplus::Point(0, 0);
};


