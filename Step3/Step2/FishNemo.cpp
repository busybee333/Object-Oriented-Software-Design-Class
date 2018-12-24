/**
 * \file FishNemo.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include <string>
#include "FishNemo.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishNemoImageName = L"images/nemo.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 60;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 60;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 45;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 45;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishNemo::CFishNemo(CAquarium *aquarium) :
	CFish(aquarium, FishNemoImageName)
{
	setSpeedX(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
	setSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Destructor
 */
CFishNemo::~CFishNemo()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishNemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"nemo");
	return itemNode;
}