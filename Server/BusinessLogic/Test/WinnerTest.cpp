#define BOOST_TEST_MODULE CSVProcessingTest test
#include <boost/test/unit_test.hpp>

#include "Winner.h"

BOOST_AUTO_TEST_CASE(CSVProcessingTest_tests)
{
    auto _1 = Winner({});
    BOOST_TEST(_1 == {1,2,3});
}
