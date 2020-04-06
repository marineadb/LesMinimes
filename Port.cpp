#include "Port.hpp"
#include <iostream>
#include <typeinfo>
#define PLACES_MAX 10
using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //

Port::Port(){
    int count = 1;
    // Création des places 

    for (int i = 0; i < PLACES_MAX; i++)
    {
        Place* p = new Place(count, 10, false);
        places[p->getNum()] = p;
        count+=1;
    }
        for (int i = 0; i < PLACES_MAX; i++)
    {
        Place* p = new Place(count, 25, false);
        places[p->getNum()] = p;
        count+=1;
    }
    for (int i = 0; i < PLACES_MAX; i++)
    {
        Place* p = new Place(count, 25, true);
        places[p->getNum()] = p;
        count+=1;
    }
    for (int i = 0; i < PLACES_MAX; i++)
    {
        Place* p = new Place(count, 150, true);
        places[p->getNum()] = p;
        count+=1;
    }
    for (int i=0; i<PLACES_MAX;i++){
        PlaceCM* p = new PlaceCM(count);
        places[p->getNum()] = p;
        count+=1;

    }
    countAbo = 0;

}

Port::~Port(){

}




// ---------- METHODES ---------- //
// Getters - Setters

Place* Port::getPlace(int _numPlace){
    if (_numPlace> places.size()){
        cout << "Cette place n'extiste pas" << endl;
        return NULL;
    } 
    else{
        return places[_numPlace];
    }
}
vector<int> Port::getPlacesDispo(){
    return placesDispo;
}

Abonne* Port::getAbonne(std::string idAbo){
    return abonnes[idAbo];
}
vector<int> Port::GetplacesOccupees(){
    return placesOccupees;
}

Facture* Port::getFacture(int _numPlace){
    Facture* f = places[_numPlace]->getContrat()->creerFacture();
    f->setID(factures.size()+1);
    return f;
}  
int Port::getNbDeparts(){
    return departs.size();

}

// Definit les places dont le contrat arrive à échéance aujourd'hui
void Port::setDeparts(Date* d) 
{
    for (int i=0; i<placesOccupees.size(); i++){
        Place* p = places[placesOccupees[i]];
        Contrat* c = p->getContrat();
        Date* date = c->getEcheance();
        if (date->estEgal(d)){
            departs.push_back(placesOccupees[i]);
        }
    }
}

// Definit les places disponibles pour un bateau
bool Port::setPlacesDispo(Bateau* b){
    placesDispo.clear();
    if (b->getServices()){
        itPlace = places.begin();
        while(itPlace != places.end()){
            if ((itPlace->second->getEstLibre()) && (itPlace->second->getTailleMax()> b->getTaille()) 
            && (itPlace->second->getServices())){
                placesDispo.push_back(itPlace->first);
            }
            itPlace++;
        }
    }
    else{
        itPlace = places.begin();
        while(itPlace != places.end()){
            if ((itPlace->second->getEstLibre()) && (itPlace->second->getTailleMax()> (b->getTaille()))){   
               placesDispo.push_back(itPlace->first);
            }
            itPlace++;
        }
    }
    if (placesDispo.size()>0){
        return true;
    }
    
    else{
        return false;
    }
}

// CREATION D'OBJETS

Bateau* Port::creerBateau(){
    double tailleBateau; 
    bool eau;
    bool elec;
    bool services;
    int reponse;
    cout << "Taille du bateau ? (en mètres)" << endl;
    cin >> tailleBateau;
    if (tailleBateau>10){
        bool verif = false;
        while (!verif){
            cout << "Accès à l'eau necessaire? \n 1 pour oui\n 2 pour non " << endl;
            cin >> reponse;
            switch (reponse){
                case 1:
                eau = true;
                verif = true;
                break;
                case 2:
                eau = false;
                verif = true;
                break;
                default:
                cin.clear();
                cin.ignore();
                cout << "Reponse invalide, recommencez : " << endl;
            }
        }
        verif = false;
        while (!verif){
            cout << "Accès à l'electricite necessaire? \n 1 pour oui\n 2 pour non" << endl;
            cin >> reponse;
            switch (reponse){
                case 1:
                elec = true;
                verif = true;
                break;
                case 2:
                elec = false;
                verif = true;
                break;
                default:
                cin.clear();
                cin.ignore();
                cout << "Reponse invalide, recommencez : " << endl;
            }
        }
        if (tailleBateau > 25){
            VoilierT2* v = new VoilierT2(tailleBateau, eau, elec);
            return v;
        }
        else{
            
            VoilierT1* v = new VoilierT1(tailleBateau,eau,elec);
            return v;
        }
    }
    else {
        VoilierNH* v = new VoilierNH(tailleBateau);
        return v;
    }
}
Abonne* Port::creerAbonne() 
{
    string nom;
    cout << "Nom de l'abonné ?" << endl;
    cin >> nom;
    Bateau* bateau = creerBateau();
    string id = to_string(countAbo+1);
    string premiereLettre = nom.substr(0,1);
    id += premiereLettre;
    Abonne* a = new Abonne(nom, id, bateau);
    return a;
}

Passager* Port::creerPassager(){
    string nom;
    cout << "Nom du passager" << endl;
    cin >> nom;
    Bateau* bateau = creerBateau();
    Passager* p = new Passager(nom, bateau);
    return p;
}

// Ajouts dans les listes

// Ajoute un abonné au port
void Port::ajoutAbonne(Abonne *_abonne, int _numPlace, Date _date) 
{
    _abonne->setPlace(places[_numPlace]);
    abonnes[_abonne->getIdAbonne()] = _abonne;
    places[_numPlace]->setUsager(_abonne);
    places[_numPlace]->occuper();
    places[_numPlace]->abonner();
    ajoutPlaceOccupee(_numPlace);
    countAbo +=1;
    Date echeance = _date;
    echeance.moisSuivant();
    Date* _echeance = new Date(echeance);
    double _majoration = _abonne->getBateau()->getMajoration();
    bool _eau = _abonne->getBateau()->getEau();
    bool _elec = _abonne->getBateau()->getElectricite();
    ContratAbo* c = new ContratAbo(_numPlace, _abonne, _echeance);
    c->calculePrix(_majoration,_elec,_eau);
    places[_numPlace]->setContrat(c);
    cout << "Ajoute l'abonné à la liste, Identifiant : " << _abonne->getIdAbonne()<< endl;
}

// Ajoute un passager
void Port::ajoutPassager(Passager* _passager, int _numPlace, Date  _date, int jours){
    places[_numPlace]->setUsager(_passager);
    places[_numPlace]->occuper();
    ajoutPlaceOccupee(_numPlace);
    Date echeance = _date;
    echeance.ajoutJours(jours);
    Date* _echeance = new Date(echeance);
    double _majoration = _passager->getBateau()->getMajoration();
    bool _eau = _passager->getBateau()->getEau();
    bool _elec = _passager->getBateau()->getElectricite();
    int reduc = places[_numPlace]->getReduction();
    Contrat* c = new Contrat(_numPlace, _passager, _echeance, jours, reduc);
    c->calculePrix(_majoration, _eau, _elec);
    places[_numPlace]->setContrat(c);
    cout << "Nouveau passager dans le port à la place : " << _numPlace <<endl;

}


// Ajoute une place occupée
void Port::ajoutPlaceOccupee(int _NumP){
    placesOccupees.push_back(_NumP);
}
    
// Ajoute une place dont le contrat est arrivé à échéance
void Port::ajoutDepart(int _NumP){
    departs.push_back(_NumP);
}

// Archive une facture.
void Port::ajoutFacture(Facture* f){
    factures[f->getIdFacture()]=f;
}



// Retrait des listes

void Port::retirePlaceOccupee(int _numP){
    itP = placesOccupees.begin();
    while (itP != placesOccupees.end()){
        if (*itP == _numP){
            placesOccupees.erase(itP);
        }
    }
}
void Port::retireDepart(int _numP){
    itP = departs.begin();
    while (itP != departs.end()){
        if (*itP == _numP){
            departs.erase(itP);
        }
    }
}


void Port::retireAbonne(string _idAbonne){
    Abonne* a=abonnes[_idAbonne];
    Place* p = a->getPlace();
    int _numPlace = p->getNum();
    places[_numPlace]->liberer();
    places[_numPlace]->desabonner();
    retirePlaceOccupee(_numPlace);
    delete abonnes[_idAbonne];
    abonnes.erase(_idAbonne);
}

void Port::retirePassager(int _numPlace){
    places[_numPlace]->liberer();
    retirePlaceOccupee(_numPlace);

}

// recherche et affichage

bool Port::trouveAbonne(string _idAbonne){
    itAbonne=abonnes.begin();
    Abonne* resultat = NULL;

    // On vérifie que le numéro fourni en paramètre existe.
    while (itAbonne != abonnes.end() && _idAbonne != itAbonne->second->getIdAbonne()){
        itAbonne ++;
    }
    if (itAbonne != abonnes.end()){
        return true;
    }

    return false;
}


bool Port::verifPlaceDispo(int _numPlace){
    itP = placesDispo.begin();
    while (itP != placesDispo.end()){
        if (*itP == _numPlace){
            return true;
        }
        itP++;
    }
    return false;
}


void Port::afficheDeparts(){
    if (departs.size()>=1){
        cout << "\n --> Contrats arrivant à échéance aujourd'hui:" << endl;
        for (int i=0; i< departs.size(); i++){
            Place* p = places[departs[i]];
            p->getContrat()->affiche();
            cout << "Place : " << p->getNum() << "\n" << endl;

        }
    }
        else{
            cout << "Pas de contrats arrivant à échéance aujourd'hui." << endl;
        }
}

 
void Port::afficheAbonnes(){
    itAbonne=abonnes.begin();
    while (itAbonne != abonnes.end()){
        itAbonne->second->affiche();
        itAbonne++;
    }
}

void Port::afficheContrats(){
    for (int i=0; i<placesOccupees.size(); i++){
        Place* p = places[placesOccupees[i]];
        Contrat* c = p->getContrat();
        c->affiche();
        cout << "--" <<endl;
    }
}