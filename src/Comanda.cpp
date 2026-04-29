#include "Comanda.hpp"
#include "Pizza.hpp"
#include "Bautura.hpp"
#include "Desert.hpp"
#include <iostream>
#include <utility>

// constructor de copiere folosind clone() pentru copiere polimorfica
Comanda::Comanda(const Comanda& alta) {
    for (const auto* produs : alta.produse) {
        if (produs != nullptr) {
            produse.push_back(produs->clone());
        }
    }
}

// destructor
Comanda::~Comanda() {
    for (auto* produs : produse) {
        delete produs;
    }
}

void swap(Comanda& c1, Comanda& c2) noexcept {
    using std::swap;
    swap(c1.produse, c2.produse);
}

// operator= 
Comanda& Comanda::operator=(Comanda alta) {
    swap(*this, alta);
    return *this;
}

void Comanda::adaugaProdus(const Produs& p) {
    produse.push_back(p.clone());
}

int Comanda::numaraPizza() const {
    int count = 0;

    for (const auto* produs : produse) {
        if (dynamic_cast<const Pizza*>(produs) != nullptr) {
            count++;
        }
    }

    return count;
}

float Comanda::calculeazaTotal() const {
    float total = 0;
    for (const Produs* p : produse) {
        total += p->calculeazaPret(); // polimorfism
    }
    return total;
}

void Comanda::afiseazaComanda() const {
    afiseazaBon(std::cout);
}

void Comanda::afiseazaBon(std::ostream& out) const {
    out << "===== BON COMANDA =====\n";

    for (const auto* produs : produse) {
        if (produs != nullptr) {
            out << *produs << "\n";
        }
    }

    out << "Total: " << calculeazaTotal() << " lei\n";
    out << "Numar pizza: " << numaraPizza() << "\n";
    out << "=======================\n";
}

std::ostream& operator<<(std::ostream& out, const Comanda& comanda) {
    comanda.afiseazaBon(out);
    return out;
}