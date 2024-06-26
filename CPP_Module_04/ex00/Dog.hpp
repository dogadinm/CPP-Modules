#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
    std::string	type;
public:
    Dog(void);
    Dog(Dog const &copy);
    ~Dog(void);

    Dog const	&operator=(Dog const &copy);

    const std::string &getType(void) const;
    void	makeSound(void) const;
};

#endif