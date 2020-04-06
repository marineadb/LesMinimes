#ifndef __BATEAU_H__
#define __BATEAU_H__


class Bateau{ // ABSTRACT
protected: 
    int taille;
    bool eau;
    bool electricite;
    bool services;
    double majoration;

public:
Bateau(int);
virtual ~Bateau();
int getTaille();
bool getElectricite();
bool getEau();
double getMajoration();
bool getServices();

virtual void affiche() = 0;
};

#endif // __BATEAU_H__
