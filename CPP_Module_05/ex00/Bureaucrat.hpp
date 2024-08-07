
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    // Constructors and Destructor
    Bureaucrat(void);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    virtual ~Bureaucrat();

    // Operators
    Bureaucrat const    &operator=(Bureaucrat const &copy);

    // Geters and setters
    std::string const   &getName(void) const;
    int const           &getGrade(void) const;

    // Class members
    void increaseGrade(void);
    void decreaseGarde(void);
    
    // Exceptions
    class GradeTooHighException: public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };

};

std::ostream & operator<<(std::ostream & str, Bureaucrat const & bureaucrat);

#endif