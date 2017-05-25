#include "ctest.h"
#include "../src/deposit.h"

CTEST(test_number_one, dataent)
{
    int result = dataent (200,49999);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_day1_9999sum, dataent)
{
    const int a = 1;
    const int b = 9999;
    int result = dataent (a,b);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_negday_sum10001, dataent)
{
    int result = dataent (-1,10001);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_days366_sum10001, dataent)
{	
    int result = dataent (366,10001);  
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_day1_sum10000, profit)
{	
      
    int result = profit (10000,1);
    int expected = 9000;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_sum10000days30, profit)
{

    int result = profit (10000,30);
    int expected = 9000;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_30days_sum100000, profit)
{

    int result = profit (100000,30);
    int expected = 90000;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_31days_sum10000, profit)
{
    int result = profit (10000,31);
    int expected = 10200;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_241days_sum10000, profit)
{
    int result = profit (10000,241);
    int expected = 11200;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_241days_sum100000, profit)
{
    int result = profit (100000,241);
    int expected = 114999;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_241days_sum110000, profit)
{
    int result = profit (110000,365);
    int expected = 126499;
    ASSERT_EQUAL(expected, result);
}
