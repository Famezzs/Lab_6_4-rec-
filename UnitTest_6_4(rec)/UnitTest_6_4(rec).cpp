#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_6_4(rec)\Lab_6_4(rec)\Lab_6_4(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
	TEST_CLASS(UnitTest64rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			int a[n];
			a[0] = -9;
			a[1] = 9;
			a[2] = 0;

			Assert::AreEqual(Min(a, n, a[0], 1), 0);
		}
	};
}
