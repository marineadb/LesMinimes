#include <iostream>
#include "Contrat.hpp"

using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //
Contrat::Contrat(int p, Usager* u, Date* d, int _duree, int _reduc) 
{
    place = p;
    usager = u;
    echeance = d;
    duree = _duree;
    reduc = _reduc;
}


Contrat::~Contrat() 
{
    delete usager;
    delete echeance;
    
}

// ---------- METHODES ---------- //


//Getters / Setters
int Contrat::getPlace() 
{
  return place;  
}

Usager* Contrat::getUsager() 
{
    return usager;
}

Date* Contrat::getEcheance() 
{
    return echeance;
}

double Contrat::getPrix(){
    return prix;
}
// --------------------


// Calcule le montant du contrat en fonction de la place, 
// du bateau, et des services
void Contrat::calculePrix(double _majoration, bool _elec, bool _eau)
{
    prix = 20 * _majoration;
    if (_elec){
        prix += 5;
    }
    if (_eau){
        prix +=5;
    }
    prix = prix/reduc;
    prix = prix * duree;
}

// Affiche les informations du contrat
void Contrat::affiche(){
    cout << "Contrat avec Mr/Mme : ";
    cout << usager->getNom() << endl;
    cout << "Actuellement sur la place : ";
    cout << place << endl;
    cout << "Arrivant à échéance le ";
    echeance->affiche();
    cout << "Montant : " << prix << endl;
}


// Renouvelle le contrat pour le nombre de jours placé en paramètre.
void Contrat::renouveler(int jours){
    echeance->ajoutJours(jours);
    cout << "Contrat renouvelé, prochain paiement le ";
    echeance->affiche();
}

// Crée la facture correspondant au contrat.
Facture* Contrat::creerFacture(){
    Facture* facture = new Facture (usager->getNom(),place,echeance,prix);
    return facture;
}