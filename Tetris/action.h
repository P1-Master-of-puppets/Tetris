#ifndef ACTION_H__
#define ACTION_H__

#include <vector>

class Action {

protected:
	std::vector<bool (*)()> inputs = std::vector<bool (*)()>();
	bool getCurrentState();
public:
	Action();
	virtual ~Action();
	virtual bool isActive();
	void resetInputs();
	//ça ne fonctionnera pas pour la manette, il va faloir la mettre statique
	void addInput(bool (*function)());
};

#endif // ! ACTION_H__
