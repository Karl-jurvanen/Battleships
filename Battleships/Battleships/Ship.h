#pragma once
#include <vector>

using std::vector;



class Ship
{
public:
	Ship();
	Ship(int size);
	Ship(const Ship & init);

	void setSize(int size);
	int getSize() const;
	int getHits() const;

	void hit();

	~Ship();



private:

	int size_;
	int hits_;
};

