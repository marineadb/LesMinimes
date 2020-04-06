#ifndef __VOILIERT1_H__
#define __VOILIERT1_H__
#include "Bateau.hpp"

class VoilierT1:public Bateau{
protected:
public : 
VoilierT1(int, bool, bool);
~VoilierT1();
virtual void affiche();
};
#endif // __VOILIERT1_H__