
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    // Parametres de configuration
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    // Constructeur prive
    Configuration() {
        cheminFichier = "C:/Users/Documents/config.txt";
        utilisateur = "admin";
        motDePasse = "123456";
    }

    // Supprimer le constructeur de copie
    Configuration(const Configuration&) = delete;

    // Supprimer l'operateur d'affectation
    Configuration& operator=(const Configuration&) = delete;

public:
    // Methode statique pour obtenir l'unique instance
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    // Afficher les parametres
    void afficherParametres() const {
        cout << "=== Configuration ===" << endl;
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {

    // Recuperer l'unique instance
    Configuration& config1 = Configuration::getInstance();

    // Afficher les parametres
    config1.afficherParametres();

    cout << endl;

    // Recuperer une deuxieme fois la meme instance
    Configuration& config2 = Configuration::getInstance();

    // Verifier que les deux references designent le meme objet
    if (&config1 == &config2) {
        cout << "Les deux references designent la meme instance." << endl;
    } else {
        cout << "Les instances sont differentes." << endl;
    }

    return 0;
}
