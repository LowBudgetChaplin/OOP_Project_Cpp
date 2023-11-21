#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


class eleviScoalaPrimara {
private:
	float grade;
	char* nume;
	int varsta;

public:
	eleviScoalaPrimara(float grade_p, const char* nume, int varsta_p)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		grade = grade_p;
		varsta = varsta_p;

	}

	void display();
};

class eleviScoalaGimnaziala {
private:
	float gradeG;
	char* numeG;
	int varstaG;
public:
	eleviScoalaGimnaziala(float grade_g, const char* numeG, int varsta_g)
	{
		this->numeG = new char[strlen(numeG) + 1];
		strcpy(this->numeG, numeG);
		gradeG = grade_g;
		varstaG = varsta_g;
	}
	void display2();

};

class eleviLiceu {
private:
	float gradeL;
	char* numeL;
	int varstaL;
public:
	eleviLiceu(float grade_l, const char* numeL, int varsta_l) 
	{
		this->numeL[strlen(numeL) + 1];
		strcpy(this->numeL, numeL);
		gradeL = grade_l;
		varstaL = varsta_l;
	}
	void display3();

};

class eleviSeral 
{
private:
	float gradeS;
	char* numeS;
	int varstaS;
public:
	eleviSeral(float grade_s, const char* numeS, int varsta_s)
	{
		this->numeS[strlen(numeS) + 1];
		strcpy(this->numeS, numeS);
		gradeS = grade_s;
		varstaS = varsta_s;
	}
	void display4();
};

class eleviPostLiceala 
{
private:
	float gradePL;
	char* numePL;
	int varstaPL;
public:
	eleviPostLiceala(float grade_pl, const char* numePL, int varsta_pl)
	{
		this->numePL[strlen(numePL) + 1];
		strcpy(this->numePL, numePL);
		gradePL = grade_pl;
		varstaPL = varsta_pl;
	}
	void display5();
};


void eleviScoalaPrimara::display()
{
	cout << endl << "Numele elevului: " << nume;
	cout << endl << "Varsta elevului: " << varsta;
	cout << endl << "Rezultatul obtinut: " << grade << endl;

}

void eleviScoalaGimnaziala::display2()
{
	cout << endl << "Numele elevului: " << numeG;
	cout << endl << "Varsta elevului: " << varstaG;
	cout << endl << "Rezultatul obtinut: " << gradeG << endl;

}

void eleviLiceu::display3()
{
	cout << endl << "Numele elevului: " << numeL;
	cout << endl << "Varsta elevului: " << varstaL;
	cout << endl << "Rezultatul obtinut: " << gradeL << endl;

}

void eleviSeral::display4()
{
	cout << endl << "Numele elevului: " << numeS;
	cout << endl << "Varsta elevului: " << varstaS;
	cout << endl << "Rezultatul obtinut: " << gradeS << endl;

}

void eleviPostLiceala::display5()
{
	cout << endl << "Numele elevului: " << numePL;
	cout << endl << "Varsta elevului: " << varstaPL;
	cout << endl << "Rezultatul obtinut: " << gradePL << endl;

}


int main()
{

	eleviScoalaPrimara elev1 (9.27, "Corodesu Serban", 11);
	eleviScoalaGimnaziala elev2 (9.88, "Popescu Mihai", 14);
	eleviLiceu elev3 (9.12, "Berechet Bogdan", 17);
	eleviSeral elev4 (9.5, "Alexandru Daniel", 19);
	eleviPostLiceala elev5 (9.92, "Ionescu George", 20);

	elev1.display();
	elev2.display2();
	elev3.display3();
	elev4.display4();
	elev5.display5();

	cin.get();
	return 0;
}
