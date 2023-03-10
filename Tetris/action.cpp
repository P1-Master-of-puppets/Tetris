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
}

bool Action::isActive()
{
	return false;
}

void Action::resetInputs()
{
}

void Action::addInput(bool (*input)())
{
	inputs.push_back (input);
}
