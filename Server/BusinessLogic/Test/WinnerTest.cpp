#define BOOST_TEST_MODULE CSVProcessingTest test
#include <boost/test/unit_test.hpp>

#include "Winner.h"

BOOST_AUTO_TEST_CASE(CSVProcessingTest_tests)
{
    std::stringstream s;
    s << R"data(
    1,12:00:00
    2,12:00:01
    3,12:00:01
    4,12:00:02
    5,12:00:02
    2,12:01:00
    1,12:01:10
    4,12:01:10
    5,12:01:12
    3,12:01:15
    2,12:02:10
    1,12:02:12
    4,12:02:12
    5,12:02:16
    3,12:02:17
    1,12:03:15
    2,12:03:20
    4,12:03:26
    3,12:03:36
    5,12:03:37
    2,12:04:20
    1,12:04:28
    5,12:04:33
    4,12:04:45
    3,12:04:46)data";
    auto _1 = Winner(s);
    decltype(_1) _2 = {1,2,3};
    auto ok = _1 == _2;
    BOOST_TEST(ok);
}
