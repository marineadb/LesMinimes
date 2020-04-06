#include <iostream>
#include"VoilierT2.hpp"
#include "Bateau.hpp"
using namespace std;

VoilierT2::VoilierT2(int _taille, bool _eau, bool _electricite):Bateau(_taille){
    eau = _eau;
    electricite = _electricite;
    majoration = 1.6;
    if ((eau) || (electricite)){
        services = true;
    }
    else {
        services = false;
    }

}
VoilierT2::~VoilierT2(){
}

void VoilierT2::affiche(){
    cout << "Voilier de type 2, de taille " << taille << endl;
    if (services) {
        cout << "Necessite une place disposant de branchements." << endl;
    }
}