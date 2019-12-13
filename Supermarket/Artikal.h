#ifndef ARTIKAL_H
#define ARTIKAL_H

#include<iostream>


using namespace std;

class Artikal
{
    public:
        Artikal();
        Artikal(float c, string n);
        Artikal(float c, string n, string p);

        void setKategorija(string x);
        void setNaziv(string x);
        void setRb(int x);
        void setProizvodjac(string x);
        void setCijena(float x);
        void printA();

        string getKategorija();
        string getNaziv();
        int getRb();
        string getProizvodjac();
        float getCijena();

        string kljucArtikla(string k,string n, int b);

    private:

        int rb;
        string kategorija;
        string naziv;
        string proizvodjac;
        float cijena;



};

#endif // ARTIKAL_H
