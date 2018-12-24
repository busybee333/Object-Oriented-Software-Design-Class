/**
 * \file Item.h
 *
 * \author Romi Yun
 *
 * Base class for any item in our aquarium.
 */

#pragma once
#include <memory>
#include <string>
#include "XmlNode.h"

class CAquarium;

/**
 * Base class for any item in our aquarium.
 */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	/// Destructor
	virtual ~CItem();

	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	//! Draw this item
	//! \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics *graphics);

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Load the attributes for an item node.
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/** Test this item to see if it has been clicked on
	 * \param x X location on the aquarium to test
	 * \param y Y location on the aquarium to test
	 * \return true if clicked on */
	bool HitTest(int x, int y);

	/// Tells whether or not an item is a predator
	virtual bool Predator();

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium *GetAquarium() { return mAquarium; }

	/// Set the mirror status for x values (left/right)
	/// \param m New mirror flag
	void SetMirrorX(bool m) { mMirror = m; }

	/// Gets item's width
	double GetWidth() { return mItemImage->GetWidth(); }

	/// Get item's height
	double GetHeight() { return mItemImage->GetHeight(); }

protected:
	/// Constructor
	CItem(CAquarium *aquarium, const std::wstring &filename);

private:
	/// The aquarium this item is contained in
	CAquarium   *mAquarium;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item

	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// True mirrors the item image
	bool mMirror = false;   
};
