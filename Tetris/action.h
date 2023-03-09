#ifndef ACTION_H__
#define ACTION_H__

class Action {

public:

	Action(bool (*assingKeyboardDelegate)(), bool (*assingControllerDelegate)());
	virtual bool isActivated();

protected:
	bool (*keyboardDelegate)();
	bool (*controllerDelegate)();
	bool wasPressed;

};



#endif // ! ACTION_H__
