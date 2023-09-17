#include <iostream>
#include <string>
using namespace std;

static double consoElectrique{ 6.6 };
static double consoLiquide{ 12.5 };

class CigaretteElectronique {
    double batterie;
    double capacite;
    double puissance;
    double liquide;
    double contenance;
    bool etat;
    


public:
    CigaretteElectronique();
    CigaretteElectronique(double batterieCE, double capaciteCE, double puissanceCE, double liquideCE, double contenanceCE, bool etatCE);
    bool allumer();
    bool eteindre();
    void tirer();
    void remplir();
    void charger();
    double get_batterie();
    double get_liquide();
    bool get_etat();
};

CigaretteElectronique::CigaretteElectronique() : batterie{0}, capacite{0}, puissance{0}, liquide{0}, contenance{0}, etat{0} {}
CigaretteElectronique::CigaretteElectronique(double batterieCE, double capaciteCE, double puissanceCE, double liquideCE, double contenanceCE, bool etatCE) :
    batterie{ batterieCE }, capacite{ capaciteCE }, puissance{ puissanceCE }, liquide{ liquideCE }, contenance{ contenanceCE }, etat{ etatCE }


{}

double CigaretteElectronique::get_batterie() { return batterie; }
double CigaretteElectronique::get_liquide() { return liquide; }
bool CigaretteElectronique::get_etat() { return etat; }

    bool  CigaretteElectronique::eteindre() {
        if (etat = false) {
            cout << "La cigarette est eteinte" << endl;
        }
        return etat;
    }

    bool  CigaretteElectronique::allumer() {
        if (etat = true) {
            cout << "La cigarette est allume" << endl;
        }
        return etat;
    }
    
    void CigaretteElectronique::tirer() {
        if (get_etat() == true) {
            if (batterie >= 0 && liquide >= 0) {
                
                if (batterie <= consoElectrique)
                {
                    cout << "Plus de batterie !, vous devez recharger." << endl;
                    batterie = 0;
                }
                else if (liquide <= consoLiquide) {

                    cout << "Plus de liquide !, vous devez recharger." << endl;
                    liquide = 0;

                }
                else
                {
                    batterie -= consoElectrique;
                    liquide -= consoLiquide;
                    
                }

            }

        }
        else {
            cout << "La cigarette est eteinte !" << endl;
        }
    }

    void CigaretteElectronique::remplir() {
        liquide = 100;
       
    }

    void CigaretteElectronique::charger() {
        batterie = 100;
        
        
    }

    int main() {
        CigaretteElectronique CE{ 100, 4000, 65, 100, 5, false };
        
        char choix = 0;
        while (true)
        {
            cout << "===Choisir===" << endl;
            cout << "a- Allumer" << endl;
            cout << "c- Charger" << endl;
            cout << "e- Eteindre" << endl;
            cout << "r- Remplir" << endl;
            cout << "t- Tirer" << endl;
            cout << "f- Fin du programme" << endl;

            cin >> choix;
            cout << endl;
            switch (choix)
            {
            case 'a':
                CE.allumer();
                break;

            case 'c':
                CE.charger();
                break;

            case 'e':
                CE.eteindre();
                break;
            case 'r':
                CE.remplir();
                break;

            case 't':
                CE.tirer();
                break;

            case 'f':
                system("PAUSE");
                return 0;
                break;

            default :
               
                break;
            }
            cout << "Le niveau de la batterie est de "<< CE.get_batterie() << " %" << endl;
            cout << "Le niveau du liquide est de " << CE.get_liquide() << " %" << endl;
            cout << endl;

            
        }  
    }
