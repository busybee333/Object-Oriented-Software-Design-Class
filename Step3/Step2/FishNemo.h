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
#include "Fish.h"

/**
  * Implements a nemo fish
  */
class CFishNemo : public CFish
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

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
};

