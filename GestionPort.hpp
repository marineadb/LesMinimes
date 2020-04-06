#ifndef __GESTIONPORT_H__
#define __GESTIONPORT_H__
#include "Port.hpp"

class GestionPort{
    protected: 
        Date date;
        Port lesMinimes;

    public : 
    GestionPort( Date);
    ~GestionPort();

    void init();

    void afficheDate();
    void affichePlacesOccupees();
    void afficheAbonnes();
    void afficheEcheances();
    void afficheContrats();
    bool affichePlacesLibres(Bateau*);


    void jourSuivant();

    void arrivee();
    void arriveeAbonne();
    void arriveePassager();

    void paiement();
    void departAbonne();
    void departPassager();
    
    void placesLibres();
    void emissionFacture(int);
    

};
#endif // __GESTIONPORT_H__