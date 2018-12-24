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
#include "Fish.h"

/**
 * Implements a Beta fish
 */
class CFishBeta : public CFish
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

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
 };
