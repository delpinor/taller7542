#ifndef PODER_H_
#define PODER_H_

class Poder {
public:
	Poder(int x, int y );
	int x;
	int y;
	void setPosInX(int x);
	void setPosInY(int y);
	void move();
	};
#endif
