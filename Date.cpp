#include "Date.hpp"
#include <iostream>
using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //
Date::Date(int j, int m, int a){
    jour = j;
    mois = m;
    annee = a;

}


Date::Date(){
    jour = 1;
    mois = 1;
    annee = 1;
}

Date::Date(const Date &d){
    jour = d.getJour();
    mois = d.getMois();
    annee = d.getAnnee();
}

Date::~Date(){   
}

// ---------- METHODES ---------- //
//Getters / Setters

int Date::getJour()const{
    return jour;
}

int Date::getMois()const{
    return mois;
}

int Date::getAnnee()const{
 return annee;   
}

// -----------

// Verifie si la date est la même que celle fournie en paramètre
// Aurait pu être remplécée par une surcharge d'opérateur.
bool Date::estEgal(Date* date)const{
    if(jour==date->getJour() && mois==date->getMois() && annee==date->getAnnee()){
        return true;
    }
    else{
        return false;
    }
    

}

// Affiche la date
void Date::affiche() 
{
    cout << jour << "/"<< mois << "/"<< annee << endl;

}

// Ajoute un jour
void Date::jourSuivant() 
{
    if (((mois==1) || (mois == 3) || (mois==5) 
    || (mois==7) || (mois==8) || (mois==10) )&& (jour==31)){
        mois +=1;
        jour = 1;
    }
    else if ((mois == 2) && (jour==28)){
        mois +=1;
        jour = 1;
    }
    else if (((mois == 4) || (mois==6) || (mois==9) || (mois==11)) && (jour==30)){
        mois +=1;
        jour = 1;
    }
    else if ((jour == 31) && (mois==12)){
        annee +=1;
        jour=1;
        mois=1;
    }
    else{
        jour +=1;
    }
}

// Ajoute 28 jours (période de 4 semaines)
void Date::moisSuivant(){
    ajoutJours(28);
}


// Ajoute le nombre de jours indiqué en paramètre
void Date::ajoutJours(int j){
    for (int i=0; i<j; i++){
        jourSuivant();
    }
}

