#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
class FlowManager
{
public:
	static bool doYouWantToContinue();
	static bool doYouWantToTryAgain();
	static void unexpectedInput();
};

