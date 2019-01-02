/**
 * \file PolyDrawable.h
 *
 * \author Romi Yun
 *
 * A drawable based on polygon images
 */

#pragma once

#include "Drawable.h"
#include <vector>

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class CPolyDrawable : public CDrawable
{
public:
	/** Constructor
	 * \param name The drawable name */
	CPolyDrawable(const std::wstring &name);

	/** Default constructor disabled */
	CPolyDrawable() = delete;

	/** Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;

	/** Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

	/// Destructor
	virtual ~CPolyDrawable();

	/** Get the color
	 * \returns The color*/
	Gdiplus::Color GetColor() { return mColor; }

	/** Set the color
	 * \param color The new color*/
	void SetColor(Gdiplus::Color color) { mColor = color; }

	/** Draw our item.
	 * \param  graphics The graphics context to draw on
	 */
	void Draw(Gdiplus::Graphics *graphics) override;

	/**
	 * Test to see if we clicked on the image.
	 * \param pos Position to test
	 * \returns True if clicked on
	 */
	bool HitTest(Gdiplus::Point pos) override;

	/**
	 * Add a point
	 * \param point The point to add
	 */
	void AddPoint(Gdiplus::Point point);

private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

