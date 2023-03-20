#include "action.h"

bool Action::getCurrentState()
{
	bool result = false;

	for (int i = 0; i < inputs.size(); i++) {
		result = result || inputs[i]();
	}
	
	return result;
}

Action::Action()
{
}

Action::~Action()
{
	//TODO tous les pointeurs doivent être delete avant de clear le vecteur
	inputs.clear();
}

void Action::resetInputs()
{
	inputs.clear();
}

void Action::addInput(bool (*input)())
{
	inputs.push_back(input);
}
