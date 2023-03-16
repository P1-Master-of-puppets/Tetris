#include "action.h"

bool Action::getCurrentState()
{
	return false;
}

Action::Action()
{
}

Action::~Action()
{
	inputs.clear();
}

bool Action::isActive()
{
	return false;
}

void Action::resetInputs()
{
	inputs.clear();
}

void Action::addInput(bool (*input)())
{
	inputs.push_back(input);
}
