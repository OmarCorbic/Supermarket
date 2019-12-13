#include "Radnik.h"
#include <iostream>
#include <string>

using namespace std;
Radnik::Radnik(){
    ime = "Nije uneseno";
}
Radnik::Radnik(string i, string p){
    ime = i;
    prezime = p;
}
Radnik::Radnik(string i, string p,string j){
    ime = i;
    prezime = p;
    JMBG = j;
}

void Radnik::setIme(string x) { ime = x; }
void Radnik::setPrezime(string x) { prezime = x; }
void Radnik::setJMBG(string x) { JMBG = x; }

string Radnik::getJMBG() { return JMBG; }
string Radnik::getPrezime() { return prezime; }
string Radnik::getIme() { return ime; }

void Radnik::printR(){
    cout<<"Ime: imo "<<ime<<endl;
    cout<<"Prezime: "<<prezime<<endl;
    cout<<"JMBG: "<<JMBG<<endl;

}
