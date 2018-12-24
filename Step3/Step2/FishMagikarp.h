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
#include "Fish.h"

/**
 * Implements a Magikarp
 */
class CFishMagikarp : public CFish
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

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
};

