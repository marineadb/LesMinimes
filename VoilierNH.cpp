#include <iostream>
#include"VoilierNH.hpp"
#include "Bateau.hpp"
using namespace std;

VoilierNH::VoilierNH(int _taille):Bateau(_taille){
    eau = false;
    electricite = false;
    services = false;
    majoration = 1;
}
VoilierNH::~VoilierNH(){
}

void VoilierNH::affiche(){
    cout << "Voilier non habitable de taille " << taille << " mètres"<< endl;
}