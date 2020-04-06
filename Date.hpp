#ifndef __DATE_H__
#define __DATE_H__

class Date{
private : 
    int jour;
    int mois;
    int annee;

public:
Date(int, int, int);
Date();
Date(const Date&);
~Date();

int getJour() const;
int getMois() const;
int getAnnee() const;
bool estEgal(Date*) const;

void affiche();
void jourSuivant();
void moisSuivant();
void ajoutJours(int);

};

#endif // __DATE_H__