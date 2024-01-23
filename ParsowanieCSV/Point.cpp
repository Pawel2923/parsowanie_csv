#include "Point.h"
using namespace std;
Dane::Dane(int r, int m, int d, int c, double ak, double ek, double im, double pob, double prod)
	:rok(r),miesiac(m),dzien(d),cwiartka(c),autokonsumpcja(ak),eksport(ek), import(im),pobor(pob),produkcja(prod){}

void Dane::display() {
	cout<< "Date: " << rok << "-" << miesiac << "-" << dzien << ", Quarter: " << cwiartka
		<< ", Autokonsumpcja: " << autokonsumpcja << ", Eksport: " << eksport
		<< ", Import: " << import << ", Pobor: " << pobor << ", Produkcja: " << produkcja << std::endl;
}

int Dane::getRok()
{
	return rok;
}
int Dane::getMiesiac()
{
	return miesiac;

}
int Dane::getDzien()
{
	return dzien;
}
int Dane::getCwiartka()
{
	return cwiartka;
}
double Dane::getAutokonsumpcja()
{
	return autokonsumpcja;
}
double Dane::getEksport()
{
	return eksport;
}
double Dane::getImport()
{
	return import;
}
double Dane::getpobor()
{
	return pobor;
}
double Dane::getProdukcja()
{
	return produkcja;
}