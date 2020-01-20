// Tarsashaz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "lakokozosseg.h"

// Keszitsen programot egy tarsashazi lakokozosseg modellezesere az alabbiak szerint:

// 2-es szinthez:
// 
// - A Tarstulajdonos osztaly:
// ... eltarolja a tulajdonosok nevet es tulajdoni hanyadat.
// ... van meg egy print() metodusa, ami nincs implementalva
// ... absztrakt osztaly, ezert nem peldanyosithato

// - A BekesTulajdonos egyfajta Tarstulajdonos
// ... 2-es szinthez: implementalja a print() metodust (hogy mit ir ki, ahhoz ld. a Kozgyules.printJelenlevok() kimenetet)

// - A PereskedoTulajdonos is egyfajta Tarstulajdonos
// ... 2-es szinthez: implementalja a print() metodust (hogy mit ir ki, ahhoz ld. a Kozgyules.printJelenlevok() kimenetet)

// - A Kozgyules osztaly:
// ... 2-es szinthez eltarolja int-kent a kozgyules evszamat, honapjat es napjat
// ... 2-es szinthez eltarolja STL kontenerben a kozgyules resztvevoinek pointereit
// ... 2-es szinthez megvalositja az addJelenlevo() metodust
// ... 2-es szinthez megvalositja a printJelenlevok() metodust, amely az osszes jelenlevore meghivja sajat print() metodusat

// - A Tarsashaz osztaly STL kontenerben, hozzadas sorrendjeben tarolja a tulajdonosokra hivatkozo pointereket
// ... 2-es szinthez a Tarstulajdonosok pointereit az addTulajdonos() metodussal lehet hozzaadni
// ... 2-es szinthez megvalositja meg a holdKozgyules() metodust. Ez a metodust gondoskodik rola, hogy
//     minden 2. pereskedo tulajdonos, es minden 3. bekes tulajdonos reszt vegyen a kozgyulesen (ehhez a kozgyules addJelenlevo() metodusat lehet hasznalni)

// - 3-as szinthez:
// Keszitsen a Kozgyules osztalyban egy printLetszam() metodust, amely a <numeric> header-ben talalhato
// std::accumulate fuggveny segitsegevel kiirja a kozgyules letszamat.
// Figyelem: az std::accumulate BinaryOperation parametere egy kezileg definialt osztaly peldanya kell, hogy legyen.
// a kezileg definialt osztaly neve legyen SumJelenlevos(). Ez az osztaly meg kell, hogy valositsa az alabbi metodust:
// int operator()(int acc, Tarstulajdonos* tp)

// 4-es szinthez:
// Keszitsen Meghatalmazas osztalyt, amely nyilvantartja, hogy melyik meghatalmazo melyik meghatalmazottnak
// adott meghatalmazast.
// Keszitsen a Kozgyules osztalyhoz egy submitMeghatalmazas() metodust, amely lehetove teszi egy adott
// meghatalmazas benyujtasat. A Kozgyules osztaly tarolja el a meghatalmazasok pointereit
// Ezt kovetoen keszitse el a Kozgyules osztaly printJelenlevokWithProxies() metodusat ugy, hogy a 
// jelenlevok tulajdoni hanyada mellett az osszes altaluk kepviselt tulajdoni hanyad is kiirasra keruljon.
// A printJelenlevokWithProxies() metodusban szinten az std::accumulate() fuggvenyt hasznalja az eltarolt
// meghatalmazas-lista / vector folott vegig iteralva. Ehhez szuksege lesz egy SumMeghatis() osztalyra is.

// 5-os szinthez:
// Valositsa meg a PereskedoTulajdonos osztaly orditozik() metodusat.
// Ha egy kozgyulesen legalabb 2x orditoznak, a BekesTulajdonosoknak elmegy a kedvuk a reszveteltol,
// es legkozelebb csak minden 4. BekesTulajdonos megy el a kozgyulesre.

#define SZINT_2 1
#define SZINT_3 1
#define SZINT_4 1
#define SZINT_5 1


int main()
{
#if SZINT_2:

	Tarstulajdonos* tulaj1 = new BekesTulajdonos("Kisimult P.", 1230);
	Tarstulajdonos* tulaj2 = new PereskedoTulajdonos("Veszekedo I.", 2660);
	Tarstulajdonos* tulaj3 = new BekesTulajdonos("Okos B.", 370);
	Tarstulajdonos* tulaj4 = new BekesTulajdonos("Sima O.", 1050);
	Tarstulajdonos* tulaj5 = new BekesTulajdonos("Rendes C.", 230);
	Tarstulajdonos* tulaj6 = new BekesTulajdonos("Aranyos K.", 410);
	Tarstulajdonos* tulaj7 = new PereskedoTulajdonos("Goromba B.", 970);
	Tarstulajdonos* tulaj8 = new PereskedoTulajdonos("Kiabalos H.", 1220);
	Tarstulajdonos* tulaj9 = new PereskedoTulajdonos("Duhongo K.", 1020);
	Tarstulajdonos* tulaj10 = new PereskedoTulajdonos("Baratsagtalan P.", 840);

	Tarsashaz chicago;
	chicago.addTulajdonos(tulaj1);
	chicago.addTulajdonos(tulaj2);
	chicago.addTulajdonos(tulaj3);
	chicago.addTulajdonos(tulaj4);
	chicago.addTulajdonos(tulaj5);
	chicago.addTulajdonos(tulaj6);
	chicago.addTulajdonos(tulaj7);
	chicago.addTulajdonos(tulaj8);
	chicago.addTulajdonos(tulaj9);
	chicago.addTulajdonos(tulaj10);

	Kozgyules kgy1(2019, 5, 12);
	chicago.holdKozgyules(&kgy1);
	kgy1.printJelenlevok(); // minden 3. bekes, es minden 2. pereskedo tulajdonos reszt vesz
	// Kiirja, hogy:
	// Bekes tulajdonos : Sima O. - 1050 / 10 000
	// Pereskedo tulajdonos : Goromba B. - 970 / 10 000
	// Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000
	std::cout << " ---------------------------- " << std::endl;
	std::cout << " Elvart kimenet:" << std::endl;
	std::cout << " Bekes tulajdonos : Sima O. - 1050 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

#if SZINT_3:

	kgy1.printLetszam(); // kiirja, hogy Letszam: 3040
	std::cout << " ---------------------------- " << std::endl;
	std::cout << " Elvart kimenet: 3040" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

# if SZINT_4:
	
	Kozgyules kgy2(2020, 1, 12);
	chicago.holdKozgyules(&kgy2);
	Meghatalmazas meghati1(tulaj1, tulaj4);
	Meghatalmazas meghati2(tulaj3, tulaj4);
	kgy2.submitMeghatalmazas(&meghati1);
	kgy2.submitMeghatalmazas(&meghati2);
	kgy2.printJelenlevokWithProxies(); // minden 3. bekes, es minden 2. pereskedo tulajdonos reszt vesz
	// viszont most mar Sima O.-nak joval tobb tulajdoni hanyada van!!
	// azt kell kiirnia, hogy:
	// Bekes tulajdonos: Sima O. - 2650 / 10 000
	// Pereskedo tulajdonos : Goromba B. - 970 / 10 000
	// Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000
	std::cout << " ---------------------------- " << std::endl;
	std::cout << " Elvart kimenet:" << std::endl;
	std::cout << " Bekes tulajdonos: Sima O. - 2650 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

# if SZINT_5:
	PereskedoTulajdonos * newPereskedo1 = new PereskedoTulajdonos("Vendeg a szomszedbol", 0);
	PereskedoTulajdonos * newPereskedo2 = new PereskedoTulajdonos("Vendeg a szomszedbol felesege", 0);
	newPereskedo1->orditozik(&kgy2);
	newPereskedo2->orditozik(&kgy2);

	Kozgyules kgy3(2020, 02, 13);
	chicago.setPreviousKozgyules(&kgy2);
	chicago.holdKozgyules(&kgy3);
	kgy3.printJelenlevok(); // minden 4. bekes, es minden 2. pereskedo tulajdonos reszt vesz
	std::cout << " ---------------------------- " << std::endl;
	std::cout << " Elvart kimenet:" << std::endl;
	std::cout << " Bekes tulajdonos : Rendes C. - 230 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
	std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
	std::cout << std::endl << std::endl << std::endl;


#endif

#endif

#endif
	
	delete tulaj1;
	delete tulaj2;
	delete tulaj3;
	delete tulaj4;
	delete tulaj5;
	delete tulaj6;
	delete tulaj7;
	delete tulaj8;
	delete tulaj9;
	delete tulaj10;
	
#endif

	std::cin.get();
    return 0;
}

