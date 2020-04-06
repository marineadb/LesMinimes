#include <iostream>
#include"VoilierT1.hpp"
#include "Bateau.hpp"
using namespace std;

VoilierT1::VoilierT1(int _taille, bool _eau, bool _electricite):Bateau(_taille){
    majoration = 1.3;
    eau = _eau;
    electricite = _electricite;
    if ((eau) || (electricite)){
        services = true;
    }
    else {
        services = false;
    }
}
VoilierT1::~VoilierT1(){
}

void VoilierT1::affiche(){
    cout << "Voilier de type 1, de taille " << taille << endl;
    if (services) {
        cout << "Necessite une place disposant de branchements." << endl;
    }
}