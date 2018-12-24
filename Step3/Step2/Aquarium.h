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
#include "XmlNode.h"

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
	/// Constructor
	CAquarium();

	/// Destructor
	virtual ~CAquarium();

	/// Draw the aquarium
	void OnDraw(Gdiplus::Graphics *graphics);

	/// Add an item to the aquarium
	void Add(std::shared_ptr<CItem> item);

	/// Test an x,y click location to see if it clicked on some item in the aquarium.
	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Moves item to front of screen
	void MoveToFront(std::shared_ptr<CItem> item);

	/// Deletes the item under param item if param is predator
	virtual void KillFish(std::shared_ptr<CItem> item);

	/// Deletes item from mItems
	void DeleteItem(std::shared_ptr<CItem> item);

	/// Save the aquarium as a .aqua XML file
	void Save(const std::wstring & filename);

	///Load the aquarium from a .aqua XML file.
	void Load(const std::wstring & filename);

	/// Clear the aquarium data.
	void Clear();

	/// Handle an item node.
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
	
	/// Handle updates for animation
	void Update(double elapsed);

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	/// Background image to use
	std::unique_ptr<Gdiplus::Bitmap> mBackground; 

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};
