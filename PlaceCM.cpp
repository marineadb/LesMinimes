#include "PlaceCM.hpp"
#include"Place.hpp"
#include "Bateau.hpp"
#include "Facture.hpp"
#include <iostream>
using namespace std;

PlaceCM::PlaceCM(int _numPlace):Place(_numPlace,150, false){
    reduction = 2;
}


PlaceCM::~PlaceCM(){
}

void PlaceCM::affiche(){
    cout << "Place sur corps mort numéro : " << numPlace<< endl;
}

