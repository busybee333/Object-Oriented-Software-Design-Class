#include "stdafx.h"
#include "CppUnitTest.h"
#include "Timeline.h"
#include "AnimChannel.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTimelineTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		//numFrames initial value, getter, and setter
		TEST_METHOD(TestNumFramesSet)
		{
			CTimeline timeline;
			timeline.SetNumFrames(10);
			int frames = timeline.GetNumFrames();
			Assert::AreEqual(10, frames);
		}
		
		TEST_METHOD(TestNumFramesGet)
		{
			CTimeline timeline;
			int frames = timeline.GetNumFrames();
			Assert::AreEqual(300, frames);
		}

		//frameRate initial value, getter, and setter
		TEST_METHOD(TestFrameRateSet)
		{
			CTimeline timeline;
			timeline.SetFrameRate(50);
			int rate = timeline.GetFrameRate();
			Assert::AreEqual(50, rate);
		}

		TEST_METHOD(TestFrameRateGet)
		{
			CTimeline timeline;
			int rate = timeline.GetFrameRate();
			Assert::AreEqual(30, rate);
		}

		//currentTime initial value, getter, and setter
		TEST_METHOD(TestCurrentTimeSet)
		{
			CTimeline timeline;
			timeline.SetCurrentTime(22.2);
			double time = timeline.GetCurrentTime();
			Assert::AreEqual(22.2, time, 0.00001);
		}

		TEST_METHOD(TestCurrentTimeGet)
		{
			CTimeline timeline;
			double time = timeline.GetCurrentTime();
			Assert::AreEqual(0, time, 0.00001);
		}

		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;
			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);
			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);
			timeline.SetNumFrames(789);
			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}
		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;
			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());
			// Changed time
			timeline.SetCurrentTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}

		TEST_METHOD(TestCTimelineAdd)
		{
			CTimeline timeline;
			CAnimChannelAngle channel;

			timeline.AddChannel(&channel);
			Assert::IsTrue(&timeline == channel.GetTimeline());
		}
	};
}