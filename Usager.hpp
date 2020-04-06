#ifndef __USAGER_H__
#define __USAGER_H__
#include <string>
#include"Bateau.hpp"


class Usager{
    protected:
        std::string nom;
        Bateau* bateau;
        
    public:
        Usager(std::string, Bateau*);
        ~Usager();

        std::string getNom();
        Bateau* getBateau();
        void setBateau(Bateau*);
        void affiche() const;
};
#endif // __USAGER_H__