#include <iostream>
#include"Usager.hpp"
using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //

Usager::Usager(string _nom, Bateau* _bateau){
    nom = _nom;
    bateau = _bateau;
}

Usager::~Usager() 
{
    delete bateau;

}

// ---------- METHODES ---------- //
// GETTERS SETTERS 
string Usager::getNom(){
    return nom;
}
Bateau* Usager::getBateau(){
    return bateau;
}
void Usager::setBateau(Bateau* _bateau){
    bateau = _bateau;
}

void Usager::affiche() const{
    cout << "Nom : " << nom << endl;
    }

