#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class User {
private:
    const int anNastere;
    int id;
    char* nume;
    int* varsta;
    static int nrUseri;

public:
    // constructor fara parametrii
    User() : anNastere()
    {
        nrUseri++;
        this->id = 0;
        this->nume = new char[strlen("na") + 1];
        strcpy(this->nume, "na");
        this->varsta = NULL;

    }
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
            this->varsta = new int[pvarsta];
            for (int i = 0; i < pvarsta; i++)
            {
                this->varsta = pvarsta[i];
            }
        }
    }

    User(const User& sursa) :anNastere(sursa.anNastere)
    {
        nrUseri++;
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

    User(int i, string n, int v) : id(i), nume(n), varsta(v) {}

    //User& operator=(const User& other) {
    //    id = other.id;
    //    name = other.name;
    //    age = other.age;
    //    return *this;
    //}

    //// getters
    //int getId() const { return id; }
    //string getName() const { return name; }
    //int getAge() const { return age; }

    //// setters
    //void setId(int i) { id = i; }
    //void setName(string n) { name = n; }
    //void setAge(int a) { age = a; }


    //// operatori
    //User operator+(const User& other) const {
    //    User result(*this);
    //    result.id += other.id;
    //    result.age += other.age;
    //    return result;
    //}

    //User operator-(const User& other) const {
    //    User result(*this);
    //    result.id -= other.id;
    //    result.age -= other.age;
    //    return result;
    //}

    //User operator*(int value) const {
    //    User result(*this);
    //    result.id *= value;
    //    result.age *= value;
    //    return result;
    //}

    //User operator/(int value) const {
    //    User result(*this);
    //    result.id /= value;
    //    result.age /= value;
    //    return result;
    //}

    //User& operator+=(const User& other) {
    //    id += other.id;
    //    age += other.age;
    //    return *this;
    //}

    //User& operator-=(const User& other) {
    //    id -= other.id;
    //    age -= other.age;
    //    return *this;
    //}

    //User& operator*=(int value) {
    //    id *= value;
    //    age *= value;
    //    return *this;
    //}

    //User& operator/=(int value) {
    //    id /= value;
    //    age /= value;
    //    return *this;
    //}

    //User& operator++() {
    //    ++id;
    //    ++age;
    //    return *this;
    //}

    //User operator++(int) {
    //    User temp(*this);
    //    ++id;
    //    ++age;
    //    return temp;
    //}

    //User& operator--() {
    //    --id;
    //    --age;
    //    return *this;
    //}

    //User operator--(int) {
    //    User temp(*this);
    //    --id;
    //    --age;
    //    return temp;
    //}

    //User operator[](int index) const {
    //    if (index == 0) {
    //        return User(id, name, age);
    //    }
    //    else {
    //        throw invalid_argument("Invalid index for User");
    //    }
    //}

    //User operator()(string newName, int newAge) const {
    //    return User(id, newName, newAge);
    //}

    //bool operator!() const {
    //    return !id;
    //}


};
int User::nrUseri = 0;



//class UserProfile : public User {
//private:
//    string address;
//    string phone;
//
//public:
//    // constructor
//    UserProfile(int i, string n, int a, string addr, string ph) : User(i, n, a), address(addr), phone(ph) {}
//
//    // assignment operator
//    UserProfile& operator=(const UserProfile& other) {
//        User::operator=(other); // assign base class attributes
//        address = other.address;
//        phone = other.phone;
//        return *this;
//    }
//
//    // getters
//    string getAddress() const { return address; }
//    string getPhone() const { return phone; }
//
//    // setters
//    void setAddress(string addr) { address = addr; }
//    void setPhone(string ph) { phone = ph; }
//};
//
//
//
//class UserManager {
//public:
//    virtual void addUser(const UserProfile& user) = 0;
//    virtual void removeUser(int id) = 0;
//    virtual UserProfile* findUser(int id) = 0;
//    virtual void displayUsers() const = 0;
//};
//
//
//
//class Session {
//private:
//    vector<UserProfile> users;
//    string fileName;
//
//public:
//    // constructor
//    Session(string fName) : fileName(fName) {}
//
//    // read data from file and store it in the users vector
//    void readData() {
//        ifstream file(fileName);
//        if (file.is_open()) {
//            int id;
//            string name;
//            int age;
//            string address;
//            string phone;
//            while (file >> id >> name >> age >> address >> phone) {
//                UserProfile user(id, name, age, address, phone);
//                users.push_back(user);
//            }
//            file.close();
//        }
//        else {
//            cout << "Error: could not open file " << fileName << endl;
//        }
//    }
//
//    // getters
//    vector<UserProfile> getUsers() const { return users; }
//};
//
//
//
//template <typename T>
//class DataProcessor {
//private:
//    vector<T> data;
//
//public:
//    // constructor
//    DataProcessor() {}
//
//    // add data to the vector
//    void addData(const T& element) {
//        data.push_back(element);
//    }
//
//    // remove data from the vector
//    void removeData(const T& element) {
//        auto it = find(data.begin(), data.end(), element);
//        if (it != data.end()) {
//            data.erase(it);
//        }
//    }
//
//    // getters
//    vector<T> getData() const { return data; }
//};



int main() {

    


    return 0;
}
