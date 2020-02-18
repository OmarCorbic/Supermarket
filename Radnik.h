#ifndef RADNIK_H
#define RADNIK_H

#include <string>
using namespace std;

class Radnik
{
    public:
        Radnik();
        Radnik(string i, string p);
        Radnik(string i, string p,string j);

        void setIme(string x);
        void setPrezime(string x);
        void setJMBG(string x);
        void printR();

        string getIme();
        string getPrezime();
        string getJMBG();

    private:
        string ime;
        string prezime;
        string JMBG;

};



#endif // RADNIK_H
