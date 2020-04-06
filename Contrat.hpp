#ifndef __CONTRAT_H__
#define __CONTRAT_H__

#include "Date.hpp"
#include "Usager.hpp"
#include "Facture.hpp"
#include <string>


class Contrat{
    protected: 
        int place;
        Usager* usager;
        Date* echeance;
        int duree; // en jours
        int reduc; // 1 si place classique, 2 si place CM
        double prix;


    public:
        Contrat(int, Usager*, Date*, int, int);
        virtual ~Contrat();

        int getPlace();
        Usager* getUsager();
        Date* getEcheance();
        double getPrix();

        void calculePrix(double, bool, bool);
        void affiche();
        void renouveler(int);
        Facture* creerFacture();
    
};
#endif // __CONTRAT_H__