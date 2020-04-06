#include <iostream>
#include"Abonne.hpp"
using namespace std;

// ---------- CONSTRUCTEURS DESTRUCTEUR ---------- //

Abonne::Abonne(string _nom, string _id, Bateau* _bateau):Usager(_nom,_bateau){
    idAbonne = _id;
    place = NULL;
}
Abonne::~Abonne(){
    delete bateau;
    delete place;
}

// ---------- METHODES ---------- //

// Revoie l'identifiant 
string Abonne::getIdAbonne(){
    return idAbonne;
}

// Revoie la place sur laquelle est l'abonné
Place* Abonne::getPlace(){
    return place;
}

// Attribue une place à l'abonné
void Abonne::setPlace(Place* _place){
    place = _place;
}


// Affiche les informations de l'abonne
void Abonne::affiche()const{
    Usager::affiche();
    cout << "Identifiant d'abonne : " << idAbonne << endl;
}



