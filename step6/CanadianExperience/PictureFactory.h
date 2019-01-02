/**
 * \file PictureFactory.h
 *
 * \author Romi Yun
 *
 * A factory class that builds our picture.
 */

#pragma once

#include "Picture.h"

#include <memory>

/**
 * A factory class that builds our picture.
 */

class CPictureFactory
{
public:
	/// Constructor
	CPictureFactory();

	/// Destructor
	virtual ~CPictureFactory();
	
	/** Factory method to create a new picture.
	* \returns The created picture
	*/
	std::shared_ptr<CPicture> Create();
};

