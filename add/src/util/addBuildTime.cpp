#include "addBuildTime.h"

addBuildTime::addBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

addBuildTime::~addBuildTime()
{
}

const char* addBuildTime::GetDateTime()
{
    return dateTime;
}

