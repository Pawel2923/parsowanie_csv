#ifndef POINT_H
#define POINT_H
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
	void display();
	int getRok();
	int getMiesiac();
	int getDzien();
	int getCwiartka();
	double getAutokonsumpcja();
	double getEksport();
	double getImport();
	double getpobor();
	double getProdukcja();
};
#endif