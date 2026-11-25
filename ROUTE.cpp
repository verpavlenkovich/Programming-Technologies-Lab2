
#include "ROUTE.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

bool hasVisibleText(const std::string& value) {
    for (std::size_t i = 0; i < value.size(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(value[i])))
            return true;
    }

    return false;
}

}

ROUTE::ROUTE()
    : start_(""), finish_(""), number_(0) {

    std::cout << "ROUTE: конструктор без параметров, объект "
              << this << '\n';
}

ROUTE::ROUTE(const std::string& start,
             const std::string& finish,
             int number)
    : start_(""), finish_(""), number_(0) {

    setStart(start);
    setFinish(finish);
    setNumber(number);

    std::cout << "ROUTE: конструктор с параметрами, объект "
              << this << '\n';
}

ROUTE::ROUTE(const ROUTE& other)
    : start_(other.start_),
      finish_(other.finish_),
      number_(other.number_) {

    std::cout << "ROUTE: конструктор копирования, объект "
              << this << '\n';
}

ROUTE& ROUTE::operator=(const ROUTE& other) {
    if (this != &other) {
        std::string startCopy(other.start_);
        std::string finishCopy(other.finish_);

        start_.swap(startCopy);
        finish_.swap(finishCopy);
        number_ = other.number_;
    }

    return *this;
}

ROUTE::~ROUTE() {
    std::cout << "ROUTE: деструктор, объект "
              << this << '\n';
}

const std::string& ROUTE::getStart() const {
    return start_;
}

const std::string& ROUTE::getFinish() const {
    return finish_;
}

int ROUTE::getNumber() const {
    return number_;
}

void ROUTE::setStart(const std::string& start) {
    if (!hasVisibleText(start))
        throw std::invalid_argument(
            "Начальный пункт не может быть пустым."
        );

    start_ = start;
}

void ROUTE::setFinish(const std::string& finish) {
    if (!hasVisibleText(finish))
        throw std::invalid_argument(
            "Конечный пункт не может быть пустым."
        );

    finish_ = finish;
}

void ROUTE::setNumber(int number) {
    if (number <= 0)
        throw std::invalid_argument(
            "Номер маршрута должен быть положительным."
        );

    number_ = number;
}

std::istream& operator>>(std::istream& in, ROUTE& route) {
    std::string start;
    std::string finish;
    std::string numberText;

    if (&in == &std::cin)
        std::cout << "Начальный пункт маршрута: ";

    if (!std::getline(in, start))
        return in;

    if (&in == &std::cin)
        std::cout << "Конечный пункт маршрута: ";

    if (!std::getline(in, finish))
        return in;

    if (&in == &std::cin)
        std::cout << "Номер маршрута: ";

    if (!std::getline(in, numberText))
        return in;

    std::istringstream converter(numberText);

    int number;
    char extra;

    if (!(converter >> number) || (converter >> extra))
        throw std::invalid_argument(
            "Номер маршрута должен быть целым числом."
        );

    ROUTE parsed(start, finish, number);
    route = parsed;

    return in;
}

std::ostream& operator<<(std::ostream& out, const ROUTE& route) {
    out << "Маршрут № " << route.getNumber()
        << ". Начало: " << route.getStart()
        << ". Конец: " << route.getFinish();

    return out;
}
