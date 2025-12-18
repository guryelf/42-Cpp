#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name) : name(zombie_name)
{
    std::cout << "Zombie " << name << " created." << std::endl;
}
Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed." << std::endl;
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}