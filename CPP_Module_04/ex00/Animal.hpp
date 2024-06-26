#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(Animal const &copy);
    virtual ~Animal();

    Animal const &operator=(Animal const &copy);

    virtual const   std::string &getType(void) const;
    virtual void    makeSound(void) const;
};

#endif