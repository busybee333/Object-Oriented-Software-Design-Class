/**
 * \file Actor.h
 *
 * \author Romi Yun
 *
 * Actor class for actors in our drawings.
 */

#pragma once

#include "Drawable.h"

#include <string>
#include <memory>
#include <vector>

class CPicture;

 /**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class CActor
{
public:
	/** Constructor
	* \param name The name of the actor
	*/
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;

	/** Copy constructor disabled */
	CActor(const CActor &) = delete;

	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;

	/// Destructor
	virtual ~CActor();

	/** Draw this actor
	* \param graphics The Graphics object we are drawing on */
	void Draw(Gdiplus::Graphics *graphics);

	/**
	* Test to see if a mouse click is on this actor.
	* \param pos Mouse position on drawing
	* \returns A drawable object we clicked on or nullptr if we missed.
	*/
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);

	/**
	* Add a drawable to this actor
	* \param drawable The drawable to add
	*/
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Get the actor name
	 * \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }

	/** Set the root drawable for the actor
	* \param root Pointer to root drawable */
	void CActor::SetRoot(std::shared_ptr<CDrawable> root)
	{
		mRoot = root;
	}

	/** Set the picture for the actor
	* \param picture Picture to set */
	void SetPicture(CPicture *picture) { mPicture = picture; }

	/** Get Picture
	* \returns mPicture The current picture */
	CPicture* GetPicture() { return mPicture; }

private:
	/// Name of the actor
	std::wstring mName;

	/// Tells if actor is enabled
	bool mEnabled = true;

	/// Position of actor
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	
	/// Tells if actor is clickable
	bool mClickable = true;

	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;

	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

	/// Picture we know about
	CPicture *mPicture = nullptr;
};

