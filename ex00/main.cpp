#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie;
	
	heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	randomChump("Stack Zombie");
	delete heapZombie;
	return (0);
}
