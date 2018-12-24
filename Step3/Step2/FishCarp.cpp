/**
 * \file FishCarp.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include <string>
#include "FishCarp.h"
#include "Aquarium.h"
#include "FishBeta.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishCarpImageName = L"images/carp.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 30;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 30;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 15;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 15;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishCarp::CFishCarp(CAquarium *aquarium) :
	CFish(aquarium, FishCarpImageName)
{
	setSpeedX(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
	setSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Destructor
 */
CFishCarp::~CFishCarp()
{
}

/**
 * Tells if item is a predator
 * \return true if a predator
 */
bool CFishCarp::Predator()
{
	return true;
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"carp");
	return itemNode;
}