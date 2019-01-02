/**
 * \file AnimChannelPoint.h
 *
 * \author Romi Yun
 *
 * Animation channel for points.
 */

#pragma once
#include "AnimChannel.h"

 /**
  * Animation channel for points.
  */

class CAnimChannelPoint :
	public CAnimChannel
{
public:
	/// Constructor
	CAnimChannelPoint();

	/// Copy Constructor (Disabled)
	CAnimChannelPoint(const CAnimChannelPoint &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CAnimChannelPoint &) = delete;

	/// Destructor
	virtual ~CAnimChannelPoint();

	/** Sets the keyframe
	* \param point Point we are setting */
	void SetKeyframe(Gdiplus::Point point);

	/** Get point
	* \returns mPoint The current point */
	Gdiplus::Point GetPoint() { return mPoint; }

	/** Class that represents a keyframe angle */
	class KeyframePoint : public Keyframe
	{
	public:
		/** Constructor
		 * \param channel The channel we are for
		 * \param point The point for the keyframe */
		KeyframePoint(CAnimChannelPoint *channel, Gdiplus::Point point) :
			Keyframe(channel), mChannel(channel), mPoint(point) {}

		/** Default constructor disabled */
		KeyframePoint() = delete;

		/** Copy constructor disabled */
		KeyframePoint(const KeyframePoint &) = delete;

		/** Assignment operator disabled */
		void operator=(const KeyframePoint &) = delete;

		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** Use this keyframe as the point */
		virtual void UseOnly() override { mChannel->mPoint = mPoint; }

		/** Get Point
		* \returns mPoint The current point */
		Gdiplus::Point GetPoint() { return mPoint; }

	private:
		/// Point
		Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

		/// The channel this keyframe is associated with
		CAnimChannelPoint *mChannel;
	};
	
protected:
	/**
	 * Compute a point that is an interpolation between two keyframes
	 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
	 * interpolate between.
	 */
	void Tween(double t);

private:
	/// Point
	Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

	/// The first point keyframe
	KeyframePoint *mKeyframe1 = nullptr;

	/// The second point keyframe
	KeyframePoint *mKeyframe2 = nullptr;
};

