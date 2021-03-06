/**
 * \file TimelineDlg.h
 *
 * \author Romi Yun
 *
 *This class implements the timeline dialogue
 */

#pragma once

class CTimeline;

/** This class implements the timeline dialogue */

class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/**
	* standard constructor	
	* \param pParent The parent
	*/
	CTimelineDlg(CWnd* pParent = nullptr);   
	virtual ~CTimelineDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	/**
	* DDX/DDV support
	* \param pDX idk
	*/	
	virtual void DoDataExchange(CDataExchange* pDX);    


	DECLARE_MESSAGE_MAP()
public:
	/// Number of frames
	int mNumFrames;

	/**
	* Pass a timeline object to this dialog box class.
	* \param timeline The timeline object.
	*/
	void SetTimeline(CTimeline * timeline);
	
	/** Transfer dialog values to the Timeline object
	*/
	void Take();
private:
	/// The timeline we are editing
	CTimeline *mTimeline = nullptr;

	/// Frame rate
	int mFrameRate;
};
