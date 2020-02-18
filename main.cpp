#include "Radnik.h"
#include "Artikal.h"
#include <iostream>
#include <string>
#include <map>
#include "Funkcije.h"
#include <unordered_map>
using namespace std;

int main()
{
    map<string, Radnik> Radnici;
    map<string, map<string, Artikal> > Police;
    map<string, map<string, Radnik*> > Kase;

    string okvir(90,'-');

    int z=1;
    int brojSubjekta = 0;
    int brojOpcije = 0;
do{
prvi:
    cout<<"Molimo unesite broj funkcije koju zelite obavljati:\n 1.Unos\n 2.Izmjena\n 3.Pregled\n 4.Brisanje\n 5.Napustanje programa\n"<<endl;
    cin>>brojOpcije;
    cout<<okvir<<endl;


    while(brojOpcije<1 || brojOpcije>5){
        cout<<"Unijeli ste nevazeci broj funkcije. Molimo unesite ponovo: "<<endl;
        cin.clear();
        std::cin.ignore(10000, '\n');
        cin>>brojOpcije;

    }



    switch(brojOpcije){
    case 1:
        cout<<"Molimo unesite broj subjekta nad kojim zelite izvrsiti funkciju:\n 1.Radnik\n 2.Kasa\n 3.Polica\n 4.Artikal\n 5.Idi nazad\n"<<endl;
        cin>>brojSubjekta;
        while(brojSubjekta<1 || brojSubjekta>5){
        cout<<"Unijeli ste nevazeci broj subjekta. Molimo unesite ponovo: "<<endl;
        cin.clear();
        std::cin.ignore(10000, '\n');
        cin>>brojSubjekta;
        }
        break;
    case 2:
        cout<<"Molimo unesite broj subjekta nad kojim zelite izvrsiti funkciju:\n 1.Radnik\n 2.Kasa\n 3.Polica\n 4.Artikal\n 5.Idi nazad\n"<<endl;
        cin>>brojSubjekta;
        while(brojSubjekta<1 || brojSubjekta>5){
        cout<<"Unijeli ste nevazeci broj subjekta. Molimo unesite ponovo: "<<endl;
        cin.clear();
        std::cin.ignore(10000, '\n');
        cin>>brojSubjekta;

        }
        break;
    case 3:
        cout<<"Molimo unesite broj subjekta nad kojim zelite izvrsiti funkciju:\n 1.Radnik\n 2.Kasa\n 3.Polica\n 4.Artikal\n 5.Idi nazad\n"<<endl;
        cin>>brojSubjekta;
        while(brojSubjekta<1 || brojSubjekta>5){
        cout<<"Unijeli ste nevazeci broj subjekta. Molimo unesite ponovo: "<<endl;
        cin.clear();
        std::cin.ignore(10000, '\n');
        cin>>brojSubjekta;
        }
        break;
    case 4:
        cout<<"Molimo unesite broj subjekta nad kojim zelite izvrsiti funkciju:\n 1.Radnik\n 2.Kasa\n 3.Polica\n 4.Artikal\n 5.Idi nazad\n"<<endl;
        cin>>brojSubjekta;
        while(brojSubjekta<1 || brojSubjekta>5){
        cout<<"Unijeli ste nevazeci broj subjekta. Molimo unesite ponovo: "<<endl;
        cin.clear();
        std::cin.ignore(10000, '\n');
        cin>>brojSubjekta;
        }
        break;
    case 5:
        z=0;
        break;
    }
    if(z==1){
    cout<<okvir<<endl;
    if(brojSubjekta == 5)goto prvi;

    switch(odrediFunkciju(brojOpcije,brojSubjekta)){
    case 11: //Unos radnika
        unesiRadnika(Radnici,Kase);
    break;
    case 12: //Unos kase
        unesiKasu(Kase);
    break;
    case 13: //Unos police
        unesiPolicu(Police);
    break;
    case 14: //Unos artikla
        unesiArtikal(Police);
    break;
    case 21: //Izjmena radnika
        izmijeniRadnika(Radnici);
    break;
    case 22: //Izjmena kase
        izmjeniKasu(Radnici,Kase);
    break;
    case 23: //Izjmena police
        izmijeniPolicu(Police);
    break;
    case 24: //Izjmena artikla
        izmijeniArtikal(Police);
    break;
    case 31: //Pregled radnika
        pregledRadnika(Radnici);
    break;
    case 32: //Pregled kase
        pregledKase(Kase);
    break;
    case 33: //Pregled police
        pregledPolice(Police);
    break;
    case 34: //Pregled artikla
        pregledArtikla(Police);
    break;
    case 41: //Brisanje radnika
        brisiRadnika(Radnici);
    break;
    case 42: //Brisanje kase
        brisiKasu(Kase);
    break;
    case 43: //Brisanje police
        brisiPolicu(Police);
    break;
    case 44: //Brisanje artikla
        brisiArtikal(Police);
    break;
    }

    cout<<okvir<<endl;

    }

}while(z==1);
return 0;
}






