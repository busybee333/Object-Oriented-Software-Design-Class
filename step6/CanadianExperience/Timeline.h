/**
 * \file Timeline.h
 *
 * \author Romi Yun
 *
 *This class implements a timeline that manages the animation
 */

#pragma once

#include <math.h>
#include <vector>

class CAnimChannel;

/** This class implements a timeline that manages the animation
*
* A timeline consists of animation channels for different parts of our
* actors, each with keyframes that set the position, orientation, etc
* at that point in time. */

class CTimeline
{
public:
	/// Constructor
	CTimeline();

	/// Copy Constructor (Disabled)
	CTimeline(const CTimeline &) = delete;

	/// Assignment Operator (Disabled)
	void operator=(const CTimeline &) = delete;

	/// Destructors
	virtual ~CTimeline();

	/** Get the number of frames in the animation
	* \returns Number of frames in the animation
	*/
	int GetNumFrames() const { return mNumFrames; }

	/** Set the number of frames in the animation
	* \param numFrames Number of frames in the animation
	*/
	void SetNumFrames(int numFrames) { mNumFrames = numFrames; }
	
	/** Get the frame rate
	* \returns Animation frame rate in frames per second
	*/
	int GetFrameRate() const { return mFrameRate; }
	
	/** Set the frame rate
	* \param frameRate Animation frame rate in frames per second
	*/
	void SetFrameRate(int frameRate) { mFrameRate = frameRate; }
	
	/** Get the current time
	* \returns Current animation time in seconds
	*/
	double GetCurrentTime() const { return mCurrentTime; }
	
	/** Set the current time
	* \param t new current animation time in seconds
	*/
	void SetCurrentTime(double t);

	/** Get the current frame.
	*
	* This is the frame associated with the current time
	* \returns Current frame
	*/
	int GetCurrentFrame() const { return int(floor(mCurrentTime*mFrameRate)); }
	
	/** Get the animation duration
	* \returns Animation duration in seconds
	*/
	double GetDuration() const { return double(mNumFrames)/mFrameRate; }

	/** Adds channel
	* \param channel Channel to be added
	*/
	void AddChannel(CAnimChannel *channel);
private:
	/// The number of frames in the animation
	int mNumFrames = 300;

	/// The frame rate in frames per second
	int mFrameRate = 30;

	/// The current animation time in seconds
	double mCurrentTime = 0;

	/// List of all animation channels
	std::vector<CAnimChannel *> mChannels;
};

