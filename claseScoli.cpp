#pragma warning(disable:4996)
#include <iostream>
#include <string>

using namespace std;
//									    SCOALA PRIMARA

class ScoalaPrimara {
private:
	static int nrElevi;
	char* nume = NULL;
	const int anNastere = 0;
	int clasa = 0;
	int nrMaterii = 0;
	float* note = 0;
	int premiu = 0;

public:
	ScoalaPrimara() :anNastere() {}

	ScoalaPrimara(const int panNastere, const char* pnume, int pclasa, int pnrMaterii, float* pnote, int ppremiu) :anNastere()
	{
		nrElevi++;
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		if (pclasa != 0)
		{
			this->clasa = pclasa;
		}
		if (pnrMaterii != 0 && pnote != NULL)
		{
			this->nrMaterii = pnrMaterii;
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
		if (ppremiu != 0)
		{
			this->premiu = ppremiu;
		}
	}

	ScoalaPrimara(const ScoalaPrimara& sursa) :anNastere(sursa.anNastere)
	{
		nrElevi++;
		if (nume != NULL)
		{
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
		}
		if (clasa != 0)
		{
			this->clasa = sursa.clasa;
		}
		if (nrMaterii != NULL && note != 0)
		{
			this->nrMaterii = sursa.nrMaterii;
			this->note = new float[sursa.nrMaterii];
			for (int i = 0; i < sursa.nrMaterii; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
		if (premiu != 0)
		{
			this->premiu = sursa.premiu;
		}

	}


	static int getNrElevi()
	{
		return ScoalaPrimara::nrElevi;
	}
	char* getNume()
	{
		return this->nume;
	}
	int getClasa()
	{
		return this->clasa;
	}
	int getNrMaterii()
	{
		return this->nrMaterii;
	}
	float* getNote()
	{
		return this->note;
	}
	int getPremiu()
	{
		return this->premiu;
	}


	void setNrElevi(int pnrElevi)
	{
		if (nrElevi != 0)
		{
			ScoalaPrimara::nrElevi = pnrElevi;
		}
	}

	void setNume(const char* pnume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		else
		{
			cout << "\nNumele nu poate fi setat!" << endl;
		}
	}

	void setClasa(int pclasa)
	{
		if (this->clasa != 0)
		{
			this->clasa = pclasa;
		}
	}

	void setNote(int pnrMaterii, float* pnote)
	{
		if (this->nrMaterii > 0)
		{
			this->nrMaterii = pnrMaterii;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}
		if (pnote != 0)
		{
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
	}

	void setPremiu(int ppremiu)
	{
		if (this->premiu != NULL)
		{
			this->premiu = ppremiu;
		}
	}


	ScoalaPrimara& operator =(const ScoalaPrimara& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->nume;
			delete[] this->note;
			if (nume != NULL)
			{
				this->nume = new char[strlen(sursa.nume) + 1];
				strcpy(this->nume, sursa.nume);
			}
			if (clasa != 0)
			{
				this->clasa = sursa.clasa;
			}
			if (nrMaterii != 0 && note != NULL)
			{
				this->nrMaterii = sursa.nrMaterii;
				this->note = new float[sursa.nrMaterii];
				for (int i = 0; i < sursa.nrMaterii; i++)
				{
					this->note[i] = sursa.note[i];
				}
			}
			if (premiu != 0)
			{
				this->premiu = sursa.premiu;
			}
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, ScoalaPrimara sursa)
	{
		out << sursa.nume << endl;
		out << sursa.clasa << endl;
		out << sursa.nrMaterii << endl;
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			out << sursa.note[i] << endl;
		}
		out << sursa.premiu << endl;
		return out;
	}

	friend istream& operator >> (istream& in, ScoalaPrimara& sursa)
	{
		if (sursa.nume != NULL)
		{
			delete[] sursa.nume;
		}
		if (sursa.note != NULL)
		{
			delete[] sursa.note;
		}

		cout << "Numele elevului: ";
		char buffer[199];
		in.getline(buffer, 199);
		//in >> buffer;
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);

		cout << endl;
		cout << "Clasa: ";
		in >> sursa.clasa;

		cout << "Numarul materiilor la care a fost premiat: ";
		in >> sursa.nrMaterii;
		sursa.note = new float[sursa.nrMaterii];
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			cout << "Notele elevului: ";
			in >> sursa.note[i];
		}

		cout << "Locul obtinut de catre elev: ";
		in >> sursa.premiu;

		return in;
	}

	float operator[](int index)
	{
		if (index >= 0 && index < this->nrMaterii)
			return this->note[index];
	}

	ScoalaPrimara operator+(int note)
	{
		ScoalaPrimara rez = *this;
		rez = rez + note;
		return *this;
	}

	ScoalaPrimara& operator++()
	{
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
	}

	ScoalaPrimara& operator++(int)
	{
		ScoalaPrimara copie = *this;
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
		return copie;
	}

	bool operator >=(const ScoalaPrimara& sursa)
	{
		if (this->premiu >= sursa.premiu)
			return sursa.premiu;
	}

	bool operator ==(const ScoalaPrimara& sursa)
	{
		if (this->nrMaterii != sursa.nrMaterii)
		{
			return false;
		}
		else return true;
	}

	bool operator !()
	{
		if (this->nrMaterii == 0)
		{
			return true;
		}
		else return false;
	}
	operator float()
	{
		return this->note[this->nrMaterii - 1];
	}

	~ScoalaPrimara()
	{
		delete[] this->nume;
		delete[] this->note;
		nrElevi--;
	}
};

int ScoalaPrimara::nrElevi = 0;

//									  SCOALA GIMNAZIALA
class ScoalaGimnaziala {
private:
	static int nrElevi;
	char* nume = NULL;
	const int anNastere = 0;
	int clasa = 0;
	int nrMaterii = 0;
	float* note = 0;
	int premiu = 0;

public:
	ScoalaGimnaziala() :anNastere() {}

	ScoalaGimnaziala(const int panNastere, const char* pnume, int pclasa, int pnrMaterii, float* pnote, int ppremiu) :anNastere()
	{
		nrElevi++;
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		if (pclasa != 0)
		{
			this->clasa = pclasa;
		}
		if (pnrMaterii != 0 && pnote != NULL)
		{
			this->nrMaterii = pnrMaterii;
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
		if (ppremiu != 0)
		{
			this->premiu = ppremiu;
		}
	}

	ScoalaGimnaziala(const ScoalaGimnaziala& sursa) :anNastere(sursa.anNastere)
	{
		nrElevi++;
		if (nume != NULL)
		{
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
		}
		if (clasa != 0)
		{
			this->clasa = sursa.clasa;
		}
		if (nrMaterii != NULL && note != 0)
		{
			this->nrMaterii = sursa.nrMaterii;
			this->note = new float[sursa.nrMaterii];
			for (int i = 0; i < sursa.nrMaterii; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
		if (premiu != 0)
		{
			this->premiu = sursa.premiu;
		}

	}


	static int getNrElevi()
	{
		return ScoalaGimnaziala::nrElevi;
	}
	char* getNume()
	{
		return this->nume;
	}
	int getClasa()
	{
		return this->clasa;
	}
	int getNrMaterii()
	{
		return this->nrMaterii;
	}
	float* getNote()
	{
		return this->note;
	}
	int getPremiu()
	{
		return this->premiu;
	}


	void setNrElevi(int pnrElevi)
	{
		if (nrElevi != 0)
		{
			ScoalaGimnaziala::nrElevi = pnrElevi;
		}
	}

	void setNume(const char* pnume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		else
		{
			cout << "\nNumele nu poate fi setat!" << endl;
		}
	}

	void setClasa(int pclasa)
	{
		if (this->clasa != 0)
		{
			this->clasa = pclasa;
		}
	}

	void setNote(int pnrMaterii, float* pnote)
	{
		if (this->nrMaterii > 0)
		{
			this->nrMaterii = pnrMaterii;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}
		if (pnote != 0)
		{
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
	}

	void setPremiu(int ppremiu)
	{
		if (this->premiu != NULL)
		{
			this->premiu = ppremiu;
		}
	}


	ScoalaGimnaziala& operator =(const ScoalaGimnaziala& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->nume;
			delete[] this->note;
			if (nume != NULL)
			{
				this->nume = new char[strlen(sursa.nume) + 1];
				strcpy(this->nume, sursa.nume);
			}
			if (clasa != 0)
			{
				this->clasa = sursa.clasa;
			}
			if (nrMaterii != 0 && note != NULL)
			{
				this->nrMaterii = sursa.nrMaterii;
				this->note = new float[sursa.nrMaterii];
				for (int i = 0; i < sursa.nrMaterii; i++)
				{
					this->note[i] = sursa.note[i];
				}
			}
			if (premiu != 0)
			{
				this->premiu = sursa.premiu;
			}
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, ScoalaGimnaziala sursa)
	{
		out << sursa.nume << endl;
		out << sursa.clasa << endl;
		out << sursa.nrMaterii << endl;
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			out << sursa.note[i] << endl;
		}
		out << sursa.premiu << endl;
		return out;
	}

	friend istream& operator >> (istream& in, ScoalaGimnaziala& sursa)
	{
		if (sursa.nume != NULL)
		{
			delete[] sursa.nume;
		}
		if (sursa.note != NULL)
		{
			delete[] sursa.note;
		}

		cout << "Numele elevului: ";
		char buffer[199];
		in.getline(buffer, 199);
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);

		cout << endl;
		cout << "Clasa: ";
		in >> sursa.clasa;

		cout << "Numarul materiilor la care a fost premiat: ";
		in >> sursa.nrMaterii;
		sursa.note = new float[sursa.nrMaterii];
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			cout << "Notele elevului: ";
			in >> sursa.note[i];
		}

		cout << "Locul obtinut de catre elev: ";
		in >> sursa.premiu;

		return in;
	}

	float operator[](int index)
	{
		if (index >= 0 && index < this->nrMaterii)
			return this->note[index];
	}

	ScoalaGimnaziala operator+(int note)
	{
		ScoalaGimnaziala rez = *this;
		rez = rez + note;
		return *this;
	}

	ScoalaGimnaziala& operator++()
	{
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
	}

	ScoalaGimnaziala& operator++(int)
	{
		ScoalaGimnaziala copie = *this;
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
		return copie;
	}

	bool operator >=(const ScoalaGimnaziala& sursa)
	{
		if (this->premiu >= sursa.premiu)
			return sursa.premiu;
	}

	bool operator ==(const ScoalaGimnaziala& sursa)
	{
		if (this->nrMaterii != sursa.nrMaterii)
		{
			return false;
		}
		else return true;
	}

	bool operator !()
	{
		if (this->nrMaterii == 0)
		{
			return true;
		}
		else return false;
	}

	operator float()
	{
		return this->note[this->nrMaterii - 1];
	}

	~ScoalaGimnaziala()
	{
		delete[] this->nume;
		delete[] this->note;
		nrElevi--;
	}
};

int ScoalaGimnaziala::nrElevi = 0;

//										    LICEU
class Liceu {
private:
	static int nrElevi;
	char* nume = NULL;
	const int anNastere = 0;
	int clasa = 0;
	int nrMaterii = 0;
	float* note = NULL;
	int premiu = 0;

public:
	Liceu() :anNastere() {}

	Liceu(const int panNastere, const char* pnume, int pclasa, int pnrMaterii, float* pnote, int ppremiu) :anNastere()
	{
		nrElevi++;
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		if (pclasa != 0)
		{
			this->clasa = pclasa;
		}
		if (pnrMaterii != 0 && pnote != NULL)
		{
			this->nrMaterii = pnrMaterii;
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
		if (ppremiu != 0)
		{
			this->premiu = ppremiu;
		}
	}

	Liceu(const Liceu& sursa) :anNastere(sursa.anNastere)
	{
		nrElevi++;
		if (nume != NULL)
		{
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
		}
		if (clasa != 0)
		{
			this->clasa = sursa.clasa;
		}
		if (nrMaterii != NULL && note != 0)
		{
			this->nrMaterii = sursa.nrMaterii;
			this->note = new float[sursa.nrMaterii];
			for (int i = 0; i < sursa.nrMaterii; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
		if (premiu != 0)
		{
			this->premiu = sursa.premiu;
		}

	}


	static int getNrElevi()
	{
		return Liceu::nrElevi;
	}
	char* getNume()
	{
		return this->nume;
	}
	int getClasa()
	{
		return this->clasa;
	}
	int getNrMaterii()
	{
		return this->nrMaterii;
	}
	float* getNote()
	{
		return this->note;
	}
	int getPremiu()
	{
		return this->premiu;
	}


	void setNrElevi(int pnrElevi)
	{
		if (nrElevi != 0)
		{
			Liceu::nrElevi = pnrElevi;
		}
	}

	void setNume(const char* pnume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		else
		{
			cout << "\nNumele nu poate fi setat!" << endl;
		}
	}

	void setClasa(int pclasa)
	{
		if (this->clasa != 0)
		{
			this->clasa = pclasa;
		}
	}

	void setNote(int pnrMaterii, float* pnote)
	{
		if (this->nrMaterii > 0)
		{
			this->nrMaterii = pnrMaterii;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}
		if (pnote != 0)
		{
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
	}

	void setPremiu(int ppremiu)
	{
		if (this->premiu != NULL)
		{
			this->premiu = ppremiu;
		}
	}


	Liceu& operator =(const Liceu& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->nume;
			delete[] this->note;
			if (nume != NULL)
			{
				this->nume = new char[strlen(sursa.nume) + 1];
				strcpy(this->nume, sursa.nume);
			}
			if (clasa != 0)
			{
				this->clasa = sursa.clasa;
			}
			if (nrMaterii != 0 && note != NULL)
			{
				this->nrMaterii = sursa.nrMaterii;
				this->note = new float[sursa.nrMaterii];
				for (int i = 0; i < sursa.nrMaterii; i++)
				{
					this->note[i] = sursa.note[i];
				}
			}
			if (premiu != 0)
			{
				this->premiu = sursa.premiu;
			}
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, Liceu sursa)
	{
		out << sursa.nume << endl;
		out << sursa.clasa << endl;
		out << sursa.nrMaterii << endl;
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			out << sursa.note[i] << endl;
		}
		out << sursa.premiu << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Liceu& sursa)
	{
		if (sursa.nume != NULL)
		{
			delete[] sursa.nume;
		}
		if (sursa.note != NULL)
		{
			delete[] sursa.note;
		}

		cout << "Numele elevului: ";
		char buffer[199];
		in.getline(buffer, 199);
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);
		cout << endl;
		cout << "Clasa: ";
		in >> sursa.clasa;

		cout << "Numarul materiilor la care a fost premiat: ";
		in >> sursa.nrMaterii;
		sursa.note = new float[sursa.nrMaterii];
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			cout << "Notele elevului: ";
			in >> sursa.note[i];
		}

		cout << "Locul obtinut de catre elev: ";
		in >> sursa.premiu;

		return in;
	}

	float operator[](int index)
	{
		if (index >= 0 && index < this->nrMaterii)
			return this->note[index];
	}

	Liceu operator+(int note)
	{
		Liceu rez = *this;
		rez = rez + note;
		return *this;
	}

	Liceu& operator++()
	{
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
	}

	Liceu& operator++(int)
	{
		Liceu copie = *this;
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
		return copie;
	}

	bool operator >=(const Liceu& sursa)
	{
		if (this->premiu >= sursa.premiu)
			return sursa.premiu;
	}

	bool operator ==(const Liceu& sursa)
	{
		if (this->nrMaterii != sursa.nrMaterii)
		{
			return false;
		}
		else return true;
	}

	bool operator !()
	{
		if (this->nrMaterii == 0)
		{
			return true;
		}
		else return false;
	}

	operator float()
	{
		return this->note[this->nrMaterii - 1];
	}

	~Liceu()
	{
		delete[] this->nume;
		delete[] this->note;
		nrElevi--;
	}
};

int Liceu::nrElevi = 0;

//											SERAL
class Seral {
private:
	static int nrElevi;
	char* nume = NULL;
	const int anNastere = 0;
	int clasa = 0;
	int nrMaterii = 0;
	float* note = NULL;
	int premiu = 0;

public:
	Seral() :anNastere() {}

	Seral(const int panNastere, const char* pnume, int pclasa, int pnrMaterii, float* pnote, int ppremiu) :anNastere()
	{
		nrElevi++;
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		if (pclasa != 0)
		{
			this->clasa = pclasa;
		}
		if (pnrMaterii != 0 && pnote != NULL)
		{
			this->nrMaterii = pnrMaterii;
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
		if (ppremiu != 0)
		{
			this->premiu = ppremiu;
		}
	}

	Seral(const Seral& sursa) :anNastere(sursa.anNastere)
	{
		nrElevi++;
		if (nume != NULL)
		{
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
		}
		if (clasa != 0)
		{
			this->clasa = sursa.clasa;
		}
		if (nrMaterii != NULL && note != 0)
		{
			this->nrMaterii = sursa.nrMaterii;
			this->note = new float[sursa.nrMaterii];
			for (int i = 0; i < sursa.nrMaterii; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
		if (premiu != 0)
		{
			this->premiu = sursa.premiu;
		}

	}


	static int getNrElevi()
	{
		return Seral::nrElevi;
	}
	char* getNume()
	{
		return this->nume;
	}
	int getClasa()
	{
		return this->clasa;
	}
	int getNrMaterii()
	{
		return this->nrMaterii;
	}
	float* getNote()
	{
		return this->note;
	}
	int getPremiu()
	{
		return this->premiu;
	}


	void setNrElevi(int pnrElevi)
	{
		if (nrElevi != 0)
		{
			Seral::nrElevi = pnrElevi;
		}
	}

	void setNume(const char* pnume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		else
		{
			cout << "\nNumele nu poate fi setat!" << endl;
		}
	}

	void setClasa(int pclasa)
	{
		if (this->clasa != 0)
		{
			this->clasa = pclasa;
		}
	}

	void setNote(int pnrMaterii, float* pnote)
	{
		if (this->nrMaterii > 0)
		{
			this->nrMaterii = pnrMaterii;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}
		if (pnote != 0)
		{
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
	}

	void setPremiu(int ppremiu)
	{
		if (this->premiu != NULL)
		{
			this->premiu = ppremiu;
		}
	}


	Seral& operator =(const Seral& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->nume;
			delete[] this->note;
			if (nume != NULL)
			{
				this->nume = new char[strlen(sursa.nume) + 1];
				strcpy(this->nume, sursa.nume);
			}
			if (clasa != 0)
			{
				this->clasa = sursa.clasa;
			}
			if (nrMaterii != 0 && note != NULL)
			{
				this->nrMaterii = sursa.nrMaterii;
				this->note = new float[sursa.nrMaterii];
				for (int i = 0; i < sursa.nrMaterii; i++)
				{
					this->note[i] = sursa.note[i];
				}
			}
			if (premiu != 0)
			{
				this->premiu = sursa.premiu;
			}
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, Seral sursa)
	{
		out << sursa.nume << endl;
		out << sursa.clasa << endl;
		out << sursa.nrMaterii << endl;
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			out << sursa.note[i] << endl;
		}
		out << sursa.premiu << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Seral& sursa)
	{
		if (sursa.nume != NULL)
		{
			delete[] sursa.nume;
		}
		if (sursa.note != NULL)
		{
			delete[] sursa.note;
		}

		cout << "Numele elevului: ";
		char buffer[199];
		in.getline(buffer, 199);
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);

		cout << endl;
		cout << "Clasa: ";
		in >> sursa.clasa;

		cout << "Numarul materiilor la care a fost premiat: ";
		in >> sursa.nrMaterii;
		sursa.note = new float[sursa.nrMaterii];
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			cout << "Notele elevului: ";
			in >> sursa.note[i];
		}

		cout << "Locul obtinut de catre elev: ";
		in >> sursa.premiu;

		return in;
	}

	float operator[](int index)
	{
		if (index >= 0 && index < this->nrMaterii)
			return this->note[index];
	}

	Seral operator+(int note)
	{
		Seral rez = *this;
		rez = rez + note;
		return *this;
	}

	Seral& operator++()
	{
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
	}

	Seral& operator++(int)
	{
		Seral copie = *this;
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
		return copie;
	}

	bool operator >=(const Seral& sursa)
	{
		if (this->premiu >= sursa.premiu)
			return sursa.premiu;
	}

	bool operator ==(const Seral& sursa)
	{
		if (this->nrMaterii != sursa.nrMaterii)
		{
			return false;
		}
		else return true;
	}

	bool operator !()
	{
		if (this->nrMaterii == 0)
		{
			return true;
		}
		else return false;
	}
	operator float()
	{
		return this->note[this->nrMaterii - 1];
	}

	~Seral()
	{
		delete[] this->nume;
		delete[] this->note;
		nrElevi--;
	}
};

int Seral::nrElevi = 0;

//										 UNIVERSITATE
class Universitate {
private:
	static int nrElevi;
	char* nume = NULL;
	const int anNastere;
	int clasa = 0;
	int nrMaterii = 0;
	float* note = NULL;
	int premiu = 0;

public:
	Universitate() :anNastere() {}

	Universitate(const int panNastere, const char* pnume, int pclasa, int pnrMaterii, float* pnote, int ppremiu) :anNastere()
	{
		nrElevi++;
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		if (pclasa != 0)
		{
			this->clasa = pclasa;
		}
		if (pnrMaterii != 0 && pnote != NULL)
		{
			this->nrMaterii = pnrMaterii;
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
		if (ppremiu != 0)
		{
			this->premiu = ppremiu;
		}
	}

	Universitate(const Universitate& sursa) :anNastere(sursa.anNastere)
	{
		nrElevi++;
		if (nume != NULL)
		{
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
		}
		if (clasa != 0)
		{
			this->clasa = sursa.clasa;
		}
		if (nrMaterii != NULL && note != 0)
		{
			this->nrMaterii = sursa.nrMaterii;
			this->note = new float[sursa.nrMaterii];
			for (int i = 0; i < sursa.nrMaterii; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
		if (premiu != 0)
		{
			this->premiu = sursa.premiu;
		}

	}

	static int getNrElevi()
	{
		return Universitate::nrElevi;
	}
	char* getNume()
	{
		return this->nume;
	}
	int getClasa()
	{
		return this->clasa;
	}
	int getNrMaterii()
	{
		return this->nrMaterii;
	}
	float* getNote()
	{
		return this->note;
	}
	int getPremiu()
	{
		return this->premiu;
	}


	void setNrElevi(int pnrElevi)
	{
		if (nrElevi != 0)
		{
			Universitate::nrElevi = pnrElevi;
		}
	}

	void setNume(const char* pnume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (pnume != NULL)
		{
			this->nume = new char[strlen(pnume) + 1];
			strcpy(this->nume, pnume);
		}
		else
		{
			cout << "\nNumele nu poate fi setat!" << endl;
		}
	}

	void setClasa(int pclasa)
	{
		if (this->clasa != 0)
		{
			this->clasa = pclasa;
		}
	}

	void setNote(int pnrMaterii, float* pnote)
	{
		if (this->nrMaterii > 0)
		{
			this->nrMaterii = pnrMaterii;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}
		if (pnote != 0)
		{
			this->note = new float[pnrMaterii];
			for (int i = 0; i < pnrMaterii; i++)
			{
				this->note[i] = pnote[i];
			}
		}
	}

	void setPremiu(int ppremiu)
	{
		if (this->premiu != NULL)
		{
			this->premiu = ppremiu;
		}
	}


	Universitate& operator =(const Universitate& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->nume;
			delete[] this->note;
			if (nume != NULL)
			{
				this->nume = new char[strlen(sursa.nume) + 1];
				strcpy(this->nume, sursa.nume);
			}
			if (clasa != 0)
			{
				this->clasa = sursa.clasa;
			}
			if (nrMaterii != 0 && note != NULL)
			{
				this->nrMaterii = sursa.nrMaterii;
				this->note = new float[sursa.nrMaterii];
				for (int i = 0; i < sursa.nrMaterii; i++)
				{
					this->note[i] = sursa.note[i];
				}
			}
			if (premiu != 0)
			{
				this->premiu = sursa.premiu;
			}
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, Universitate sursa)
	{
		out << sursa.nume << endl;
		out << sursa.clasa << endl;
		out << sursa.nrMaterii << endl;
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			out << sursa.note[i] << endl;
		}
		out << sursa.premiu << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Universitate& sursa)
	{
		if (sursa.nume != NULL)
		{
			delete[] sursa.nume;
		}
		if (sursa.note != NULL)
		{
			delete[] sursa.note;
		}

		cout << "Numele elevului: ";
		char buffer[199];
		in.getline(buffer, 199);
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);

		cout << endl;
		cout << "Clasa: ";
		in >> sursa.clasa;

		cout << "Numarul materiilor la care a fost premiat: ";
		in >> sursa.nrMaterii;
		sursa.note = new float[sursa.nrMaterii];
		for (int i = 0; i < sursa.nrMaterii; i++)
		{
			cout << "Notele elevului: ";
			in >> sursa.note[i];
		}

		cout << "Locul obtinut de catre elev: ";
		in >> sursa.premiu;

		return in;
	}

	float operator[](int index)
	{
		if (index >= 0 && index < this->nrMaterii)
			return this->note[index];
	}

	Universitate operator+(int note)
	{
		Universitate rez = *this;
		rez = rez + note;
		return *this;
	}

	Universitate& operator++()
	{
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
	}

	Universitate& operator++(int)
	{
		Universitate copie = *this;
		float* vn = new float[this->nrMaterii + 1];
		for (int i = 0; i < this->nrMaterii; i++)
		{
			vn[i] = this->note[i];
		}
		vn[this->nrMaterii] = 0;
		delete[]this->note;

		this->note = vn;
		this->nrMaterii++;

		return *this;
		return copie;
	}

	bool operator >=(const Universitate& sursa)
	{
		if (this->premiu >= sursa.premiu)
			return sursa.premiu;
	}

	bool operator ==(const Universitate& sursa)
	{
		if (this->nrMaterii != sursa.nrMaterii)
		{
			return false;
		}
		else return true;
	}

	bool operator !()
	{
		if (this->nrMaterii == 0)
		{
			return true;
		}
		else return false;
	}

	operator float()
	{
		return this->note[this->nrMaterii - 1];
	}

	~Universitate()
	{
		delete[] this->nume;
		delete[] this->note;
		nrElevi--;
	}
};

int Universitate::nrElevi = 0;


