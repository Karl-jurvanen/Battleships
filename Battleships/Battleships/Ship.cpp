#include "Ship.h"



Ship::Ship():size_(0), hits_(0)
{
}

Ship::Ship(int size) :size_(size), hits_(0)
{
}

Ship::Ship(const Ship & init): size_(init.size_), hits_(init.hits_)
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

int Ship::getHits() const
{
	return hits_;
}

void Ship::hit()
{
	hits_++;
}

Ship::~Ship()
{
}
