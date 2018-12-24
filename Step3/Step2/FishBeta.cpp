/**
 * \file FishBeta.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include <string>
#include "FishBeta.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 45;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 45;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 30;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 30;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium *aquarium) :
	CFish(aquarium, FishBetaImageName)
{
	setSpeedX(-(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)));
	setSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
	SetMirrorX(TRUE);
}

/**
 * Destructor
 */
CFishBeta::~CFishBeta()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");
	return itemNode;
}