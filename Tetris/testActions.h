#pragma once
#ifndef TESTACTIONS_H__
#define TESTACTIONS_H__

#include <windows.h>
#include <iostream>
#include "translateAction.h"
#include "holdAction.h"
#include "singleInputAction.h"

class TestActions {
public:
	void testerSingleInput();
	void testerHold();
	void testerTranslate();
};



#endif

