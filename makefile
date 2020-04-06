cc = g++

prog: main.o GestionPort.o Port.o Date.o Bateau.o VoilierNH.o VoilierT1.o VoilierT2.o Place.o PlaceCM.o  Facture.o Usager.o Passager.o Abonne.o Contrat.o ContratAbo.o
	$(cc)  main.o GestionPort.o Port.o Date.o Bateau.o VoilierNH.o VoilierT1.o VoilierT2.o Place.o PlaceCM.o  Facture.o Usager.o Passager.o Abonne.o Contrat.o ContratAbo.o -o prog

main.o: main.cpp
	$(cc) -c main.cpp

GestionPort.o : GestionPort.hpp GestionPort.cpp 
	$(cc) -c GestionPort.cpp 

Port.o: Port.hpp Port.cpp 
	$(cc) -c Port.cpp 


Date.o : Date.hpp Date.cpp
	$(cc) -c Date.cpp

Bateau.o : Bateau.hpp Bateau.cpp
	$(cc) -c Bateau.cpp

VoilierNH.o : VoilierNH.hpp VoilierNH.cpp Bateau.hpp Bateau.cpp
	$(cc) -c VoilierNH.cpp

VoilierT1.o : VoilierT1.hpp VoilierT1.cpp Bateau.hpp Bateau.cpp
	$(cc) -c VoilierT1.cpp

VoilierT2.o : VoilierT2.hpp VoilierT2.cpp Bateau.hpp Bateau.cpp
	$(cc) -c VoilierT2.cpp

Place.o: Place.hpp Place.cpp
	$(cc) -c Place.cpp

PlaceCM.o: Place.hpp Place.cpp PlaceCM.hpp PlaceCM.cpp
	$(cc) -c PlaceCM.cpp
	

Facture.o : Facture.hpp Facture.cpp
	$(cc) -c Facture.cpp


Usager.o : Usager.hpp Usager.cpp
	$(cc) -c Usager.cpp

Passager.o : Usager.hpp Usager.cpp Passager.hpp Passager.cpp
	$(cc) -c Passager.cpp

Abonne.o : Usager.hpp Usager.cpp Abonne.hpp Abonne.cpp
	$(cc) -c Abonne.cpp

Contrat.o : Contrat.hpp Contrat.cpp	
	$(cc) -c Contrat.cpp
ContratAbo.o : ContratAbo.hpp ContratAbo.cpp Contrat.hpp Contrat.cpp
	$(cc) -c ContratAbo.cpp