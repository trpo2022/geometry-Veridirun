#include <ctest.h>
#include <libgeometry/geom_string.h>

CTEST(suite, test1_true)
{
    int result = ProcessGeomFile("../test/testfiles/test1.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test2_true)
{
    int result = ProcessGeomFile("../test/testfiles/test2.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test3_true)
{
    int result = ProcessGeomFile("../test/testfiles/test3.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test4_true)
{
    int result = ProcessGeomFile("../test/testfiles/test4.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test5_true)
{
    int result = ProcessGeomFile("../test/testfiles/test5.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test6_circleword)
{
    const int result = ProcessGeomFile("../test/testfiles/test6.txt");

    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test7_lotsofspaces)
{
    const int result = ProcessGeomFile("../test/testfiles/test7.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test8_badbracket)
{
    int result = ProcessGeomFile("../test/testfiles/test8.txt");

    const int expected = 3;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test9_badnum)
{
    int result = ProcessGeomFile("../test/testfiles/test9.txt");

    const int expected = 3;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test10_missingcomma)
{
    int result = ProcessGeomFile("../test/testfiles/test10.txt");

    const int expected = 4;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test11_badnum)
{
    int result = ProcessGeomFile("../test/testfiles/test11.txt");

    const int expected = 3;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test12_missingleftbracket)
{
    int result = ProcessGeomFile("../test/testfiles/test12.txt");

    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(suite, test13_missingrightbracket)
{
    int result = ProcessGeomFile("../test/testfiles/test13.txt");

    const int expected = 5;

    ASSERT_EQUAL(expected, result);
}
