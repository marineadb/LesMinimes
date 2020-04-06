#ifndef __ABONNE_H__
#define __ABONNE_H__
#include "Usager.hpp"
#include "Place.hpp"
#include "Bateau.hpp"
#include <string>

class Abonne:public Usager{
    private:
    std::string idAbonne;
    Place* place;

    public : 

        // CONSTRUCTEURS DESTRUCTEUR
        Abonne(std::string, std::string,Bateau*);
        ~Abonne();

        // METHODES
        std::string getIdAbonne();
        Place* getPlace();
        void setPlace(Place*);
        virtual void affiche()const;
        
        

};
#endif // __ABONNE_H__