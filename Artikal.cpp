#include "Artikal.h"
#include<iostream>
#include<string>

using namespace std;
Artikal::Artikal(){
    cijena = 0.00;
}
Artikal::Artikal(float c, string n){
    cijena = c;
    naziv = n;
}
Artikal::Artikal(float c, string n,string p){
    cijena = c;
    naziv = n;
    proizvodjac = p;
}


void Artikal::setKategorija(string x) { kategorija = x; }
void Artikal::setNaziv(string x) { naziv = x; }
void Artikal::setRb(int x) { rb = x; }
void Artikal::setProizvodjac(string x) { proizvodjac = x; }
void Artikal::setCijena(float x) { cijena = x; }


string Artikal::getKategorija() { return kategorija; }
string Artikal::getNaziv() { return naziv; }
int Artikal::getRb() { return rb; }
string Artikal::getProizvodjac() { return proizvodjac; }
float Artikal::getCijena() { return cijena; }

string Artikal::kljucArtikla(string k,string n, int b){
    string ka = kategorija + n.substr(0,3) + to_string(b);
    return ka;
}

void Artikal::printA(){

    cout << "Cijena\tProizvodjac\tNaziv\t" << endl;
    cout << cijena <<" KM"<< "\t" << proizvodjac << "\t\t" << naziv << endl;
    cout << endl;

}

