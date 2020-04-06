#ifndef __FACTURE_H__
#define __FACTURE_H__
#include"Date.hpp"

class Facture{
protected:
    std::string nomUsager;
    int IdFacture;
    Date* echeance;
    double prix;
    int numPlace;
    bool paye;

public:
    Facture(std::string _nom, int _numPlace, Date* _echeance, double _prix);
    ~Facture();
    
    int getNumPlace();
    int getIdFacture();
    double getPrix();
    std::string getNomUsager();
    Date* getEcheance();
    void setID(int);
    void setPrix(int); 
    void setEcheance(Date*);
    
    void payer();
    void affiche();
};
#endif // __FACTURE_H__