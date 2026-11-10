
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Interface Observateur
class Observateur {
public:
    virtual void mettreAJour(float temperature,
                             float humidite,
                             float pression) = 0;

    virtual ~Observateur() {}
};

// Classe StationMeteo (Sujet)
class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:
    // Ajouter un observateur
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    // Supprimer un observateur
    void supprimerObservateur(Observateur* o) {
        observateurs.erase(
            remove(observateurs.begin(), observateurs.end(), o),
            observateurs.end()
        );
    }

    // Notifier tous les observateurs
    void notifierObservateurs() {
        for (Observateur* o : observateurs) {
            o->mettreAJour(temperature, humidite, pression);
        }
    }

    // Modifier les donnees meteorologiques
    void definirMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;

        cout << "\nNouvelle mesure meteorologique !" << endl;

        notifierObservateurs();
    }
};

// Observateur Temperature
class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Temperature : " << t << " C" << endl;
    }
};

// Observateur Humidite
class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Humidite : " << h << " %" << endl;
    }
};

// Observateur Pression
class AffichagePression : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Pression : " << p << " hPa" << endl;
    }
};

// Programme principal
int main() {

    StationMeteo station;

    AffichageTemperature affichageTemp;
    AffichageHumidite affichageHum;
    AffichagePression affichagePress;

    // Ajouter les observateurs
    station.ajouterObservateur(&affichageTemp);
    station.ajouterObservateur(&affichageHum);
    station.ajouterObservateur(&affichagePress);

    // Premier changement des donnees
    station.definirMesures(25.5, 60, 1013);

    // Deuxieme changement des donnees
    station.definirMesures(30, 45, 1010);

    // Supprimer un observateur
    station.supprimerObservateur(&affichageHum);

    // Troisieme changement des donnees
    station.definirMesures(22, 70, 1015);

    return 0;
}
