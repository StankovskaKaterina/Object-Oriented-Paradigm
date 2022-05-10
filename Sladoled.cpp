#include <iostream>
#include <cstring>
using namespace std;

class IceCream {
private:
    char* ime;
    char sostav[100];
    float cena;
    int popust;
public:

    //constructor
    IceCream(const char* name="", const char* s="", float c=0) {
        ime= new char[strlen(name)+1];
        strcpy(ime,name);
        strcpy(sostav,s);
        cena=c;
        popust=0;
    }
    // copy constructor
    IceCream(const IceCream &ice) {
        ime = new char[strlen(ice.ime)+1];
        strcpy(ime,ice.ime);
        strcpy(sostav,ice.sostav);
        cena=ice.cena;
        popust=ice.popust;
    }
    //operator =
    IceCream& operator =(const IceCream &ice) {
        if (this != &ice) {
            delete [] ime;
            ime = new char[strlen(ice.ime)+1];
            strcpy(ime, ice.ime);
            strcpy(sostav, ice.sostav);
            cena=ice.cena;
            popust=ice.popust;
        }
        return *this;
    }

    //set popust
    void setDiscount(int p) {
        if (p>0&&p<100) {
            popust=p;
        }

    }
    // operator <<
    friend ostream& operator <<(ostream& out, const IceCream &ice) {
        out << ice.ime<<": ";
        out << ice.sostav<<" ";
        out << ice.cena<<" ";
        if(ice.popust>0) {
            out<<"("<<ice.cena * (100 - ice.popust) / 100 <<")";

        }
        return out;
    }
    //operator ++
    IceCream& operator++ () {
        popust+=5;
        return *this;
    }
    // operator +
    IceCream operator+(const char * nov) {
        char * newName= new char[strlen (ime)+ strlen (nov)+4];
        strcat(newName, ime);
        strcat(newName," + ");
        strcat(newName, nov);
        IceCream res (newName, sostav, cena+10);
        res.setDiscount(popust);
        return res;
    }
    //set ime
    void setName(const char* n) {
        delete [] ime;
        ime = new char (strlen(n)+1);
        strcpy(ime,n);
    }


};

class IceCreamShop {
private:
    char ime[50];
    IceCream* sladoledi;
    int broj;
public:
    //constructor
    IceCreamShop(const char* IME="") {
        strcpy(ime,IME);
        sladoledi = NULL ;
        broj=0;
    }


    //operator +=
    IceCreamShop& operator+= (IceCream &ice) {
        IceCream *tmp = sladoledi;
        sladoledi= new IceCream[broj+1];
        for(int i=0; i<broj; i++) {
            sladoledi[i]= tmp[i];
        }
        sladoledi[broj]=ice;
        ++broj;
        delete [] tmp;
        return *this;
    }
// operator <<
    friend ostream& operator<<(ostream &out, const IceCreamShop &ics)  {
        cout<<ics.ime<<endl;
        for(int i=0; i<ics.broj; ++i) {
            out<<ics.sladoledi[i]<<endl;
        }
        return out;
    }
    //copy constructor
    IceCreamShop(const IceCreamShop &ics) {
        strcpy(ime,ics.ime);
        broj=ics.broj;
        sladoledi= new IceCream[broj];
        for(int i=0; i<broj; i++) {
            sladoledi[i]= ics.sladoledi[i];
        }

    }


};


int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics+=x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}
