#ifndef CONTROL_INTERFACE_H__
#define CONTROL_INTERFACE_H__

class ControlInterface {
	public:
		virtual bool translateLeft() = 0;
		virtual bool translateRight() = 0;
		virtual bool rotateRight() = 0;
		virtual bool rotateLeft() = 0;
		virtual bool dropInstant() = 0;
		virtual bool dropFaster() = 0;
		virtual bool holdPiece() = 0;
		virtual bool menu() = 0;
};

#endif