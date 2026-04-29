#ifndef PIZZA_HPP
#define PIZZA_HPP

#include "Produs.hpp"
#include <vector>
#include <string>

class Pizza : public Produs {
private:
    std::vector<std::string> ingrediente;

public:
    // constructori
    Pizza();
    Pizza(const std::string& nume, float pret, const std::vector<std::string>& ingrediente);
    Pizza(const Pizza& alta); // Constructor de copiere

    // destructor
    ~Pizza() override;

    // operator de atribuire
    Pizza& operator=(const Pizza& alta);

    // metode specifice 
    void adaugaIngredient(const std::string& ingredient);

    // suprascrierea metodelor virtuale (polimorfism la runtime)
    float calculeazaPret() const override;
    Produs* clone() const override;
    void afisare(std::ostream& out) const override;

    // supraincarcare operatori
    friend std::istream& operator>>(std::istream& in, Pizza& p);
};

#endif