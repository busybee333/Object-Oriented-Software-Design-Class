/**
 * \file PictureObserver.h
 *
 * \author Romi Yun
 *
 * Observer base class for a picture.
 */

#pragma once

#include <memory>
#include <vector>

class CPicture;

/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class CPictureObserver
{
public:
	/// Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CPictureObserver &) = delete;

	/// Virtual Destructor
	virtual ~CPictureObserver();

	/** Set the picture for this observer
	 * \param picture The picture to set */
	void SetPicture(std::shared_ptr<CPicture> picture);

	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/** The picture 
	* \returns Picture */
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }

protected:
	/// Constructor
	CPictureObserver();

private:
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;
};

