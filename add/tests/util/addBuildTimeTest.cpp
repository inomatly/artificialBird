#include "CppUTest/TestHarness.h"
#include "addBuildTime.h"

TEST_GROUP(addBuildTime)
{
  addBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new addBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(addBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}

