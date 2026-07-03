#include "Bureaucrat.hpp"
// Default constructor (private fallback)
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

// Parameterized constructor with boundary exception checks
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Copy assignment operator (Note: _name is const, so only _grade can be copied)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

// Increment grade (reduces integer value toward 1)
void Bureaucrat::incrementGrade() {
	if(this->grade - 1 < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}

// Decrement grade (increases integer value toward 150)
void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

// Custom Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! Maximum allowed rank is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! Minimum allowed rank is 150.";
}

// Ostream operator overload
std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}
