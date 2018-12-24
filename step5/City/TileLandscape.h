/**
* \file TileLandscape.h
*
* \author Charles B. Owen
*
*  Class that implements a Landscape tile
*/

#pragma once

#include "Tile.h"
#include "TileVisitor.h"


/**
*  A Landscape tile
*/
class CTileLandscape : public CTile
{
public:
    CTileLandscape(CCity *city);

    ///  Default constructor (disabled)
    CTileLandscape() = delete;

    ///  Copy constructor (disabled)
    CTileLandscape(const CTileLandscape &) = delete;

	/// Destructor
    ~CTileLandscape();

	/// Save this item to an XML node
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/// Load the attributes for an item node.
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitLandscape(this); }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept1(CTileVisitor *visitor) override { visitor->VisitLandscape(this); }
};

