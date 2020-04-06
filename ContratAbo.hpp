#ifndef __CONTRATABO_H__
#define __CONTRATABO_H__
#include "Contrat.hpp"
#include "Facture.hpp"

class ContratAbo : public Contrat{
    public:
    ContratAbo(int , Usager*,  Date*);
    ~ContratAbo();

    void calculePrix(double, bool, bool);
    void affiche();
    

};
#endif // __CONTRATABO_H__