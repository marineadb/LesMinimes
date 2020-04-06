#include <iostream>
#include "GestionPort.hpp"
#include "Abonne.hpp"
#include "Facture.hpp"
#include "Usager.hpp"
using namespace std;

// ---------- CONTRUCTEUR - DESTRUCTEUR ---------- //
GestionPort::GestionPort( Date  _date){
    lesMinimes = Port();
    date = _date;
}

GestionPort::~GestionPort(){

}

// ---------- METHODES ---------- //

// Initialise le port avec des abonnés et passagers
void GestionPort::init(){
    cout << " \n ------- INITIALISATION -------" << endl;
    VoilierNH* v1 = new VoilierNH(8);
    Abonne* a1 = new Abonne("Dupont", "1D", v1 );
    lesMinimes.ajoutAbonne(a1, 3, date);
    date.ajoutJours(8);
    VoilierT1* v2 = new VoilierT1(18, true, true);
    Abonne* a2 = new Abonne("Martin", "2M", v2);
    lesMinimes.ajoutAbonne(a2,21, date);
    date.ajoutJours(12);
    VoilierT2* v3 = new VoilierT2(35,true,true);
    Abonne* a3 = new Abonne("Bolteau", "3B", v3);
    lesMinimes.ajoutAbonne(a3,33, date);
    date.ajoutJours(2);
    VoilierNH* v4 = new VoilierNH(9);
    Passager* p1 = new Passager("Cornier", v4);
    lesMinimes.ajoutPassager(p1, 45, date, 6);
    date.ajoutJours(2);
    VoilierT1* v5 = new VoilierT1(15, false, false);
    Passager* p2 = new Passager("Carriat", v5);
    lesMinimes.ajoutPassager(p2,11,date, 5);
    cout << " ------------------------------ " << endl;
}



// Affiche les places occupées en ce moment
void GestionPort::affichePlacesOccupees() 
{
    vector<int> p = lesMinimes.GetplacesOccupees();
    cout << "\n  --> Places occupees actuellement : "<<endl;
    for (int i=0; i< p.size(); i++){
        cout << p[i] << " ";
    }

}

// Affiche les places libres pour le bateau placé en paramètre
bool GestionPort::affichePlacesLibres(Bateau* b){
    bool placesLibres = lesMinimes.setPlacesDispo(b);
    if(placesLibres){
        cout << "\n --> Places disponibles pour ce bateau : " << endl;
        vector<int> v = lesMinimes.getPlacesDispo();
        for (int i=0; i<v.size(); i++){
            Place* a =lesMinimes.getPlace(v[i]);
            a->affiche();
            cout << "--"<< endl;
        }
    }
    else{
        cout << " \n --> Pas de places libre pour ce bateau" << endl;
    }
    return placesLibres;
}

//Affiche la date du jour
void GestionPort::afficheDate(){
    cout << "\n ---> Nous sommes le ";
    date.affiche();
    cout << "\n";
}

// Affiche les abonnés présents dans le port
void GestionPort::afficheAbonnes() 
{
    cout << "Abonnés actuellement présents dans le port : " << endl;
    lesMinimes.afficheAbonnes();
    
}

// Affiche les contrats arrivant à échéance aujourd'hui
void GestionPort::afficheEcheances(){
    lesMinimes.afficheDeparts();
}

void GestionPort::afficheContrats(){
    cout << "\n --> Contrats en cours : \n" << endl;
    lesMinimes.afficheContrats();
}

// Verifie que tous les paiements du jour ont été éffectués
// passe au jour suivant si c'est le cas.
void GestionPort::jourSuivant() 
{
    if (lesMinimes.getNbDeparts() != 0){
        cout << "Vous ne pouvez pas passer au jour suivant, des paiements n'ont pas été effectués." << endl;
    }
    else {
        date.jourSuivant();
        cout << "Nous sommes maintenant le " ;
        date.affiche();
        Date* d = new Date(date);
        lesMinimes.setDeparts(d);
    }
    
}

// Oriente vers l'arrivée d'un passager ou d'un abonné
void GestionPort::arrivee() 
{
    cout << "\n----- Arrivee d'un Usager -----" << endl;
    int choix = 0;
    while (choix != 1 && choix !=2){
        cout << " 1 pour un nouvel abonné \n 2 pour un nouveau passager" << endl;
        cin >> choix;
        switch (choix)
        {
        case 1: 
            arriveeAbonne();
            break;
        case 2 : 
            arriveePassager();
            break;
        
        default:
            cout << "Choix invalide, recommencez : " << endl;
            cin.clear();
            cin.ignore();
            break;
        }
    } 
}

// Gère l'arrivée de l'abonné
void GestionPort::arriveeAbonne(){
    Abonne* a = lesMinimes.creerAbonne();
    bool verifPlace = affichePlacesLibres(a->getBateau());
    if (verifPlace){
        int place;
        bool verif = false;
        while (!verif){
            cout << "Quelle place choisissez vous?" << endl;
            cin >> place;
            if (lesMinimes.verifPlaceDispo(place)){
                lesMinimes.ajoutAbonne(a,place,date);
                verif = true;
            }
            else {
                cout << "Choix invalide, recommencez :" << endl;
            }   
        }
    }

}
// Gere l'arrivée du passager
void GestionPort::arriveePassager(){
    Passager* p = lesMinimes.creerPassager();
    bool verifPlace = affichePlacesLibres(p->getBateau());
    if (verifPlace){
        int place;
        int jours;
        bool verif = false;
        while (!verif){
            cout << "Quelle place choisissez vous?" << endl;
            cin >> place;
            if (lesMinimes.verifPlaceDispo(place)){
                cout << "Combien de jours restez vous au port?" << endl;
                cin >> jours;
                lesMinimes.ajoutPassager(p,place,date,jours);
                verif = true;
            }
            else {
                cout << "Choix invalide, recommencez :" << endl;
            } 
        }
    }
             
}

// Oriente vers le paiement d'un passager ou d'un abonné
void GestionPort::paiement(){
    cout << "\n----- Paiement d'un Usager -----" << endl;
    if (lesMinimes.getNbDeparts()>0){
        int choix = 0;
        while (choix != 1 && choix !=2){
            cout << " 1 pour abonné \n 2 pour un passager" << endl;
            cin >> choix;
            switch (choix)
            {
                case 1: 
                    departAbonne();
                    break;
                case 2 : 
                    departPassager();
                    break;
                
                default:
                    cout << "Choix invalide, recommencez : " << endl;
                    cin.clear();
                    cin.ignore();
                    break;
            }
        } 
    }
    else{
        cout << "Pas de paiements a réaliser aujourd'hui." << endl;
    }
    
}

// Permet le paiement d'un abonné et son départ ou son renouvellement de contrat
void GestionPort::departAbonne(){
    cout << "Identifiant Abonne ?" << endl;
    string id;
    cin >> id;
    int place;
    if (lesMinimes.trouveAbonne(id)){
        place = lesMinimes.getAbonne(id)->getPlace()->getNum();
        emissionFacture(place);
        bool verif = false;
        int choix;
        while (!verif){
            cout << "\n 1 pour renouveler le contrat \n 2 pour le départ de l'abonne" << endl;
            cin>> choix;
            switch (choix)
            {
            case 1:
                lesMinimes.getPlace(place)->getContrat()->renouveler(28);
                verif = true;
                break;
            case 2:
               lesMinimes.retireAbonne(id);
               lesMinimes.retireDepart(place);
               verif = true;
               break; 
            
            default:
                cout << "Choix invalide, recommencez" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
        }
    } 
    else {
        cout << "Pas d'abonné dans le port correspondant à cet identifiant. Retour au menu." << endl;
    } 
}

// Permet le paiement d'un passager et son départ ou son renouvellement de contrat
void GestionPort::departPassager(){
    int place;
    cout <<" Numéro de place?" << endl;
    cin >>place;
    if (!(lesMinimes.getPlace(place)->getEstLibre())){
        emissionFacture(place);
        bool verif = false;
        int choix;
        while (!verif){
            cout << "\n 1 pour le départ du passager \n 2 pour prolonger le sejour" << endl;
            cin>> choix;
            switch (choix)
            {
            case 1:
                lesMinimes.retirePassager(place);
                lesMinimes.retireDepart(place);
                verif = true;
                break;
            case 2:
                int jours;
                cout << "Renouveler pour combien de jours?" << endl;
                cin >> jours;
                lesMinimes.getPlace(place)->getContrat()->renouveler(jours);
                verif = true;
               break; 
            
            default:
                cout << "Choix invalide, recommencez" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
        }
    }
    else{
        cout << "Cette place n'est pas occupée. Retour au menu." << endl;
    }
}



// Marque le paiement comme effectué et archive la facture.
void GestionPort::emissionFacture(int _numPlace) 
{
    Facture* f = lesMinimes.getFacture(_numPlace);
    f->affiche();
    cout << "- Paiement réalisé - "<< endl;
    string entree;
    getline(cin,entree);
    f->payer();
    lesMinimes.ajoutFacture(f);

    
    
}


// Définit la liste de places disponibles pour un bateau.
void GestionPort::placesLibres(){
    Bateau* b = lesMinimes.creerBateau();
    bool verif = affichePlacesLibres(b);
    if (!verif){
        cout << "Pas de places libres pour ce bateau." << endl;
    }
}


