/**
 * \file FishMagikarp.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include <string>
#include "FishMagikarp.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishMagikarpImageName = L"images/magikarp.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 15;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 15;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 0;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 0;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishMagikarp::CFishMagikarp(CAquarium *aquarium) :
	CFish(aquarium, FishMagikarpImageName)
{
	setSpeedX(-(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)));
	setSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
	SetMirrorX(TRUE);
}

/**
 * Destructor
 */
CFishMagikarp::~CFishMagikarp()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"magikarp");
	return itemNode;
}