/**
 * \file PictureFactory.cpp
 *
 * \author Romi Yun
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "ImageDrawable.h"
#include "JujuFactory.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CPictureFactory::CPictureFactory()
{
}

/**
 * Destructor
 */
CPictureFactory::~CPictureFactory()
{
}

/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();

	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI =
		make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	picture->AddActor(harold);

	// Create and add Juju
	CJujuFactory factory1;
	auto juju = factory1.Create();

	// This is where Juju will start out.
	juju->SetPosition(Point(200, 500));

	picture->AddActor(juju);

	return picture;
}