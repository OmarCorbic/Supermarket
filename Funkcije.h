#ifndef FUNKCIJE_H_INCLUDED
#define FUNKCIJE_H_INCLUDED
#include <unordered_map>

int odrediFunkciju(int a, int b);
void unesiRadnika(map<string, Radnik> & m, map<string, map<string, Radnik*>>& k);
void pregledRadnika(map<string, Radnik> & m);
void izmijeniRadnika(map<string, Radnik> &m);
void brisiRadnika(map<string, Radnik> &m);

void unesiArtikal(map<string, map<string, Artikal>>& p);
void pregledArtikla(map<string, map<string, Artikal>>& p);
void brisiArtikal(map<string, map<string, Artikal>>& p);
void izmijeniArtikal(map<string, map<string, Artikal>>& p);

void unesiPolicu(map<string, map<string, Artikal>>& p);
void pregledPolice(map<string, map<string, Artikal>>& p);
void brisiPolicu(map<string, map<string, Artikal>>& p);
void izmijeniPolicu(map<string, map<string, Artikal>>& p);


void unesiKasu(map<string, map<string, Radnik*>>& k);
void brisiKasu(map<string, map<string, Radnik*>>& k);
void pregledKase(map<string, map<string, Radnik*>>& k);
void izmjeniKasu(map<string, Radnik>& m, map<string, map<string, Radnik*>>& k);



#endif
