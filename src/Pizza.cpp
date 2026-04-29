#include "Pizza.hpp"
#include "Exceptii.hpp"

// constructor default
Pizza::Pizza() : Produs("Pizza Custom", 20.0f) {}

// constructor cu parametri (apelam constructorul clasei de baza)
Pizza::Pizza(const std::string& nume, float pret, const std::vector<std::string>& ingrediente)
    : Produs(nume, pret) {
    for (const auto& ingredient : ingrediente) {
        adaugaIngredient(ingredient);
    }
}

// constructor de copiere
Pizza::Pizza(const Pizza& alta) : Produs(alta), ingrediente(alta.ingrediente) {}

// destructor
Pizza::~Pizza() = default;

// operator=
Pizza& Pizza::operator=(const Pizza& alta) {
    if (this != &alta) {
        Produs::operator=(alta); // apelam operatorul din clasa de baza
        this->ingrediente = alta.ingrediente;
    }
    return *this;
}

// metoda pentru a adauga ingrediente
void Pizza::adaugaIngredient(const std::string& ingredient) {
    if (ingredient.empty()) {
        throw IngredientInvalidException("Ingredientul nu poate fi gol.");
    }

    ingrediente.push_back(ingredient);
}

Produs* Pizza::clone() const {
    return new Pizza(*this);
}

// polimorfism: pretul de baza + 4.5 RON pentru fiecare ingredient
float Pizza::calculeazaPret() const {
    return pretDeBaza + (ingrediente.size() * 4.5f);
}

// suprascriem afisarea pentru a printa si ingredientele
void Pizza::afisare(std::ostream& out) const {
    Produs::afisare(out); // afisam partea de baza (ID, Nume, Pret de baza)
    out << " | Ingrediente: ";
    if (ingrediente.empty()) {
        out << "Niciunul";
    } else {
        for (size_t i = 0; i < ingrediente.size(); ++i) {
            out << ingrediente[i] << (i < ingrediente.size() - 1 ? ", " : "");
        }
    }
    out << " | Pret final: " << calculeazaPret() << " RON";
}

// citirea unei Pizza de la tastatura
std::istream& operator>>(std::istream& in, Pizza& p) {
    // putem face un cast la referinta de tip Produs pentru a apela operatorul >> din baza
    in >> static_cast<Produs&>(p); 
    
    int nr;
    std::cout << "Cate ingrediente are pizza? ";
    in >> nr;
    p.ingrediente.clear(); // curatam ingredientele vechi
    for(int i = 0; i < nr; i++) {
        std::string ing;
        std::cout << "Ingredient " << i + 1 << ": ";
        in >> ing;
        p.adaugaIngredient(ing);
    }
    return in;
}