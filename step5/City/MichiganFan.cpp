/**
 * \file MichiganFan.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "MichiganFan.h"

using namespace std;
using namespace Gdiplus;

/// Image for background
const wstring TileBackground = L"grass.png";

/// Fan at beginning of the game
const wstring BeginningFan = L"umguy1.png";

/// Fan after being astounded during the game
const wstring DuringFan = L"umguy2.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 150;

/** Constructor
* \param city The city this is a member of
*/
CMichiganFan::CMichiganFan(CCity *city) : CTile(city)
{
	SetImage(TileBackground);

	LoadImage(mBeginningFan, BeginningFan);
	LoadImage(mDuringFan, DuringFan);

	mSpeedX = ((double)rand() / (RAND_MAX - 1)) * MaxSpeedX;
	mSpeedX += 80;
	if (int(mSpeedX) % 2 != 0)
	{
		mSpeedX = -mSpeedX;
	}
}

/**
*  Destructor
*/
CMichiganFan::~CMichiganFan()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CMichiganFan::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"fan");

	return itemNode;
}

/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CMichiganFan::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/** Draw this item
* \param graphics The graphics context to draw on */
void CMichiganFan::Draw(Gdiplus::Graphics *graphics)
{
	CTile::Draw(graphics);

	if (mState == Beginning)
	{
		int wid = mBeginningFan->GetWidth();
		int hit = mBeginningFan->GetHeight();

		graphics->DrawImage(mBeginningFan.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else
	{
		int wid = mDuringFan->GetWidth();
		int hit = mDuringFan->GetHeight();

		if (mNumPlays < 3)
		{
			graphics->DrawImage(mDuringFan.get(),
				(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
				wid, hit);
			mInitialX = (int)(GetX() - OffsetLeft);
			mInitialY = (int)(GetY() - OffsetLeft);
		}
		else
		{
			graphics->DrawImage(mDuringFan.get(),
				(int)(GetX() - OffsetLeft) + mRunX, (int)(GetY() + OffsetDown - hit),
				wid, hit);
		}
	}
}

/**
*  Changes state of Michigan Fan
*/
void CMichiganFan::ChangeState()
{
	mState = During;
}

/**
*  Increment number of plays watched
*/
void CMichiganFan::IncrementPlay()
{
	mNumPlays++;
}

/**
* Called before the image is drawn
* \param elapsed Time since last draw
*/
void CMichiganFan::Update(double elapsed)
{
	CTile::Update(elapsed);

	if (mNumPlays < 3)
	{
		mRunX = 0;
	}

	// when the Minion is running...
	// mSpeedX is a constant pixels per second running speed...
	mRunX += mSpeedX * elapsed;

}

/**
*  Resets state and number of plays of Michigan Fan
*/
void CMichiganFan::ResetPosition()
{
	mNumPlays = 0;
	mState = Beginning;
}
