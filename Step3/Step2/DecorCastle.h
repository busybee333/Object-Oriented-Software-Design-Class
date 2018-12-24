/**
 * \file DecorCastle.h
 *
 * \author Romi Yun
 *
 * Class the implements a castle decoration
 */

#pragma once
#include <memory>
#include "Item.h"

 /**
  * Implements a castle decoration
  */
class CDecorCastle : public CItem
{
public:
	/// Constructor
	CDecorCastle(CAquarium *aquarium);

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle &) = delete;

	/// Destructor
	virtual ~CDecorCastle();
	
	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
};

