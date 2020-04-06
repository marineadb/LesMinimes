#include <iostream>
#include "ContratAbo.hpp"

using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //
ContratAbo::ContratAbo(int p, Usager* u,  Date* d) :Contrat(p,u,d,0,0)
{
    place = p;
    usager = u;
    echeance = d;
    duree = 28;

}

ContratAbo::~ContratAbo() 
{
    delete usager;
    delete echeance;
}

// ---------- METHODES ---------- //


// Calcule le montant du contrat en fonction de la place, 
// du bateau, et des services
void ContratAbo::calculePrix(double _majoration, bool _elec, bool _eau) 
{
    prix =  prix = 500 * _majoration;
    if (_elec){
        prix += 5*28;
    }
    if (_eau){
        prix +=5*28;
    }
}

void ContratAbo::affiche(){
    cout << "Abonnement :" << endl;
    Contrat::affiche();
}
