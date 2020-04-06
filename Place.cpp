#include "Place.hpp"
#include <iostream>
using namespace std;

// CONSTRUCTEURS DESTRUCTEUR



Place::Place(int _numPlace, int _tailleMax, bool _services){
    numPlace = _numPlace;
    tailleMax = _tailleMax;
    estLibre = true;
    reduction = 1;
    estAbonne = false;
    services = _services;
    contrat = nullptr;
    
}

Place::~Place(){
    delete usager;
    delete contrat;
}

// METHODES 
// Getters - Setters

int Place::getNum(){
    return numPlace;
}
int Place::getTailleMax(){
    return tailleMax;
}

bool Place::getEstLibre(){
    return estLibre;
}

bool Place::getEstAbonne(){
    return estAbonne;
}

int Place::getReduction(){
    return reduction;
}
bool Place::getServices(){
    return services;
}

Usager* Place::getUsager(){
    return usager;
}

Contrat* Place::getContrat(){
    return contrat;
}


void Place::setContrat(Contrat* c){
    contrat = c;
}
void Place::setUsager(Usager* u){
    usager = u;
    
}
// -----------------------

// Marque la place comme occupée
void Place::occuper(){
    estLibre = false;
}
// Marque la place comme libre
void Place::liberer(){
    cout << "Place " << numPlace << " libérée." << endl;
    estLibre = true;
}
// Marque la place comme étant occupée par un abonné
void Place::abonner(){
    estAbonne = true;

}

void Place::desabonner(){
    estAbonne = false;
}


// Affiche les informations sur la place.
void Place::affiche(){
    cout << "Place normale numéro " << numPlace<< endl;
    if(services){
        cout << "Branchements : oui" << endl;
    }
    else {
        cout << "Branchements : non" << endl;
    }
}

