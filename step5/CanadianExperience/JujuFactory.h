/**
 * \file JujuFactory.h
 *
 * \author Romi Yun
 *
 * Factory class that builds the Juju character
 */

#pragma once
#include "ActorFactory.h"
#include "Actor.h"

/**
 * Factory class that builds the Juju character
 */

class CJujuFactory :
	public CActorFactory
{
public:
	/// Constructor
	CJujuFactory();

	/// Destructor
	virtual ~CJujuFactory();

	/** This is a concrete factory method that creates our Juju actor.
	* \returns Pointer to an actor object.
	*/
	std::shared_ptr<CActor> Create();
};

