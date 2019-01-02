/**
 * \file HaroldFactory.h
 *
 * \author Romi Yun
 *
 * Factory class that builds the Harold character
 */

#pragma once
#include "ActorFactory.h"
#include "Actor.h"

#include <memory>

 /**
  * Factory class that builds the Harold character
  */

class CHaroldFactory : public CActorFactory
{
public:
	/// Constructor
	CHaroldFactory();

	/// Destructor
	virtual ~CHaroldFactory();

	/** This is a concrete factory method that creates our Harold actor.
	* \returns Pointer to an actor object.
	*/
	std::shared_ptr<CActor> Create();
};

