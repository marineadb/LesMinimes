#ifndef __VOILIERT2_H__
#define __VOILIERT2_H__
#include "Bateau.hpp"

class VoilierT2:public Bateau{
protected:
    bool eau;
    bool electricite;

public : 
VoilierT2(int,bool,bool);
~VoilierT2();
virtual void affiche();

};
#endif // __VOILIERT2_H__