/**
 * \file HeadTop.h
 *
 * \author Romi Yun
 *
 * Class to draw top of head
 */

#pragma once
#include "ImageDrawable.h"

 /**
  * Class for drawing top of head
  */

class CHeadTop :
	public CImageDrawable
{
public:
	/** Constructor
	 * \param name The drawable name
	 * \param filename The filename for the image */
	CHeadTop(const std::wstring &name, const std::wstring &filename);

	/// Destructor
	virtual ~CHeadTop();

	/** Default constructor disabled */
	CHeadTop() = delete;

	/** Copy constructor disabled */
	CHeadTop(const CHeadTop &) = delete;

	/** Draw our item.
	 * \param  graphics The graphics context to draw on
	 */
	void Draw(Gdiplus::Graphics *graphics);

	/**
	 * Tells if item is movable
	 * \returns True
	 */
	bool IsMovable() override { return true; }

	/** Transform a point from a location on the bitmap to
	*  a location on the screen.
	* \param  p Point to transform
	* \returns Transformed point
	*/
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
};

