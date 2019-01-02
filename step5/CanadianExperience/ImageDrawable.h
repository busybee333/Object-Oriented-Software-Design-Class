/**
 * \file ImageDrawable.h
 *
 * \author Romi Yun
 *
 * Abstract class for drawing images
 */

#pragma once
#include "Drawable.h"

#include <memory>

using namespace Gdiplus;
using namespace std;

/**
 * Abstract base class for drawable images of our picture
 */

class CImageDrawable :
	public CDrawable
{
public:
	/** Constructor
	 * \param name The drawable name
	 * \param filename The filename for the image */
	CImageDrawable(const std::wstring &name, const std::wstring &filename);

	/// Destructor
	virtual ~CImageDrawable();

	/** Default constructor disabled */
	CImageDrawable() = delete;

	/** Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;

	/** Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;

	/** Draw our item.
	 * \param  graphics The graphics context to draw on
	 */
	void Draw(Gdiplus::Graphics * graphics);

	/**
	 * Test to see if we clicked on the image.
	 * \param pos Position to test
	 * \returns True if clicked on
	 */
	bool HitTest(Gdiplus::Point pos);

	/** Get the canter
	 * \returns The center position*/
	Gdiplus::Point GetCenter() { return mCenter; }

	/** Set the center
	 * \param center The new center position*/
	void SetCenter(Gdiplus::Point center) { mCenter = center; }

protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;

private:
	/// The center position
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

