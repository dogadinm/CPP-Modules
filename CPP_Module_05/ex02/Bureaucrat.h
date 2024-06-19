
#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#define LOWEST 150
#define HIGHEST 1

#include <iostream>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat(void);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();

    Bureaucrat const &operator=(Bureaucrat const &copy);
    std::string const &getName(void) const;
    int const &getGrade(void) const;


    void increaseGrade(void);
    void decreaseGarde(void);

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