#ifndef HOLDACTION_H__
#define HOLDACTION_H__

#include <chrono>
#include "action.h"

using namespace std::chrono;

class HoldAction : public Action
{

	public:

		HoldAction(bool(*assingKeyboardDelegate)(), bool(*assingControllerDelegate)(), int assingInputDelay);
		bool isActivated();

	private:
		high_resolution_clock::time_point lastActivation;
		int inputDelay;

};



#endif // ! ACTION_H__
#pragma once
