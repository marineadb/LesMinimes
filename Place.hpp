#ifndef __PLACE_H__
#define __PLACE_H__
#include <string>
#include "Usager.hpp"
#include "Passager.hpp"
#include "Bateau.hpp"
#include "Contrat.hpp"
#include "Facture.hpp"

class Place{ // ABSTRACT
    protected:
        int numPlace;
        int tailleMax; 
        bool estLibre;
        int reduction;
        Usager* usager;
        bool estAbonne;
        bool services;
        Contrat* contrat;
        

    public : 
       // CONSTRUCTEUR DESTRUCTEUR
        Place(int, int, bool);
        virtual ~Place();

        // METHODES 
        int getNum();
        int getTailleMax();
        bool getEstLibre();
        bool getEstAbonne();
        int getReduction();
        bool getServices();
        Usager* getUsager();
        Contrat* getContrat();
        void setContrat(Contrat*);
        void setUsager(Usager* );
        
        void occuper();
        void liberer();
        void abonner();
        void desabonner();
        
        virtual void affiche();
    
};
#endif // __PLACE_H__