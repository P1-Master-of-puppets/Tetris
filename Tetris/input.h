#ifndef INPUT_H__
#define INPUT_H__

#include "control.h"

class Input {
private:
	Control* _control;
	bool(*_functionptr)();
public:
	Input(Control control, bool (*functionptr)());
};

#endif // !INPUT_H__
