#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73
{
	TEST_CLASS(UnitTest73кул)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k, n;
			int** matrix = create(k = 2, n = 3);

			int nonZeroColumns = countColumns(matrix, k, n);

			Assert::AreEqual(nonZeroColumns, 2);
		}
	};
}
