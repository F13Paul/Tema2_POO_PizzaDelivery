#include <iostream>
#include <vector>

#include "Comanda.hpp"
#include "Pizza.hpp"
#include "Bautura.hpp"
#include "Desert.hpp"
#include "Exceptii.hpp"

int main() {
    std::cout << "=== Sistem PizzaDelivery ===\n\n";

    try {
        Comanda comandaCurenta;

        std::vector<std::string> ingrPizza1 = {"Sos Rosii", "Mozzarella", "Salam"};
        std::vector<std::string> ingrPizza2 = {"Sos de usturoi", "Pui", "Porumb", "Masline"};

        Pizza diavola("Pizza Diavola", 25.0f, ingrPizza1);
        Pizza pollo("Pizza Pollo", 28.0f, ingrPizza2);
        Bautura cola("Cola La Sticla", 6.5f, 500);
        Bautura apa("Apa Minerala Mare", 4.0f, 1000);
        Desert clatite("Clatite cu fineti", 15.0f, 600);

        comandaCurenta.adaugaProdus(diavola);
        comandaCurenta.adaugaProdus(pollo);
        comandaCurenta.adaugaProdus(cola);
        comandaCurenta.adaugaProdus(apa);
        comandaCurenta.adaugaProdus(clatite);

        std::cout << "Comanda initiala:\n";
        std::cout << comandaCurenta << "\n";

        std::cout << "Numar pizza in comanda: "
                  << comandaCurenta.numaraPizza() << "\n\n";

        std::cout << "Test constructor de copiere:\n";
        Comanda comandaCopiata = comandaCurenta;
        std::cout << comandaCopiata << "\n";

        std::cout << "Test operator= cu copy-and-swap:\n";
        Comanda comandaAsignata;
        Bautura suc("Suc Portocale", 7.0f, 330);
        comandaAsignata.adaugaProdus(suc);

        std::cout << "Inainte de atribuire:\n";
        std::cout << comandaAsignata << "\n";

        comandaAsignata = comandaCurenta;

        std::cout << "Dupa atribuire:\n";
        std::cout << comandaAsignata << "\n";

        std::cout << "\n--- Test getteri ---\n";
        std::cout << "Pizza: id=" << diavola.getId()
                  << ", nume=" << diavola.getNume() << "\n";

        std::cout << "Bautura: " << cola.getNume()
                  << ", volum=" << cola.getVolumMl() << " ml\n";

        std::cout << "Desert: " << clatite.getNume()
                  << ", kcal=" << clatite.getKcal() << "\n";

        std::cout << "\n--- Afisare comanda prin metoda afiseazaComanda() ---\n";
        comandaCurenta.afiseazaComanda();

        std::cout << "Test exceptii:\n";

        try {
            Desert desertInvalid("Tiramisu", 20.0f, -100);
            comandaCurenta.adaugaProdus(desertInvalid);
        } catch (const CaloriiInvalideException& e) {
            std::cerr << "Exceptie calorii prinsa corect: " << e.what() << "\n";
        }

        try {
            Bautura bauturaInvalida("Apa gresita", 5.0f, 0);
            comandaCurenta.adaugaProdus(bauturaInvalida);
        } catch (const VolumInvalidException& e) {
            std::cerr << "Exceptie volum prinsa corect: " << e.what() << "\n";
        }

        try {
            Pizza pizzaInvalida("Pizza fara ingredient valid", 20.0f, {""});
            comandaCurenta.adaugaProdus(pizzaInvalida);
        } catch (const IngredientInvalidException& e) {
            std::cerr << "Exceptie ingredient prinsa corect: " << e.what() << "\n";
        }

        try {
            Pizza pizzaPretInvalid("Pizza imposibila", -10.0f, {"Mozzarella"});
            comandaCurenta.adaugaProdus(pizzaPretInvalid);
        } catch (const PretInvalidException& e) {
            std::cerr << "Exceptie pret prinsa corect: " << e.what() << "\n";
        }

    } catch (const PizzaDeliveryException& e) {
        std::cerr << "Eroare PizzaDelivery: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Eroare standard: " << e.what() << "\n";
    }

    return 0;
}