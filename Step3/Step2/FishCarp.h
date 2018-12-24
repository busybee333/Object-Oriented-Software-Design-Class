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
#include "Fish.h"

/**
 * Implements a nemo fish
 */
class CFishCarp : public CFish
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

	/// Tells if this item is a predator
	virtual bool Predator();

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
};

