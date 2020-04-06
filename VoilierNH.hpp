#ifndef __VOILIERNH_H__
#define __VOILIERNH_H__
#include "Bateau.hpp"

class VoilierNH:public Bateau{
protected:
public : 
VoilierNH(int);
~VoilierNH();

virtual void affiche();

};
#endif // __VOILIERNH_H__