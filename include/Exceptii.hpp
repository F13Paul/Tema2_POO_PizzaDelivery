#ifndef EXCEPTII_HPP
#define EXCEPTII_HPP

#include <stdexcept>
#include <string>

class PizzaDeliveryException : public std::runtime_error {
public:
    explicit PizzaDeliveryException(const std::string& mesaj)
        : std::runtime_error(mesaj) {}
};

class PretInvalidException : public PizzaDeliveryException {
public:
    explicit PretInvalidException(const std::string& mesaj)
        : PizzaDeliveryException(mesaj) {}
};

class CaloriiInvalideException : public PizzaDeliveryException {
public:
    explicit CaloriiInvalideException(const std::string& mesaj)
        : PizzaDeliveryException(mesaj) {}
};

class VolumInvalidException : public PizzaDeliveryException {
public:
    explicit VolumInvalidException(const std::string& mesaj)
        : PizzaDeliveryException(mesaj) {}
};

class IngredientInvalidException : public PizzaDeliveryException {
public:
    explicit IngredientInvalidException(const std::string& mesaj)
        : PizzaDeliveryException(mesaj) {}
};

#endif