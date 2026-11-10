
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Interface StrategieTri
class StrategieTri {
public:
    virtual void trier(vector<string>& elements) = 0;

    virtual ~StrategieTri() {}
};

// Strategie de tri croissant
class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end());
    }
};

// Strategie de tri decroissant
class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end(), greater<string>());
    }
};

// Strategie de tri par longueur
class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& elements) override {
        sort(elements.begin(), elements.end(),
             [](const string& a, const string& b) {
                 return a.length() < b.length();
             });
    }
};

// Classe GestionnaireTri
class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    // Constructeur
    GestionnaireTri(StrategieTri* s) {
        strategie = s;
    }

    // Modifier la strategie
    void definirStrategie(StrategieTri* s) {
        strategie = s;
    }

    // Executer le tri
    void executerTri(vector<string>& elements) {
        if (strategie != nullptr) {
            strategie->trier(elements);
        }
        else {
            cout << "Aucune strategie de tri definie !" << endl;
        }
    }
};

// Afficher le vecteur
void afficher(const vector<string>& elements) {
    for (const string& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

// Programme principal
int main() {

    vector<string> mots = {
        "Banane", "Chat", "Ordinateur",
        "Livre", "Programmation", "Avion"
    };

    // Creer les strategies
    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur longueur;

    // Creer le gestionnaire
    GestionnaireTri gestionnaire(&croissant);

    // Tri croissant
    cout << "=== Tri croissant ===" << endl;
    gestionnaire.executerTri(mots);
    afficher(mots);

    // Changer vers le tri decroissant
    gestionnaire.definirStrategie(&decroissant);

    cout << "\n=== Tri decroissant ===" << endl;
    gestionnaire.executerTri(mots);
    afficher(mots);

    // Changer vers le tri par longueur
    gestionnaire.definirStrategie(&longueur);

    cout << "\n=== Tri par longueur ===" << endl;
    gestionnaire.executerTri(mots);
    afficher(mots);

    return 0;
}
