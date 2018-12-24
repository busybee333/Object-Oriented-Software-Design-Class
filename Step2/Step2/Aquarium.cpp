/**
 * \file Aquarium.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include <algorithm>

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}

	// Loop over the rows of items we will create
	// We use the constant here to indicate how many rows we want to create
	const int NumRows = 5;
	for (int r = 0; r < NumRows; r++)
	{
		// There is a row every 64 pixels and we start 150 pixels from the top
		int y = r * 64 + 150;

		// The number of columns starts at 1 and increases as we 
		// go down in the Y direction until half way, then decreases.
		// If we had 5 rows, the number of columns for each row
		// will be:  1 2 3 2 1
		int numCols = NumRows / 2 - abs(r - NumRows / 2) + 1;

		// We center the columns on the screen
		int xStart = 512 - (numCols - 1) * 128;

		for (int c = 0; c < numCols; c++)
		{
			// Each column is 128 pixels to the right.
			int x = c * 256 + xStart;

			// Create a new fish.
			// This creates a shared pointer pointing at this fish
			shared_ptr<CItem> fish(new CFishBeta(this));

			// Set the location
			fish->SetLocation(x, y);

			// Add to the list of fish.
			mItems.push_back(fish);
		}
	}
}

/**
 * Destructor
 */
CAquarium::~CAquarium()
{
}

/** Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics *graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Move an item to the front of screen
 * \param item Item to bring to front
 */
void CAquarium::MoveToFront(std::shared_ptr<CItem> item)
{	
	// Deletes item from mItems
	this->DeleteItem(item); 

	// Adds item to the end of mItems to move to front
	this->Add(item);
}

/**
 * When item is a predator and dragged in front
 * of another item, kills the other item
 * \param item Possible predator
 */
void CAquarium::KillFish(std::shared_ptr<CItem> item)
{
	// break flag
	bool flag = false;

	// if the item is a predator
	if (item->Predator()) 
	{
		for (auto i = mItems.rbegin(); i != mItems.rend(); i++) 
		{
			// if item is not current item
			if (*i != item) 
			{
				// if the X's and Y's are the same
				if ((*i)->HitTest(item->GetX(), item->GetY())) 
				{
					// delete prey
					this->DeleteItem(*i); 

					// set flag to break
					flag = true; 
				}
			}
			//if something has been deleted, break
			if (flag == true) 
			{
				break;
			}
		}
	}
}

/**
 * Deletes item from mItems
 * \param item Item to delete
 */
void CAquarium::DeleteItem(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
}