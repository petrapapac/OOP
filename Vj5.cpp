#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

class Karta {
public:
	string zog;  
	int broj;     

	Karta(string z, int b) : zog(z), broj(b) {}
	void print() const {
		cout << broj << " " << zog;
	}
};

class Mac {
	vector<Karta> karte;

public:
	Mac() {
		vector<string> boje = { "bastoni", "spade", "coppe", "denari" };
		for (auto& b : boje)
			for (int i = 1; i <= 10; ++i)
				karte.emplace_back(b, i);
	}

	void promijesaj() {
		random_device rd;
		mt19937 g(rd());
		shuffle(karte.begin(), karte.end(), g);
	}

	vector<Karta> podijeli(int n) {
		vector<Karta> ruka(karte.begin(), karte.begin() + n);
		karte.erase(karte.begin(), karte.begin() + n);
		return ruka;
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi = 0;

	Igrac(string i) : ime(i) {}

	void postavi_karte(const vector<Karta>& k) {
		ruka = k;
	}

	void ispisi_karte() const {
		cout << ime << " ima karte: ";
		for (auto& k : ruka) {
			cout << "(" << k.broj << " " << k.zog << ") ";
		}
		cout << endl;
	}

	void akuziraj() {
		for (string boja : {"bastoni", "spade", "coppe", "denari"}) {
			bool ima1 = false, ima2 = false, ima3 = false;
			for (auto& k : ruka) {
				if (k.zog == boja && k.broj == 1) ima1 = true;
				if (k.zog == boja && k.broj == 2) ima2 = true;
				if (k.zog == boja && k.broj == 3) ima3 = true;
			}
			if (ima1 && ima2 && ima3)
				bodovi += 3;
		}
		for (int broj = 1; broj <= 10; ++broj) {
			int count = 0;
			for (auto& k : ruka)
				if (k.broj == broj)
					count++;
			if (count == 3) bodovi += 3;
			if (count == 4) bodovi += 4;
		}
	}
};

int main() {
	int broj_igraca;
	cout << "Unesite broj igraca (2 ili 4): ";
	cin >> broj_igraca;

	vector<Igrac> igraci;
	for (int i = 0; i < broj_igraca; ++i) {
		string ime;
		cout << "Ime igraca " << i + 1 << ": ";
		cin >> ime;
		igraci.emplace_back(ime);
	}

	Mac mac;
	mac.promijesaj();

	for (auto& igrac : igraci) {
		igrac.postavi_karte(mac.podijeli(10));
		igrac.ispisi_karte();
		igrac.akuziraj();
	}

	cout << "\n--- Rezultati akuze ---" << endl;
	for (auto& igrac : igraci) {
		cout << igrac.ime << " ima " << igrac.bodovi << " bodova iz akuze." << endl;
	}

	return 0;
}