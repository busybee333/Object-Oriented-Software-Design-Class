/**
* \file TileCoalmine.h
*
* \author Charles B. Owen
*
* Class that implements a Coal mine tile
*/

#pragma once

#include "Tile.h"
#include "TileVisitor.h"


/**
* A Coal mine tile
*/
class CTileCoalmine : public CTile
{
public:
    CTileCoalmine(CCity *city);

    ///  Default constructor (disabled)
    CTileCoalmine() = delete;

    ///  Copy constructor (disabled)
    CTileCoalmine(const CTileCoalmine &) = delete;

	/// Destructor
    ~CTileCoalmine();

	/// Save this item to an XML node
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitCoalmine(this); }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept1(CTileVisitor *visitor) override { visitor->VisitCoalmine(this); }
};

