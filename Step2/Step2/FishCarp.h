/**
 * \file FishCarp.h
 *
 * \author Romi Yun
 *
 * Class the implements a carp fish
 */

#pragma once
#include <memory>
#include "Item.h"

/**
 * Implements a nemo fish
 */
class CFishCarp : public CItem
{
public:
	/// Constructor
	CFishCarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishCarp() = delete;

	/// Copy constructor (disabled)
	CFishCarp(const CFishCarp &) = delete;

	/// Destructor
	virtual ~CFishCarp();

	/// Draws a carp
	virtual void Draw(Gdiplus::Graphics *graphics);

	/// Test to see if we hit this object with a mouse
	bool HitTest(int x, int y);

	/// Tells if this item is a predator
	virtual bool Predator();

private:
	/// Carp image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

