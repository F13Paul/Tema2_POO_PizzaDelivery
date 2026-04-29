#ifndef COMANDA_HPP
#define COMANDA_HPP

#include "Produs.hpp"
#include <vector>
#include <iostream>

class Comanda {
private:
    std::vector<Produs*> produse; // vector de pointeri la baza (upcasting)

public:
    Comanda() = default;
    Comanda(const Comanda& alta); // constructor de copiere
    ~Comanda(); // destructor pentru a curata pointerii

    Comanda& operator=(Comanda alta); // operator de atribuire

    friend void swap(Comanda& c1, Comanda& c2) noexcept;
    void adaugaProdus(const Produs& p);
    void afiseazaComanda() const;
    float calculeazaTotal() const;
    void afiseazaBon(std::ostream& out) const;
    int numaraPizza() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Comanda& comanda);
};

#endif