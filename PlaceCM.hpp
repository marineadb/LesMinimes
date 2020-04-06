#ifndef __PLACECM_H__
#define __PLACECM_H__
#include "Place.hpp"
#include "Bateau.hpp"
#include "Facture.hpp"

class PlaceCM:public Place{
private :
public:
 // CONSTRUCTEURS DESTRUCTEUR
    PlaceCM(int);
    ~PlaceCM();



virtual void affiche();

};
#endif // __PLACECM_H__