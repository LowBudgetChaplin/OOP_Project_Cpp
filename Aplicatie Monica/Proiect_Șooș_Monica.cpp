#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class User {
private:
    const int anNastere;
    int id=0;
    char* nume=NULL;
    int* varsta=NULL;
    static int nrUseri;

public:
    // constructor fara parametrii
    User() : anNastere(){}
    // constructor cu toti parametrii
    User(const int panNastere, int pid, const char* pnume, int* pvarsta) :anNastere()
    {
        nrUseri++;
        if (pnume != NULL)
        {
            this->nume = new char[strlen(pnume) + 1];
            strcpy(this->nume, pnume);
        }
        if (pid != 0 && pvarsta != NULL)
        {
            this->id = pid;
            this->varsta = new int[pid];
            for (int i = 0; i < pid; i++)
            {
                this->varsta[i] = pvarsta[i];
            }
        }
    }
    // constrcutor de copiere
    User(const User& sursa) :anNastere(sursa.anNastere)
    {
        nrUseri++;
        if (nume != NULL)
        {
            this->nume = new char[strlen(sursa.nume) + 1];
            strcpy(this->nume, sursa.nume);
        }
        if (id != 0 && varsta != NULL)
        {
            this->id = sursa.id;
            this->varsta = new int[sursa.id];
            for (int i = 0; i < sursa.id; i++)
            {
                this->varsta[i] = sursa.varsta[i];
            }
        }
    }

    // getters
    int getId()
    { 
        return this->id;
    }
    char* getNume()
    {
        return this->nume;
    }
    int* getVarsta()
    {
        return this->varsta;
    }
    int getNrUseri()
    {
        return User::nrUseri;
    }

    // setters
    void setId(int pid, int* pvarsta)
    {
        if (this->id != 0)
        {
            this->id = pid;
        }
        if (this->varsta != NULL)
        {
            delete[] this->varsta;
        }
        if (pvarsta != 0)
        {
            this->varsta = new int[pid];
            for (int i = 0; i < pid; i++)
            {
                this->varsta[i] = pvarsta[i];
            }
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
    void setNrUseri(int pnrUseri)
    {
        if (pnrUseri != 0)
        {
            User::nrUseri = pnrUseri;
        }
    }

    // Supraincarcare de operatori
    User& operator = (const User& sursa)
    {
        if (this != &sursa)   // sa nu se poata autoasigna
        {
            delete[] this->nume;
            delete[] this->varsta;
        }
        if (nume != NULL)
        {
            this->nume = new char[strlen(sursa.nume) + 1];
            strcpy(this->nume, sursa.nume);
        }
        if (id != 0 && varsta != NULL)
        {
            this->id = sursa.id;
            this->varsta = new int[sursa.id];
            for (int i = 0; i < sursa.id; i++)
            {
                this->varsta[i] = sursa.varsta[i];
            }
        }
        return *this;
    }

    friend ostream& operator << (ostream& out, User sursa)
    {
        out << sursa.nume << endl;
        out << sursa.id << endl;
        for (int i = 0; i < sursa.id; i++)
        {
            out << sursa.varsta[i] << endl;
        }
        return out;
    }
    friend istream& operator >> (istream& in, User& sursa)
    {
        if (sursa.nume != NULL)
        {
            delete[] sursa.nume;
        }
        if (sursa.varsta != NULL)
        {
            delete[] sursa.varsta;
        }
        cout << "ID-ul user-ului: ";
        in >> sursa.id;
        sursa.varsta = new int[sursa.id];
        for (int i = 0; i < sursa.id; i++)
        {
            cout << "Varsta user-ului: ";
            in >> sursa.varsta[i];
        }
        cout << "Numele user-ului: ";
        char buffer[200];
        in.getline(buffer, 200);            //ca sa poti scrie nume cu spatiu
        sursa.nume = new char[strlen(buffer) + 1];
        strcpy(sursa.nume, buffer);
        return in;
    }

    User operator+(const User& s)
    {
    User rez = *this;
    rez.id += s.id;
    return rez;
    }

    User operator-(const User& s)
    {
        User rez = *this;
        rez.id -= s.id;
        return rez;
    }

    User operator++(int) {
        User r = *this;
        ++id;
        ++varsta;
        return r;
    }

    // Destructor
    ~User()
    {
        delete[] this->nume;
        delete[] this->varsta;
        nrUseri--;
    }
};
int User::nrUseri = 0;


class Admin {
private:
    const int anNastere;
    int id = 0;
    char* nume = NULL;
    int* varsta = NULL;
    static int nrAdmini;

public:
    // constructor fara parametrii
    Admin() : anNastere() {}
    // constructor cu toti parametrii
    Admin(const int panNastere, int pid, const char* pnume, int* pvarsta) :anNastere()
    {
        nrAdmini++;
        if (pnume != NULL)
        {
            this->nume = new char[strlen(pnume) + 1];
            strcpy(this->nume, pnume);
        }
        if (pid != 0 && pvarsta != NULL)
        {
            this->id = pid;
            this->varsta = new int[pid];
            for (int i = 0; i < pid; i++)
            {
                this->varsta[i] = pvarsta[i];
            }
        }
    }
    // constrcutor de copiere
    Admin(const Admin& sursa) :anNastere(sursa.anNastere)
    {
        nrAdmini++;
        if (nume != NULL)
        {
            this->nume = new char[strlen(sursa.nume) + 1];
            strcpy(this->nume, sursa.nume);
        }
        if (id != 0 && varsta != NULL)
        {
            this->id = sursa.id;
            this->varsta = new int[sursa.id];
            for (int i = 0; i < sursa.id; i++)
            {
                this->varsta[i] = sursa.varsta[i];
            }
        }
    }

    // getters
    int getId()
    {
        return this->id;
    }
    char* getNume()
    {
        return this->nume;
    }
    int* getVarsta()
    {
        return this->varsta;
    }
    int getNrUseri()
    {
        return Admin::nrAdmini;
    }

    // setters
    void setId(int pid, int* pvarsta)
    {
        if (this->id != 0)
        {
            this->id = pid;
        }
        if (this->varsta != NULL)
        {
            delete[] this->varsta;
        }
        if (pvarsta != 0)
        {
            this->varsta = new int[pid];
            for (int i = 0; i < pid; i++)
            {
                this->varsta[i] = pvarsta[i];
            }
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
    void setNrUseri(int nrAdmini)
    {
        if (nrAdmini != 0)
        {
            Admin::nrAdmini = nrAdmini;
        }
    }

    // Supraincarcare de operatori
    Admin& operator = (const Admin& sursa)
    {
        if (this != &sursa) 
        {
            delete[] this->nume;
            delete[] this->varsta;
        }
        if (nume != NULL)
        {
            this->nume = new char[strlen(sursa.nume) + 1];
            strcpy(this->nume, sursa.nume);
        }
        if (id != 0 && varsta != NULL)
        {
            this->id = sursa.id;
            this->varsta = new int[sursa.id];
            for (int i = 0; i < sursa.id; i++)
            {
                this->varsta[i] = sursa.varsta[i];
            }
        }
        return *this;
    }

    friend ostream& operator << (ostream& out, Admin sursa)
    {
        out << sursa.nume << endl;
        out << sursa.id << endl;
        for (int i = 0; i < sursa.id; i++)
        {
            out << sursa.varsta[i] << endl;
        }
        return out;
    }
    friend istream& operator >> (istream& in, Admin& sursa)
    {
        if (sursa.nume != NULL)
        {
            delete[] sursa.nume;
        }
        if (sursa.varsta != NULL)
        {
            delete[] sursa.varsta;
        }
        cout << "ID-ul user-ului: ";
        in >> sursa.id;
        sursa.varsta = new int[sursa.id];
        for (int i = 0; i < sursa.id; i++)
        {
            cout << "Varsta user-ului: ";
            in >> sursa.varsta[i];
        }
        cout << "Numele user-ului: ";
        char buffer[200];
        in.getline(buffer, 200);
        sursa.nume = new char[strlen(buffer) + 1];
        strcpy(sursa.nume, buffer);
        return in;
    }

    Admin& operator+=(const Admin& s) {
        this->id += s.id;
        for (int i = 0; i < s.id; i++)
        {
            this->varsta += s.varsta[i];
        }
        return *this;
    }

    bool operator!() 
    {
    return !id;
    }

    bool operator >=(const Admin& sursa)
    {
        if (this->varsta >= sursa.varsta)
            return sursa.varsta;
    }

    // Destructor
    ~Admin()
    {
        delete[] this->nume;
        delete[] this->varsta;
        nrAdmini--;
    }
};
int Admin::nrAdmini = 0;



class UserProfil : public User {
private:
    string email;
    string telefon;

public:
    // constructor
    UserProfil(int id, string nume, int varsta, string email, string telefon) : email(email), telefon(telefon) {}

    UserProfil& operator=(const UserProfil& s) {
        User::operator=(s);
        this->email = s.email;
        this->telefon = s.telefon;
        return *this;
    }

    // getters
    string getAdresa()
    { 
        return email;
    }
    string getTelefon()
    { 
        return telefon; 
    }

    // setters
    void setAdresa(string email) 
    { 
        this->email = email; 
    }
    void setTelefon(string telefon) 
    { 
        this->telefon =  telefon; 
    }
};

//metode virtuale
class UserManager {
public:
    virtual void adaugaUser(const UserProfil& user) = 0;
    virtual void stergeUser(int id) = 0;
    virtual UserProfil* cautaUser(int id) = 0;
    virtual void displayUseri() const = 0;
};

class Fisier {
private:
    vector<UserProfil> users;
    string numeFisier;

public:
    Fisier(string fName) : numeFisier(fName) {}

    // citeste date din fisier si le stocheaza in vectorul de useri
    void readData() {
        ifstream file(numeFisier);
        if (file.is_open()) {
            int id;
            string nume;
            int varsta;
            string email;
            string telefon;
            while (file >> id >> nume >> varsta >> email >> telefon) 
            {
                UserProfil user(id, nume, varsta, email, telefon);
                users.push_back(user);
            }
            file.close();
        }
        else
        {
            cout << "Nu s-a putut deschide fisierul" << numeFisier << endl;
        }
    }

    // getters
    vector<UserProfil> obtineUseri() const 
    {
        return users; 
    }
};

//clasa template
template <typename T>
class ProcesareDate
{
private:
    vector<T> data;

public:
    // constructor
    ProcesareDate() {}

    // adauga date in vector
    void adaugaDate(const T& element) 
    {
        data.push_back(element);
    }

    // elimina date din vector
    void eliminaDate(const T& element) 
    {
        auto it = find(data.begin(), data.end(), element);
        if (it != data.end()) 
        {
            data.erase(it);
        }
    }

    // getter
    vector<T> getData()
    {
        return data;
    }
};


    //User u1(2000, 1, "Maria Popescu", new int[1]{22});
    //User u2;
    //cout << u1;
    //Fisier f1("test.txt");
    //f1.obtineUseri();
    int main()
    {

        User user;
        Admin admin;

        user.setId(1, new int[1]{ 20 });
        user.setNume("Popescu Camelia");

        admin.setId(2, new int[1]{ 21 });
        admin.setNume("Ionascu Eric");

        ofstream file("Users.txt", ios::app);
        if (file.is_open()) {
            file << "User: " << endl << user.getId() << " " << user.getNume() << " " << *(user.getVarsta()) << endl;
            file << "Admin: " << endl << admin.getId() << " " << admin.getNume() << " " << *(admin.getVarsta()) << endl;
            file.close();
        }
        else {
            cout << "Nu s-a putut deschide fisierul!" << endl;
        }
        return 0;
    }