#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Passing through WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Passing through WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "Passing through WrongCat copy constructor" << std::endl;
	*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "Passing through WrongCat operator=() overload" << std::endl;
	this->type = copy.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}