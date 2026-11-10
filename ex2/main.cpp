
#include <iostream>
#include <string>
using namespace std;

// Classe abstraite Forme
class Forme {
public:
    virtual void afficher() const = 0;

    virtual ~Forme() {}
};

// Classe Cercle
class Cercle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Cercle." << endl;
    }
};

// Classe Carre
class Carre : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Carre." << endl;
    }
};

// Classe Triangle
class Triangle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Triangle." << endl;
    }
};

// Fabrique de formes
class FabriqueForme {
public:
    static Forme* creerForme(const string& type) {

        if (type == "cercle") {
            return new Cercle();
        }
        else if (type == "carre") {
            return new Carre();
        }
        else if (type == "triangle") {
            return new Triangle();
        }
        else {
            return nullptr;
        }
    }
};

// Programme principal
int main() {

    Forme* f1 = FabriqueForme::creerForme("cercle");
    Forme* f2 = FabriqueForme::creerForme("carre");
    Forme* f3 = FabriqueForme::creerForme("triangle");

    if (f1 != nullptr) {
        f1->afficher();
    }

    if (f2 != nullptr) {
        f2->afficher();
    }

    if (f3 != nullptr) {
        f3->afficher();
    }

    // Liberation de la memoire
    delete f1;
    delete f2;
    delete f3;

    return 0;
}
