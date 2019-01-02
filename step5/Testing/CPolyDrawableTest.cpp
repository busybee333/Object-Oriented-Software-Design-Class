#include "stdafx.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
	{
	public:

		bool CompareColors(Gdiplus::Color color1, Gdiplus::Color color2)
		{
			auto color1_a = color1.Color::GetA();
			auto color1_b = color1.Color::GetB();
			auto color1_g = color1.Color::GetG();
			auto color1_r = color1.Color::GetR();

			auto color2_a = color2.Color::GetA();
			auto color2_b = color2.Color::GetB();
			auto color2_g = color2.Color::GetG();
			auto color2_r = color2.Color::GetR();

			bool a = color1_a == color2_a;
			bool b = color1_b == color2_b;
			bool g = color1_g == color2_g;
			bool r = color1_r == color2_r;

			if (a && b && g && r)
			{
				return true;
			}
			return false;

		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCPolyDrawableConstructor)
		{
			CPolyDrawable polyDrawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), polyDrawable.GetName());
		}

		TEST_METHOD(TestCPolyDrawableColor)
		{
			// color default value, getter, and setter
			CPolyDrawable polyDrawable(L"Harold");
			Assert::IsTrue(CompareColors(polyDrawable.GetColor(), Gdiplus::Color::Black));
			Assert::IsFalse(CompareColors(polyDrawable.GetColor(), Gdiplus::Color::AntiqueWhite));

			polyDrawable.SetColor(Gdiplus::Color::Aquamarine);
			Assert::IsTrue(CompareColors(polyDrawable.GetColor(), Gdiplus::Color::Aquamarine));
			Assert::IsFalse(CompareColors(polyDrawable.GetColor(), Gdiplus::Color::AntiqueWhite));
		}
	};
}