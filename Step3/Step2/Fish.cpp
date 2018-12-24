#include "stdafx.h"
#include "Fish.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 50;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
	CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode> CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"speedX", mSpeedX);
	itemNode->SetAttribute(L"speedY", mSpeedY);
	return itemNode;
}

/*
 * Destructor
 */
CFish::~CFish()
{
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	double rightWidth = GetAquarium()->GetWidth() - 10 - (this->GetWidth() / 2);
	double leftWidth = 10 + (this->GetWidth() / 2);
	double topWidth = GetAquarium()->GetHeight() - 10 - (this->GetHeight() / 2);
	double bottomWidth = 10 + (this->GetHeight() / 2);

	if (mSpeedX > 0 && GetX() >= rightWidth)
	{
		mSpeedX = -mSpeedX;
		SetMirrorX(mSpeedX < 0);
	}
	if (mSpeedX < 0 && GetX() <= leftWidth)
	{
		mSpeedX = -mSpeedX;
		SetMirrorX(mSpeedX < 0);
	}
	if (mSpeedY > 0 && GetY() >= topWidth)
	{
		mSpeedY = -mSpeedY;
	}
	if (mSpeedY < 0 && GetY() <= bottomWidth)
	{
		mSpeedY = -mSpeedY;
	}
}