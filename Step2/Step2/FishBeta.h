/**
 * \file FishBeta.h
 *
 * \author Romi Yun
 *
 * Class the implements a Beta fish
 */

#pragma once
#include <memory>
#include "Item.h"

/**
 * Implements a Beta fish
 */
class CFishBeta : public CItem
{
public:
	/// Constructor
	CFishBeta(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;

	/// Destructor
	virtual ~CFishBeta();

	/// Draws beta fish
	virtual void Draw(Gdiplus::Graphics *graphics);

	/// Test to see if we hit this object with a mouse
	bool HitTest(int x, int y);

private:
	/// Beta fish image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};
