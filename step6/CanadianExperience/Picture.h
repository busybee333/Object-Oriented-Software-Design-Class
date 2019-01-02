/**
 * \file Picture.h
 *
 * \author Romi Yun
 *
 * Picture class provides the picture we are drawing
 */

#pragma once
#include "Timeline.h"
#include <memory>
#include <vector>

class CPictureObserver;
class CActor;

/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class CPicture
{
public:
	/// Constructor
	CPicture();

	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CPicture &) = delete;

	/// Destructor
	virtual ~CPicture();

	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	/**
	 * Add an observer to this picture.
	 * \param observer The observer to add
	 */
	void AddObserver(CPictureObserver *observer);

	/**
	 * Remove an observer from this picture
	 * \param observer The observer to remove
	 */
	void RemoveObserver(CPictureObserver *observer);

	/**
	 * Update all observers to indicate the picture has changed.
	 */
	void UpdateObservers();
	
	/**
	 * Draw this picture on a device context
	 * \param graphics The device context to draw on
	 */
	void Draw(Gdiplus::Graphics *graphics);

	/**
	 * Adds actor to list of actors
	 * \param actor An actor to add
	 */
	void AddActor(std::shared_ptr<CActor> actor);

	/** Set the current animation time
	 *
	 * This forces the animation of all
	 * objects to the current animation location.
	 * \param time The new time.
	 */
	void SetAnimationTime(double time);

	/** Get a pointer to the Timeline object
	* \returns Pointer to the Timeline object
	*/
	CTimeline *GetTimeline() { return &mTimeline; }

	/** Iterator that iterates over some picture */
	class Iter
	{
	public:
		/** Constructor
		 * \param picture The picture we are iterating over 
		 * \param pos The position */
		Iter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

		/** Test for end of the iterator
		 * \param other The other item we are comparing
		 * \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		 * \returns Value at mPos in the picture */
		std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

		/** Increment the iterator
		 * \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		CPicture *mPicture;   ///< Picture we are iterating over
		int mPos;       ///< Position in the picture
	};

	/** Gets the beginning of the iterator
	 * \returns position of beginning */
	Iter begin() { return Iter(this, 0); }

	/** Gets the end of the iterator
	 * \returns position of end */
	Iter end() { return Iter(this, mActors.size()); }
private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);

	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;

	/// The observers of this picture
	std::vector<std::shared_ptr<CActor>> mActors;

	/// The animation timeline
	CTimeline mTimeline;
};

