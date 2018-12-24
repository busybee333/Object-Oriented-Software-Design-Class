/**
 * \file FishMagikarp.h
 *
 * \author Romi Yun
 *
 * Class the implements a Magikarp
 */

#pragma once
#include <memory>
#include "Item.h"

/**
 * Implements a Magikarp
 */
class CFishMagikarp : public CItem
{
public:
	/// Constructor
	CFishMagikarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishMagikarp() = delete;

	/// Copy constructor (disabled)
	CFishMagikarp(const CFishMagikarp &) = delete;

	/// Destructor
	virtual ~CFishMagikarp();

	/// Draws a magikarp
	virtual void Draw(Gdiplus::Graphics *graphics);

	/// Test to see if we hit this object with a mouse
	bool HitTest(int x, int y);

private:
	/// Magikarp image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

