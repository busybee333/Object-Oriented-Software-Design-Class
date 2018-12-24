/**
* \file MichiganFan.h
*
* \author Romi Yun
*
*  Class that implements a Michigan fan
*/

#pragma once

#include "Tile.h"
#include "TileVisitor.h"

/**
*  A Michigan fan on a tile
*/
class CMichiganFan : public CTile
{
public:
	CMichiganFan(CCity *city);

	///  Default constructor (disabled)
	CMichiganFan() = delete;

	///  Copy constructor (disabled)
	CMichiganFan(const CMichiganFan &) = delete;

	/// Destructor
	~CMichiganFan();

	/// Save this item to an XML node
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/// Loads image
	void LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	/// Draws image
	void Draw(Gdiplus::Graphics * graphics);

	/// Changes Michigan Fan's state to During (play)
	void ChangeState();

	/// Increments Michigan Fan's plays watched counter
	void IncrementPlay();

	/// Called before the image is drawn
	void Update(double elapsed);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitMichiganFan(this); }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept1(CTileVisitor *visitor) override { visitor->VisitFan(this); }

	/// The different states a fan can be in
	enum States { Beginning, During };

	/// Returns the number of plays watched
	int GetPlays() { return mNumPlays; }

	/// Sets the number of plays watched to 3
	void SetToThree() { mNumPlays = 3; }

	/// Resets UM fan to original position and 0 plays
	void ResetPosition();
private:
	/// The image of the beginning fan
	std::unique_ptr<Gdiplus::Bitmap> mBeginningFan;

	/// The image of the during play fan
	std::unique_ptr<Gdiplus::Bitmap> mDuringFan;

	/// Initial state will be beginning
	States mState = Beginning;

	/// Number of plays
	int mNumPlays = 0;

	/// Run speed
	double mRunX = 0;

	/// Fan speed in the X direction
	double mSpeedX;

	/// Initial X position
	double mInitialX;

	/// Initial Y position
	double mInitialY;
};