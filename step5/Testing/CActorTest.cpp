#include "stdafx.h"
#include "CppUnitTest.h"
#include "Actor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CActorTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}

		TEST_METHOD(TestCActorEnabled)
		{
			// enabled default value, getter, and setter
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsEnabled());

			actor.SetEnabled(false);
			Assert::IsFalse(actor.IsEnabled());
		}

		TEST_METHOD(TestCActorClickable)
		{
			// clickable default value, getter, and setter
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsClickable());

			actor.SetClickable(false);
			Assert::IsFalse(actor.IsClickable());
		}

		TEST_METHOD(TestCActorPosition)
		{
			// position default value, getter, and setter
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
			
			actor.SetPosition(Size(100,200));
			Assert::AreEqual(100, actor.GetPosition().X);
			Assert::AreEqual(200, actor.GetPosition().Y);
		}
	};
}