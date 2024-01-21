#include<iostream>

using namespace std;

class Dane {
private:
	int rok;
	int miesiac;
	int dzien;
	int cwiartka;
	double autokonsumpcja;
	double eksport;
	double import;
	double pobor;
	double produkcja;


public :
	Dane(int r, int m, int d, int c, double ak, double ek, double im, double pob, double prod);
};
