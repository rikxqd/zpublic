#include "stdafx.h"
#include "TestWinUtils.h"


CTestWinUtils::CTestWinUtils(void)
{
    TEST_ADD(CTestWinUtils::test_path);
    TEST_ADD(CTestWinUtils::test_directory);
}


CTestWinUtils::~CTestWinUtils(void)
{
}