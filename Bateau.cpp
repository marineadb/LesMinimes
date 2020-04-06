#include <iostream>
#include"Bateau.hpp"
using namespace std;

Bateau::Bateau(int _taille){
    taille = _taille;
}
Bateau::~Bateau(){
}

int Bateau::getTaille(){
    return taille;
}

double Bateau::getMajoration(){
    return majoration;
}
bool Bateau::getEau(){
    return eau;
}

bool Bateau::getElectricite(){
    return electricite;
}

bool Bateau::getServices(){
    return services;
}