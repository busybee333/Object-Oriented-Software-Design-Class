/**
 * \file AnimChannel.h
 *
 * \author Romi Yun
 *
 * Base class for animation channels
 */

#pragma once

#include <string>
#include <vector>

class CTimeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */

class CAnimChannel
{
public:
	/// Constructor
	CAnimChannel();

	/// Copy Constructor (Disabled)
	CAnimChannel(const CAnimChannel &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CAnimChannel &) = delete;

	/// Destructor
	virtual ~CAnimChannel();

	/** Sets the name
	* \param name Name we are setting */
	void SetName(const std::wstring &name) { mName = name; }

	/** Get Name
	* \returns mName The current name */
	std::wstring GetName() const { return mName; }

	/**
	 * Is the channel valid, meaning has keyframes?
	 * \returns true if the channel is valid.
	 */
	bool IsValid();

	/** Sets the frame
	* \param currFrame Frame we are setting */
	void SetFrame(int currFrame);

	/** Sets the timeline
	* \param timeline Timeline we are setting */
	void SetTimeline(CTimeline *timeline) { mTimeline = timeline; }

	/** Get timeline
	* \returns mTimeline The current timeline */
	CTimeline *GetTimeline() { return mTimeline; }

	/** Class that represents a keyframe */
	class Keyframe
	{
	public:
		/** Constructor
		 * \param channel Channel we are associated with */
		Keyframe(CAnimChannel *channel) : mChannel(channel) {}

		/** Default constructor disabled */
		Keyframe() = delete;

		/** Copy constructor disabled */
		Keyframe(const Keyframe &) = delete;

		/** Assignment operator disabled */
		void operator=(const Keyframe &) = delete;
		
		/** Sets the frame
		* \param frame Frame we are setting */
		void SetFrame(int frame) { mFrame = frame; }

		/** Get frame
		* \returns mFrame The current frame */
		int GetFrame() const { return mFrame; }

		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() = 0;

		/** Use this keyframe as keyframe 2 */
		virtual void UseAs2() = 0;

		/** Use this keyframe as the x */
		virtual void UseOnly() = 0;

	protected:
		/// The frame
		int mFrame;

	private:
		/// The channel this keyframe is associated with
		CAnimChannel *mChannel;
	};


protected:
	/** Determine how we should insert a keyframe into our keyframe list.
	 * \param keyframe The keyframe to insert
	 */
	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);
		
	/**
	* Compute a point that is an interpolation between two keyframes
	* \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
	* interpolate between.
	*/
	virtual void Tween(double t) {}

private:
	std::wstring mName;     ///< The channel name
	int mKeyframe1 = -1;    ///< The first keyframe
	int mKeyframe2 = -1;    ///< The second keyframe

	/// The timeline object
	CTimeline *mTimeline = nullptr;

	/// The collection of keyframes for this channel
	std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};

