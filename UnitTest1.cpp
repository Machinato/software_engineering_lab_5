#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\mason\source\repos\Laba 2 1.5\Laba 2 1.5\Laba 2 1.5.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CalculateTest)
    {
    public:
        TEST_METHOD(Calculate_x_1_n_1_returned_0dot5)
        {
            int n = 2;
            double x = 1;
            double res = calculate(x, n);
            Assert::AreEqual(1.6, res);
        }
    public:

        TEST_METHOD(Calculate_x_m1_n_2_return_0)
        {
            int n = 2;
            double x = -1;
            double res = calculate(x, n);
            Assert::AreEqual(0.15, res);
        }
    public:

        TEST_METHOD(Calculate_x_0_n_3_return_0)
        {
            int n = 3;
            double x = 0;
            double res = calculate(x, n);
            Assert::AreEqual(0.1, res);
        }
    };
    TEST_CLASS(CheckValidParamTest){
  public :
    TEST_METHOD(CheckValidParam_n_m1_exceptionTrown){
        int n = 0;
        try
        {
          checkValidParam(n);
          Assert::Fail();
        }
        catch (...)
        {
            Assert::IsTrue(true);
        }
      }

  public:
    TEST_METHOD(CheckValidParam_n_9_exceptionNotTrown)
    {
      int n = 3;
      try
      {
        checkValidParam(n);
        Assert::IsTrue(true);
      }
      catch (...)
      {
        Assert::Fail();
      }
    }
  };

}




