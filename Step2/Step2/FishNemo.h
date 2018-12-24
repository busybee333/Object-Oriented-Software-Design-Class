/**
 * \file FishNemo.h
 *
 * \author Romi Yun
 *
 * Class the implements a nemo fish
 */

#pragma once
#include <memory>
#include "Item.h"

/**
  * Implements a nemo fish
  */
class CFishNemo : public CItem
{
public:
	/// Constructor
	CFishNemo(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo &) = delete;

	/// Destructor
	virtual ~CFishNemo();

	/// Draws nemo
	virtual void Draw(Gdiplus::Graphics *graphics);

	/// Test to see if we hit this object with a mouse
	bool HitTest(int x, int y);

private:
	/// Nemo image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

