#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include "claseScoli.cpp"

using namespace std;

class fisiereScoalaPrimara : public ScoalaPrimara
{
	static int nrElevi;
	char* nume;
	const int anNastere;
	int clasa;
	int nrMaterii;
	float* note;
	int premiu;

public:
	void writeToFile(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		f.write(nume, sizeof(char) * lungime);
		f.write((char*)&this->anNastere, sizeof(this->anNastere));
		f.write((char*)&this->clasa, sizeof(this->clasa));
		f.write((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		for (int i = 0; i < this->nrMaterii; i++)
		{
			f.write((char*)&this->note[i], sizeof(this->note[i]));
		}
		f.write((char*)&this->premiu, sizeof(this->premiu));
	}

	void readFromFile(ifstream& in)
	{
		int lungime = 0;
		in.read((char*)&lungime, sizeof(int));
		char* buffer = new char[lungime];
		in.read(buffer, lungime);
		this->nume = buffer;
		delete[] buffer;
		in.read((char*)&this->anNastere, sizeof(this->anNastere));
		in.read((char*)&this->clasa, sizeof(this->clasa));
		in.read((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		delete[] this->note;
		this->note = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			in.read((char*)&this->note[i], sizeof(this->note[i]));
		}
		in.read((char*)&this->premiu, sizeof(this->premiu));
	}


	void readCSV(ifstream& in)
	{
		ifstream myFile;
		myFile.open("ScoalaPrimara.csv");
		while (myFile.good())
		{
			string l;
			getline(myFile, l, ',');
		}
	}
};

class fisiereScoalaGimnaziala : public ScoalaGimnaziala
{
	static int nrElevi;
	char* nume;
	const int anNastere;
	int clasa;
	int nrMaterii;
	float* note;
	int premiu;

public:
	void writeToFile(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		f.write(nume, sizeof(char) * lungime);
		f.write((char*)&this->anNastere, sizeof(this->anNastere));
		f.write((char*)&this->clasa, sizeof(this->clasa));
		f.write((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		for (int i = 0; i < this->nrMaterii; i++)
		{
			f.write((char*)&this->note[i], sizeof(this->note[i]));
		}
		f.write((char*)&this->premiu, sizeof(this->premiu));
	}

	void readFromFile(ifstream& in)
	{
		int lungime = 0;
		in.read((char*)&lungime, sizeof(int));
		char* buffer = new char[lungime];
		in.read(buffer, lungime);
		this->nume = buffer;
		delete[] buffer;
		in.read((char*)&this->anNastere, sizeof(this->anNastere));
		in.read((char*)&this->clasa, sizeof(this->clasa));
		in.read((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		delete[] this->note;
		this->note = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			in.read((char*)&this->note[i], sizeof(this->note[i]));
		}
		in.read((char*)&this->premiu, sizeof(this->premiu));
	}

	void readCSV(ifstream& in)
	{
		ifstream myFile;
		myFile.open("ScoalaGimnaziala.csv");
		while (myFile.good())
		{
			string l;
			getline(myFile, l, ',');
		}
	}
};

class fisiereLiceu : public Liceu
{
	static int nrElevi;
	char* nume;
	const int anNastere;
	int clasa;
	int nrMaterii;
	float* note;
	int premiu;

public:
	void writeToFile(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		f.write(nume, sizeof(char) * lungime);
		f.write((char*)&this->anNastere, sizeof(this->anNastere));
		f.write((char*)&this->clasa, sizeof(this->clasa));
		f.write((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		for (int i = 0; i < this->nrMaterii; i++)
		{
			f.write((char*)&this->note[i], sizeof(this->note[i]));
		}
		f.write((char*)&this->premiu, sizeof(this->premiu));
	}

	void readFromFile(ifstream& in)
	{
		int lungime = 0;
		in.read((char*)&lungime, sizeof(int));
		char* buffer = new char[lungime];
		in.read(buffer, lungime);
		this->nume = buffer;
		delete[] buffer;
		in.read((char*)&this->anNastere, sizeof(this->anNastere));
		in.read((char*)&this->clasa, sizeof(this->clasa));
		in.read((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		delete[] this->note;
		this->note = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			in.read((char*)&this->note[i], sizeof(this->note[i]));
		}
		in.read((char*)&this->premiu, sizeof(this->premiu));
	}

	void readCSV(ifstream& in)
	{
		ifstream myFile;
		myFile.open("Liceu.csv");
		while (myFile.good())
		{
			string l;
			getline(myFile, l, ',');
		}
	}
};

class fisiereSeral : public Seral
{
	static int nrElevi;
	char* nume;
	const int anNastere;
	int clasa;
	int nrMaterii;
	float* note;
	int premiu;

public:
	void writeToFile(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		f.write(nume, sizeof(char) * lungime);
		f.write((char*)&this->anNastere, sizeof(this->anNastere));
		f.write((char*)&this->clasa, sizeof(this->clasa));
		f.write((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		for (int i = 0; i < this->nrMaterii; i++)
		{
			f.write((char*)&this->note[i], sizeof(this->note[i]));
		}
		f.write((char*)&this->premiu, sizeof(this->premiu));
	}

	void readFromFile(ifstream& in)
	{
		int lungime = 0;
		in.read((char*)&lungime, sizeof(int));
		char* buffer = new char[lungime];
		in.read(buffer, lungime);
		this->nume = buffer;
		delete[] buffer;
		in.read((char*)&this->anNastere, sizeof(this->anNastere));
		in.read((char*)&this->clasa, sizeof(this->clasa));
		in.read((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		delete[] this->note;
		this->note = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			in.read((char*)&this->note[i], sizeof(this->note[i]));
		}
		in.read((char*)&this->premiu, sizeof(this->premiu));
	}

	void readCSV(ifstream& in)
	{
		ifstream myFile;
		myFile.open("Seral.csv");
		while (myFile.good())
		{
			string l;
			getline(myFile, l, ',');
		}
	}
};

class fisiereUniversitate : public Universitate
{
	static int nrElevi;
	char* nume;
	const int anNastere;
	int clasa;
	int nrMaterii;
	float* note;
	int premiu;

public:
	void writeToFile(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		f.write(nume, sizeof(char) * lungime);
		f.write((char*)&this->anNastere, sizeof(this->anNastere));
		f.write((char*)&this->clasa, sizeof(this->clasa));
		f.write((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		for (int i = 0; i < this->nrMaterii; i++)
		{
			f.write((char*)&this->note[i], sizeof(this->note[i]));
		}
		f.write((char*)&this->premiu, sizeof(this->premiu));
	}

	void readFromFile(ifstream& in)
	{
		int lungime = 0;
		in.read((char*)&lungime, sizeof(int));
		char* buffer = new char[lungime];
		in.read(buffer, lungime);
		this->nume = buffer;
		delete[] buffer;
		in.read((char*)&this->anNastere, sizeof(this->anNastere));
		in.read((char*)&this->clasa, sizeof(this->clasa));
		in.read((char*)&this->nrMaterii, sizeof(this->nrMaterii));
		delete[] this->note;
		this->note = new float[this->nrMaterii];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			in.read((char*)&this->note[i], sizeof(this->note[i]));
		}
		in.read((char*)&this->premiu, sizeof(this->premiu));
	}

	void readCSV(ifstream& in)
	{
		ifstream myFile;
		myFile.open("Universitate.csv");
		while (myFile.good())
		{
			string l;
			getline(myFile, l, ',');
		}
	}

};

class Elevi
{
	int nrElevi;
	int nrPremianti;
public:
	virtual void AdaugaElev(string nume, int varsta) = 0;
	virtual void StergeElev(string nume) = 0;
	virtual int numarElevi()
	{
		return nrElevi;
	}
	virtual int numarPremianti()
	{
		return nrPremianti;
	}

};

template <typename T>
class utilizareDate
{
private:
	vector<T> data;
public:
	utilizareDate() {}
	void adaugaDate(const T& element)
	{
		data.push_back(element);
	}
	void eliminaDate(const T& element)
	{
		auto it = find(data.begin(), data.end(), element);
		if (it != data.end())
		{
			data.erase(it);
		}
	}
	vector<T> getData()
	{
		return data;	
	}
};


class Meniu {
public:
	static void afisareMeniuPrincipal()
	{
		cout << "-------------------------------- MENIU --------------------------------" << endl;
		cout << "1) Afiseaza elevi" << endl;
		cout << "2) Introduceti informatii despre elevi de la tastatura" << endl;
		cout << "3) Salveaza informatiile" << endl;
		cout << "q) EXIT " << endl;
		cout << "Alege optiunea: ";
	}
};



int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Nu au fost transmise suficiente argumente!" << endl;
		return 1;
	}
	cout << "Numarul de argumente transmise: " << argc << endl;
	cout << "Primul fisier: " << argv[1] << endl;
	cout << "Al doilea fisier: " << argv[2] << endl;

	ScoalaPrimara sp1(2014, "Ionescu Andrei", 2, 3, new float[3]{ 9, 9.3f, 9.2f }, 1);
	ScoalaPrimara sp2(2013, "Cristescu Valentin", 3, 3, new float[3]{ 9.7f, 9.63f, 9.54f }, 2);
	ScoalaPrimara sp3(sp2);

	ScoalaGimnaziala sg1(2009, "Alexandru Daniel", 6, 1, new float[1]{ 9.64f }, 2);
	ScoalaGimnaziala sg2(2007, "Enache Cosmina", 8, 1, new float[1]{ 9.7f }, 1);

	Liceu li1(2005, "Pirvu Alexandru", 11, 1, new float[1]{ 9.34f }, 2);
	Liceu li2(2004, "Ungureanu George", 12, 1, new float[1]{ 9.54f }, 1);

	Seral se1(1999, "Petrescu Carmen", 12, 2, new float[2]{ 8.6f, 8.3f }, 2);
	Seral se2(2000, "Cotenescu Rares", 12, 2, new float[2]{ 9, 9.15f }, 1);

	Universitate uni(2001, "Popa Mihaela", 3, 1, new float[1]{ 9.73f }, 1);
	Universitate uni1(2001, "Mutu Mihaela", 3, 2, new float[2]{ 9, 9.3f }, 2);
	Universitate uni2(2002, "Codrea Razvan", 2, 2, new float[2]{ 8.7f, 7.3f }, 3);


	ScoalaPrimara sp4;

	ofstream fout;
	fout.open("ScoalaPrimara.txt", ofstream::out);
	if (fout.is_open()) {
		fout << sp4;
		fout.close();
	}

	ScoalaGimnaziala sg3;

	ifstream fin;
	fin.open("ScoalaGimnaziala.txt", ifstream::in);
	if (fin.is_open())
	{
		fin >> sg3;
		fin.close();
	}

	Seral se3;

	ifstream fin1;
	fin1.open("Seral.txt", ifstream::in);
	if (fin1.is_open())
	{
		fin1 >> se3;
		fin1.close();
	}


	Liceu li3;

	ofstream fout2;
	fout2.open("Liceu.bin", ofstream::binary);
	if (fout2.is_open())
	{
		//li3.writeToFile(fout2);
		fout2.close();
	}

	Universitate uni3;

	ifstream fin2;
	fin2.open("Universitate.bin", ifstream::binary);
	if (fin2.is_open())
	{
		//uni3.citireBinar(fin2);
		fin2.close();
	}
	Meniu m;
	m.afisareMeniuPrincipal();

	char optiune;
	while (true)
	{
		cin >> optiune;
		switch (optiune)
		{
		case '1':
		{
			cout << "----------- Scoala primara -----------" << endl;
			cout << sp1 << endl;
			cout << sp2 << endl;
			cout << "----------- Scoala gimnaziala -----------" << endl;
			cout << sg1 << endl;
			cout << sg2 << endl;
			cout << "----------- Liceu -----------" << endl;
			cout << li1 << endl;
			cout << li2 << endl;
			cout << "----------- Seral -----------" << endl;
			cout << se1 << endl;
			cout << se2 << endl;
			cout << "----------- Universitate -----------" << endl;
			cout << uni1 << endl;
			cout << uni2 << endl;
			break;
		}
		case '2':
		{
			cin >> sp4;
			cout << endl;
			cin >> sg3;
			cout << endl;
			cin >> li3;
			cout << endl;
			cin >> se3;
			cout << endl;
			cin >> uni3;
			break;
		}
		case '3':
		{
			ofstream bin1;
			bin1.open("elevi.bin", ofstream::binary);
			if (bin1.is_open()) {
				//readFromFile.scriereBinar(bin1, uni3);
			}
			bin1.close();
			cout << "Fisier salvat" << endl;
			break;
		}
		case 'q':
			return 0;
		default:
			cout << "Optiunea aleasa nu este valida. Va rugam alegeti din nou." << endl;
		}
	}
	return 0;
}

