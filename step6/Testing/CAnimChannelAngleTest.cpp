#include "stdafx.h"
#include "CppUnitTest.h"
#include "AnimChannelAngle.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CAnimChannelAngleTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestGetSet)
		{
			CAnimChannelAngle a;
			a.SetName(L"Lala");
			Assert::AreEqual(std::wstring(L"Lala"), a.GetName());
		}

	};
}