#include "Ship.h"



Ship::Ship():size_(0), hits_(0)
{
}

Ship::Ship(int size) :size_(size), hits_(0)
{
}


void Ship::setSize(int size)
{
	size_ = size;
}

int Ship::getSize() const
{
	return size_;
}

Ship::~Ship()
{
}
