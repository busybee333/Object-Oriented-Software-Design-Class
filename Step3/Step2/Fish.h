/**
 * \file Fish.h
 *
 * \author Romi Yun
 *
 * Base class for a fish
 */

#pragma once
#include "Item.h"
#include "Aquarium.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish &) = delete;

	/// Destructor
	virtual ~CFish();

	/// Handle updates in time of our fish
	void Update(double elapsed);

	/// Sets speedX
	void setSpeedX(double speedX) { mSpeedX = speedX; }

	/// Sets speedY
	void setSpeedY(double speedY) { mSpeedY = speedY; }

protected:
	/// Constructor
	CFish(CAquarium * aquarium, const std::wstring & filename);

	/// Save this item to an XML node
	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
};

