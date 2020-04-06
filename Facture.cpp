#include <iostream>
#include"Facture.hpp"

using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //

Facture::Facture(string _nom, int _numPlace, Date* _echeance, double _prix){
    nomUsager = _nom;
    numPlace = _numPlace;
    echeance = _echeance;
    prix = _prix;
    paye = false;
}

Facture::~Facture(){
    delete echeance;
    cout << "Supprime facture" << endl;
}

// ---------- METHODES ---------- //
//Getters / Setters
int Facture::getNumPlace(){
    return numPlace;
}
int Facture::getIdFacture(){
    return IdFacture;
}
double Facture::getPrix(){
    return prix;
}
string Facture::getNomUsager(){
    return nomUsager;
}
Date* Facture::getEcheance(){
    return echeance;
}

void Facture::setID(int _id){
    IdFacture = _id;
}
void Facture::setPrix(int jours){
    prix = prix*jours;
}
void Facture::setEcheance(Date* _echeance){
    echeance = _echeance;
}



// Marque la facture comme payée
void Facture::payer(){
    paye = true;
}

// Affiche la facture
void Facture::affiche(){
    cout << "----- FACTURE -------" << endl;
    cout << "Nom de l'usager :" << nomUsager << endl;
    cout << "Place : " << numPlace << endl;
    cout << "Montant : "<< prix << endl;
    if (paye){
        cout << "Réglé."<< endl;
    }
    else{
        cout << "Echeance : ";
        echeance->affiche();
    }
    cout << "----------------------" << endl;
}