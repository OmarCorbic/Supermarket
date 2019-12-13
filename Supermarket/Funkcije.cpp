#include "Radnik.h"
#include <iostream>
#include "Artikal.h"
#include <string>
#include <map>
#include "Funkcije.h"

int odrediFunkciju(int a, int b){
    if (a==1 && b==1)
        return 11;
    if (a==1 && b==2)
        return 12;
    if (a==1 && b==3)
        return 13;
    if (a==1 && b==4)
        return 14;

    if (a==2 && b==1)
        return 21;
    if (a==2 && b==2)
        return 22;
    if (a==2 && b==3)
        return 23;
    if (a==2 && b==4)
        return 24;

    if (a==3 && b==1)
        return 31;
    if (a==3 && b==2)
        return 32;
    if (a==3 && b==3)
        return 33;
    if (a==3 && b==4)
        return 34;

    if (a==4 && b==1)
        return 41;
    if (a==4 && b==2)
        return 42;
    if (a==4 && b==3)
        return 43;
    if (a==4 && b==4)
        return 43;
return 0;}

void unesiRadnika(map<string, Radnik>& m, map<string, map<string, Radnik*>>& k){

    typedef std::pair<std::string, Radnik*> MyPair;

    string ime,prezime,JMBG;
    cout<<"Molimo unesite ime radnika: ";
    cin>>ime;

    cout<<"Molimo unesite prezime radnika: ";
    cin>>prezime;

    cout<<"Molimo unesite JMBG radnika: ";
    cin>>JMBG;
    while(JMBG.size()<13 || JMBG.size()>13){
        cout<<"Molimo ispravno unesite podatak: ";
        cin>>JMBG;
    }
    Radnik r(ime,prezime,JMBG);

    m.insert({ime,r});

    if(!k.empty()){
        string nazivKase;
        cout<<"Molimo unesite naziv kase na kojoj ce radnik raditi: "<<endl;
        for(auto iter : k)
            cout<<iter.first<<endl;
            cout<<endl;

        cin>>nazivKase;
        while(!k.count(nazivKase)){
            cout<<"Unesena polica ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>nazivKase;
            }
        while(k[nazivKase].size()>=1){
            cout<<"Na kasi moze raditi samo jedan radnik. Ova kasa je zauzeta.\nMolimo unesite naziv druge kase: "<<endl;
            cin>>nazivKase;
            while(!k.count(nazivKase)){
            cout<<"Unesena polica ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>nazivKase;
            }

        }
        Radnik *pR;
        pR = &r;
        k[nazivKase].insert(MyPair(ime,pR));
    }
}
void pregledRadnika(map<string, Radnik>& m){
    if(m.empty()){
        cout<<"Nema zaposlenih. "<<endl;
    }
    else{
      for (auto it : m){
        it.second.printR();
      }
    }
}
void izmijeniRadnika(map<string, Radnik>& m){
    if(m.empty()){
        cout<<"Nema zaposlenih. "<<endl;
    }
    else{

    string ime,novoIme,novoPrezime,noviJMBG;
    int a;
    cout<<"Unesite ime radnika kojeg zelite izmijeniti: ";
    cin>>ime;
     while(!m.count(ime)){
        cout<<"Radnik "<<ime<<" ne postoji. Molimo unesite ponovo. "<<endl;
        cin>>ime;
    }


    cout<<"\nKoju informaciju zelite izmijeniti?\n1.Prezime \n2.JMBG\n"<<endl;
    cin>>a;
    while(a<1 || a>2){
        cout<<"Molimo ispravno unesite odgovor. "<<endl;
        cin>>a;
    }
    switch(a){
        case 1:
            cout<<"Unesite novo prezime: ";
            cin>>novoPrezime;
            m[ime].setPrezime(novoPrezime);
            break;

        case 2:
            cout<<"Unesite novi JMBG: ";
            cin>>noviJMBG;
            m[ime].setJMBG(noviJMBG);
            break;

           }
    }
    }
void brisiRadnika(map<string, Radnik>& m){
    if(m.empty()){
        cout<<"Nema zaposlenih. "<<endl;
    }
    else{
    string ime;
    cout<<"Unesite ime radnika kojeg zelite ukloniti: ";
    cin>>ime;
    while(!m.count(ime)){
        cout<<"Radnik "<<ime<<" ne postoji. Molimo unesite ponovo. "<<endl;
        cin>>ime;
    }
    auto i = m.find(ime);
    m.erase(i);
    cout<<"Radnik "<<ime<<" je uspjesno uklonjen. "<<endl;
    }
}
void unesiArtikal(map<string, map<string, Artikal>>& p){
    if(p.empty()){
        cout<<"Nema unesenih polica. \n";
    }
    else{
        int n;
        float cijena;
        string kategorija,naziv,proizvodjac;

        cout<<"U koju policu zelite dodati artikle? "<<endl;

        for(auto iter : p)
        cout<<iter.first<<endl;

        cout<<endl;
        cin>>kategorija;
        while(!p.count(kategorija)){
            cout<<"Unesena polica ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>kategorija;
        }

        cout<<"Unesite broj artikala za unijeti: ";
        cin>>n;

        cout<<"Unesite naziv artikla: ";
        cin>>naziv;
        cout<<"Unesite cijenu artikla: ";
        cin>>cijena;
        cout<<"Unesite proizvodjaca artikla: ";
        cin>>proizvodjac;

        for(int i = 1;i <= n; i++){
            Artikal a(cijena, naziv, proizvodjac);
            a.setKategorija(kategorija);
            a.setRb(i);

            p[kategorija].insert({a.kljucArtikla(kategorija,naziv,i), a});
        }

    }
}
void unesiPolicu(map<string, map<string, Artikal>>& p){

    map<string, Artikal> m;
    string kategorija;
    int brojPolice;
    string kljuc;

    brojPolice = p.size() + 1;

    cout<<"Unesite kategoriju police koju zelite kreirati (3 slova): ";
    cin>>kategorija;

    while(kategorija.size()<1 || kategorija.size()>3){
        cout<<"Niste ispravno unijeli podatak. Molimo unesite ponovo: "<<endl;
        cin>>kategorija;
    }

    kljuc = kategorija + to_string(brojPolice);

    p.insert({kljuc, m});
    cout<<"Polica uspjesno kreirana. "<<endl;
}
void pregledPolice(map<string, map<string, Artikal>>& p){
    if(p.empty()){
        cout<<"Nema unesenih polica. "<<endl;
    }
    else{
        for(auto & outer_map_pair : p) {
            cout << "Polica: "<< outer_map_pair.first << " sadrzi: "<<outer_map_pair.second.size()<<" Artikala"<<endl;
                for(auto & inner_map_pair : outer_map_pair.second) {
                    cout<<inner_map_pair.first;
                    cout<<endl;
            }
            cout<<endl;
        }
    }

}
void brisiPolicu(map<string, map<string, Artikal>>& p){

    string kategorija;
    cout<<"Koju policu zelite ukloniti?"<<endl;
    for(auto iter : p)
        cout<<iter.first<<endl;
        cout<<endl;
        cin>>kategorija;
        while(!p.count(kategorija)){
            cout<<"Unesena polica ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>kategorija;
        }
    auto i = p.find(kategorija);
    p.erase(i);

}
void unesiKasu(map<string, map<string, Radnik*>>& k){
    map<string, Radnik*> r;
    int n;
    string kljuc;

    cout<<"Koliko kasa zelite kreirati? "<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){

        kljuc = "K" + to_string(i);

        k.insert({kljuc, r});
        cout<<"Kasa "<<kljuc<<" je uspjesno kreirana."<<endl;
    }
}
void brisiKasu(map<string, map<string, Radnik*>>& k){
    if(k.empty()){
        cout<<"Nema unesenih kasa."<<endl;
    }
    else{
        string nazivKase;
        cout<<"Koju kasu zelite ukloniti?"<<endl;
        for(auto iter : k)
            cout<<iter.first<<endl;
        cout<<endl;
        cin>>nazivKase;
        while(!k.count(nazivKase)){
            cout<<"Unesena polica ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>nazivKase;
        }
    auto i = k.find(nazivKase);
    k.erase(i);
    cout<<"Kasa "<<nazivKase<<" je uspjesno uklonjena. "<<endl;
        }
    }
void pregledKase(map<string, map<string, Radnik*>>& k){
     if(k.empty()){
            cout<<"Nema unesenih kasa. "<<endl;
        }
        else{
            for(auto & outer_map_pair : k) {
                cout << "Na kasi "<< outer_map_pair.first << " radi: "<<endl;
                for(auto & inner_map_pair : outer_map_pair.second) {
                    inner_map_pair.second->printR(); //getIme();
                        cout<<endl;

                    }
                }
                cout<<endl;
            }
}

void izmjeniKasu(map<string, Radnik>& m, map<string, map<string, Radnik*>>& k){
    if(k.empty()){
        cout<<"Nema unesenih kasa. "<<endl;
        }
    else{
        if(m.empty()){
            cout<<"Nema zaposlenih."<<endl;
        }
        else{
        typedef std::pair<std::string, Radnik*> MyPair;

        Radnik* pR;
        string imeRadnika;
        int brojFunkcije;
        string nazivKase;

        cout<<"Koju kasu zelite izmijeniti?"<<endl;
        for(auto iter : k)
            cout<<iter.first<<endl;

        cout<<endl;
        cin>>nazivKase;

        while(!k.count(nazivKase)){
            cout<<"Unesena kasa ne postoji. Molimo unesite ponovo: "<<endl;
            cin>>nazivKase;
        }

        cout<<"Koju funkciju zelite obavljati nad odabranom kasom?\n1.Dodaj radnika\n2.Ukloni radnika\n"<<endl;
        cin>>brojFunkcije;
        while(brojFunkcije<1 || brojFunkcije>2){
            cout<<"Pogresno unesen podatak. Molimo unesite ponovo. "<<endl;
            cin>>brojFunkcije;
        }

        switch(brojFunkcije){
        case 1:

            cout<<"Unesite ime radnika kojeg zelite dodati na kasu?"<<endl;
            for(auto i : m)
                cout<<i.first<<endl;
            cout<<endl;
            cin>>imeRadnika;
            while(!m.count(imeRadnika)){
                cout<<"Unesena radnik ne postoji. Molimo unesite ponovo: "<<endl;
                cin>>imeRadnika;
            }
            pR = &m[imeRadnika];
            k[nazivKase].insert(MyPair(imeRadnika,pR));
            cout<<"Radnik "<<imeRadnika<<" sada radi na kasi "<<nazivKase<<"."<<endl;

            break;

        case 2:
            auto i =  k[nazivKase].begin();
            k[nazivKase].erase(i);
            cout<<"Radnik uspjenso uklonjen.\nKasa "<<nazivKase<<" je sada prazna."<<endl;
            break;
        }
    }
}
}
