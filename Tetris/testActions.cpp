#include "testActions.h"

bool inputClavier() {
	return GetAsyncKeyState(VK_SPACE);
}


void TestActions::testerSingleInput()
{
	SingleInputAction monAction;
	monAction.addInput(inputClavier);


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
}

void TestActions::testerHold()
{
	HoldAction monAction;
	monAction.addInput(inputClavier);


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
}

void TestActions::testerTranslate()
{
	TranslateAction monAction;
	monAction.addInput(inputClavier);


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
}
