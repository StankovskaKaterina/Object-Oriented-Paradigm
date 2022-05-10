#include<iostream>
#include<cstring>
using namespace std;
enum tip {
    pop, rap, rok
};
class Pesna {
private:
    char *ime;
    int min;
    tip kojtip;
public:

    Pesna (char *i , int m, tip kt) {
        ime=new char [strlen(i)+1];
        strcpy(ime,i);
        min=m;
        kojtip=kt;
    }
    Pesna () {
        ime = new char [0];
        min=0;
        kojtip= pop;
    }

    Pesna (const Pesna &p) {
        ime = new char [strlen (p.ime)+1];
        strcpy(ime,p.ime);
        min=p.min;
        kojtip=p.kojtip;
    }

    Pesna& operator=(const Pesna &p) {
        if (this != &p) {
            delete [] ime;
            ime= new char [strlen(p.ime)+1];
            strcpy(ime,p.ime);
            min=p.min;
            kojtip=p.kojtip;
        }
        return *this;
    }
    //"Happy"-5min

    void pecati () {
        cout<<"\""<<ime<<"\"-"<<min<<"min"<<endl;
    }

    int getMin() {
        return min;
    }

    tip getTip() {
        return kojtip;
    }
    ~Pesna() {
        delete [] ime;
    }
};

class CD {
private:
    Pesna pesna[10];
    int brCD;
    int maxMin;
public:

    CD (Pesna *pe=0, int br=0, int max=0) {
        for(int i=0; i<brCD; i++) {
            pesna[i]=pe[i];
        }
        brCD=br;
        maxMin=max;

    }

    CD (const CD &c) {
        for(int i=0; i<brCD; i++) {
            pesna[i]=c.pesna[i];
        }
        brCD=c.brCD;
        maxMin=c.maxMin;

    }


    CD (int br) {
        maxMin=br;
         brCD=0;
    }

    int getBroj() {
        return brCD;
    }
    Pesna getPesna(int br) {
        return pesna[br];
    }
    void dodadiPesna (Pesna p) {
        if (brCD<10) {
            if (maxMin>=p.getMin()) {
                pesna [brCD]=p;
                ++brCD;
                maxMin-=p.getMin();
            }
        }
    }

    void pecatiPesniPoTip(tip t) {
        for(int i=0; i<brCD; i++) {
            if (pesna[i].getTip()==t) {
                pesna[i].pecati();
            }
        }

    }
};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0; i<n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    } else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0; i<n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0; i<n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    } else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0; i<n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}
