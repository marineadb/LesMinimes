#include <iostream>
#include "Date.hpp"
#include "GestionPort.hpp"
using namespace std;

// FONCTIONS

void afficheMenu(){
    cout << "\n ----------- Port des Minimes - Bienvenue ----------- \n" << endl;
    cout << "* * Que voulez vous faire? * * \n" << endl;
    cout << " 1   pour une arrivée au port" << endl;
    cout << " 2   pour afficher les contrats arrivant à echeance aujourd'hui" << endl;
    cout << " 3   pour un paiement de facture" << endl;
    cout << " 4   pour afficher les places occupées actuellement " << endl;
    cout << " 5   pour afficher tous les contrats en cours et leurs échéances" << endl;
    cout << " 6   pour afficher les places disponibles pour un type de bateau " << endl;
    cout << " 7   pour afficher les abonnés présents dans le port" << endl;
    cout << " 8   pour passer au jour suivant" << endl;
    cout << " 9   pour afficher la date du jour" << endl;
    cout << " 10   pour quitter la gestion du port" << endl;
    cout << "\n ----------------------------------------------------- \n" << endl;
}



// MAIN 


int main(){
    Date dateDuJour(1,4,2020); // Initialise la date du jour
    GestionPort port(dateDuJour); // Création du port
    port.init(); // Initialisation du port
    int choix;
    while (true){
        afficheMenu();
            cin >> choix;
        switch (choix)
        {
        case 1 :
            port.arrivee();
            break;
        case 2: 
            port.afficheEcheances();
            break ; 
        case 3 : 
            port.paiement();
            break; 
        case 4 :
            port.affichePlacesOccupees();
            break;
        case 5 :
            port.afficheContrats();
            break;
        case 6 : 
            port.placesLibres();
            break;
        case 7 : 
            port.afficheAbonnes(); 
            break;
        case 8 : 
            port.jourSuivant();
            break;
        case 9 : 
            port.afficheDate();
            break;
        case 10 : 
            exit(0);
        default:
            cin.clear();
            cin.ignore();
            cout << "Choix invalide, recommencez :" << endl;
            break;
        }

    }


}