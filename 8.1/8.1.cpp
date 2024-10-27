#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1 char 3/8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My81
{
	TEST_CLASS(My81)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(hasSQorQS("This contains SQ and QS"));
			Assert::IsTrue(hasSQorQS("Only SQ here"));
			Assert::IsTrue(hasSQorQS("QS appears here"));
		}
	};
}
