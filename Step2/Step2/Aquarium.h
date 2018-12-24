/**
 * \file Aquarium.h
 *
 * \author Romi Yun
 *
 * Class that represents an aquarium.
 */

#pragma once
#include <memory>
#include <vector>

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
	// Constructor
	CAquarium();

	// Destructor
	virtual ~CAquarium();

	// Draw the aquarium
	void OnDraw(Gdiplus::Graphics *graphics);

	// Add an item to the aquarium
	void Add(std::shared_ptr<CItem> item);

	// Test an x,y click location to see if it clicked on some item in the aquarium.
	std::shared_ptr<CItem> HitTest(int x, int y);

	// Moves item to front of screen
	void MoveToFront(std::shared_ptr<CItem> item);

	// Deletes the item under param item if param is predator
	virtual void KillFish(std::shared_ptr<CItem> item);

	// Deletes item from mItems
	void DeleteItem(std::shared_ptr<CItem> item);

private:
	/// Background image to use
	std::unique_ptr<Gdiplus::Bitmap> mBackground; 

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};
