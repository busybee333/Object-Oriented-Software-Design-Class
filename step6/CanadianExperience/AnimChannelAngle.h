/**
 * \file AnimChannelAngle.h
 *
 * \author Romi Yun
 *
 * Animation channel for angles.
 */

#pragma once
#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */

class CAnimChannelAngle :
	public CAnimChannel
{
public:
	/// Constructor
	CAnimChannelAngle();

	/// Copy Constructor (Disabled)
	CAnimChannelAngle(const CAnimChannelAngle &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CAnimChannelAngle &) = delete;

	/// Destructor
	virtual ~CAnimChannelAngle();

	/** Get angle
	* \returns mAngle The current angle */
	double GetAngle() { return mAngle; }

	/** Sets the keyframe
	* \param angle Angle we are setting */
	void SetKeyframe(double angle);

	/** Class that represents a keyframe angle */
	class KeyframeAngle : public Keyframe
	{
	public:
		/** Constructor
		 * \param channel The channel we are for
		 * \param angle The angle for the keyframe */
		KeyframeAngle(CAnimChannelAngle *channel, double angle) :
			Keyframe(channel), mChannel(channel), mAngle(angle) {}

		/// Default Constructor (Disabled)
		KeyframeAngle() = delete;

		/// Copy Constructor (Disabled)
		KeyframeAngle(const KeyframeAngle &) = delete;

		/// Assignment Operator (Disabled)
		void operator=(const KeyframeAngle &) = delete;

		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** Use this keyframe as the angle */
		virtual void UseOnly() override { mChannel->mAngle = mAngle; }

		/** Get angle
		* \returns mAngle The current angle */
		double GetAngle() { return mAngle; }

	private:
		/// Current angle
		double mAngle;

		/// The channel this keyframe is associated with
		CAnimChannelAngle *mChannel;
	};

protected:
	/**
	 * Compute an angle that is an interpolation between two keyframes
	 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
	 * interpolate between.
	 */
	void Tween(double t);

private:
	/// Angle in degrees
	double mAngle = 0;

	/// The first angle keyframe
	KeyframeAngle *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframeAngle *mKeyframe2 = nullptr;
};

