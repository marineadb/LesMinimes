#ifndef __PASSAGER_H__
#define __PASSAGER_H__
#include "Usager.hpp"
#include "Bateau.hpp"
#include "Contrat.hpp"
#include <string>

class Passager:public Usager{
    private :     
    public: 
        Passager (std::string,Bateau*);
        ~Passager();
        virtual void affiche()const;
};
#endif // __PASSAGER_H__