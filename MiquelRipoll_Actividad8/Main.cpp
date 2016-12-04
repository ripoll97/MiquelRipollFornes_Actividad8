#include <map>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

/*	CLASSE FECHA	*/

class Fecha {
public:
	int dia, mes;
	Fecha(int day, int month): dia(day), mes(month){}

};

inline bool operator < (const Fecha &f1, const Fecha &f2) {
	if (f1.mes < f2.mes) { return true; };
	if (f1.mes == f2.mes) {
		if (f1.dia < f2.dia) { return true; }
		else return false;
	}
	else return false;
};

inline bool operator == (const Fecha &f1, const Fecha &f2) {
	if (f1.mes == f2.mes && f1.dia == f2.dia) { return true; }
	else return false;
}

/* CLASSE HORA	*/

class Hora {
public:
	int hora, minutos;
	Hora(int hour, int minutes) : hora(hour), minutos(minutes){}
};

inline bool operator == (const Hora &h1, const Hora &h2) {
	if (h1.hora == h2.hora && h1.minutos == h2.minutos) { return true; }
	else return false;
}

inline bool operator < (const Hora &h1, const Hora &h2) {
	if (h1.hora < h2.hora) { return true; }
	if (h1.hora == h2.hora) {
		if (h1.minutos < h2.minutos) { return true; }
		else return false;
	}
	else return false;
}

/* CLASSE AGENDA	*/

class Agenda {
	private:
	map <Hora, string> dayCalendar;
	map <Fecha, map <Hora, string>> calendari;
	
public:
	void insertarEvento(const Fecha &fecha, const Hora &hora, const string &description) {	
		dayCalendar.insert(pair<const Hora, string>(hora, description));
		calendari.insert(pair <const Fecha, map<Hora, string>> (fecha, dayCalendar));
	}

	void provaInsertar(const Fecha &fecha, string fet);
	
	void printKey();
};

/*
void Agenda::provaInsertar(const Fecha &fecha, string fet) {
	Agenda::provam.insert(Agenda::provam.begin(), pair <const Fecha, string > (fecha, fet));
}*/


void Agenda::printKey() {
	for (auto it = calendari.begin(); it != calendari.end(); ++it) {
		cout << it->first.dia << " Del mes: " << it->first.mes << " tenc: " << it->second << "\n";
	}
}

/*	MAIN	*/

int main() {

	Agenda a;
	const Fecha primer (6,2);
	const Fecha segon(6, 5);
	const Hora hour(17, 40);
	const Hora hour2(19, 10); 

	a.insertarEvento(primer, hour, "Reunion");
	a.insertarEvento(segon, hour2, "Partido de futbol");

	a.printKey();

	return 0;
}