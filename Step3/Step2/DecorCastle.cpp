/**
 * \file DecorCastle.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include <string>
#include "DecorCastle.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/

/// Fish filename 
const wstring DecorCastleImageName = L"images/castle.png";

/**
 * Constructor
 */
CDecorCastle::CDecorCastle(CAquarium *aquarium) :
	CItem(aquarium, DecorCastleImageName)
{
}

/**
 * Destructor
 */
CDecorCastle::~CDecorCastle()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"castle");
	return itemNode;
}