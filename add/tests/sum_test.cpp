#include "CppUTest/TestHarness.h"

extern "C"{
    #include "sum.h"
}

TEST_GROUP(add) {
    void setup(){};
    void teardown(){};
};

TEST(add, InputPlusValue) {
    int ret = sum(3, 4);
    CHECK_EQUAL(ret, 7);
}