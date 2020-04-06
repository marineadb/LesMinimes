#ifndef __PORT_H__
#define __PORT_H__

#include"Date.hpp"
#include"VoilierNH.hpp"
#include"VoilierT1.hpp"
#include"VoilierT2.hpp"
#include"PlaceCM.hpp"
#include "Facture.hpp"
#include "Passager.hpp"
#include "Usager.hpp"
#include "Abonne.hpp"
#include "Contrat.hpp"
#include "ContratAbo.hpp"
#include <vector>
#include <map>
#include <string>

// ---------------------------------//


 typedef std::map<std::string, Abonne*> map_abonnes;
 typedef std::map<int,Place*> map_places;
 typedef std::map<int,Facture*> map_factures;

class Port{
private:
    map_abonnes abonnes;
    map_places places;
    map_factures factures;
    map_abonnes::iterator itAbonne;
    map_places::iterator itPlace;
    map_factures::iterator itFacture;
    int countAbo;
    std::vector<int> placesDispo;
    std::vector<int> placesOccupees;
    std::vector<int> departs;
    std::vector<int>::iterator itP;


public:
    Port();
    ~Port();
    void creePlaces();
    

    std::vector<int> getPlacesDispo();
    Place* getPlace(int);
    Abonne* getAbonne(std::string);
    std::vector<int> GetplacesOccupees();
    Facture* getFacture(int);
    int getNbDeparts();
    bool setPlacesDispo(Bateau *);
    void setDeparts(Date*);
    
    Bateau* creerBateau();
    Abonne* creerAbonne();
    Passager* creerPassager();

    void ajoutAbonne(Abonne*, int, Date);
    void ajoutPassager(Passager*, int, Date, int);
    void ajoutPlaceOccupee(int);
    void ajoutDepart(int);
    void ajoutFacture(Facture*);
    
    void retirePlaceOccupee(int);
    void retireDepart(int);
    void retireAbonne(std::string);
    void retirePassager(int);
    
    bool trouveAbonne(std::string);
    bool verifPlaceDispo(int);  
    void afficheAbonnes();
    void afficheDeparts();
    void afficheContrats();
    
};
#endif // __PORT_H__