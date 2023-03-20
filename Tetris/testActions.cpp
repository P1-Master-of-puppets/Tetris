#include "testActions.h"

void TestActions::testerSingleInput()
{
	Keyboard* keyboard = new Keyboard();
	SingleInputAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getInstantDrop));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}

	delete keyboard;
}

void TestActions::testerHold()
{
	Keyboard* keyboard = new Keyboard();
	HoldAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getInstantDrop));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
	delete keyboard;
}

void TestActions::testerTranslate()
{
	Keyboard* keyboard = new Keyboard();
	TranslateAction monAction;
	monAction.addInput(new Input(keyboard, &Control::getInstantDrop));


	while (1) {

		if (monAction.isActive()) {
			std::cout << "Input" << std::endl;
		}
	}
	delete keyboard;
}
