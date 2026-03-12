#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie;

	heapZombie = newZombie("HeapZ");
	heapZombie->announce();
	randomChump("StackZ");
	delete heapZombie;
	return (0);
}
