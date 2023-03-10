#ifndef TRANSLATEACTION_H__
#define TRANSLATEACTION_H__

#include "holdAction.h"

class TranslateAction : public HoldAction
{
public:
	TranslateAction();
	~TranslateAction();
	bool isActivated();
};
#endif // ! TRANSLATEACTION_H__