#pragma once
#include <vector>

using std::vector;



class Ship
{
public:
	Ship();
	Ship(int size);

	void setSize(int size);
	int getSize() const;

	~Ship();



private:

	int size_;
	int hits_;
};

