#include <iostream>
#include"Passager.hpp"
#include"Usager.hpp"
#include "Bateau.hpp"
using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //
Passager::Passager (string _nom, Bateau* _bateau):Usager(_nom, _bateau){
}
Passager::~Passager(){
}

// ---------- METHODES ---------- //
void Passager::affiche()const{
    Usager::affiche();
}