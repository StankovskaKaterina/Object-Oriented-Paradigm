#include<iostream>
#include<cstring>
using namespace std;
enum zanr {
    akcija, komedija, drama
};

class Film {
private:
    char *ime;
    int mem;
    zanr zanrFilm;

public:

    Film (char *i="",int MB=0, zanr zf=akcija) {
        ime = new char [strlen(i)+1];
        strcpy(ime,i);
        mem=MB;
        zanrFilm=zf;
    }

    Film (const Film &f) {
        ime=new char [strlen(f.ime)+1];
        strcpy(ime,f.ime);
        mem=f.mem;
        zanrFilm=f.zanrFilm;
    }
    void pecati() {
        cout<<mem<<"MB-"<<"\""<<ime<<"\""<<endl;

    }

    zanr getZanr() {
        return zanrFilm;
    }
    int getMem() {
        return mem;
    }
    Film &operator=(const Film &m) {
        if (this != &m) {
            delete [] ime;
            ime= new char [strlen(m.ime)+1];
            strcpy(ime,m.ime);
            mem = m.mem;
            zanrFilm=m.zanrFilm;
        }
        return *this;
    }
    ~Film() {
        delete [] ime;
    }
};

class DVD {
private:
    Film niza[5];
    int broj;
    int memDVD;
public:
    DVD (Film *film=NULL, int br=0, int mem=0) {
        broj=br;
        memDVD=mem;
        for(int i=0; i<br; i++) {
            niza[i]=film[i];
        }

    }
    DVD (int kapacitet) {
        memDVD=kapacitet;
        broj=0;
    }
    DVD  (const DVD &d) {
        broj=d.broj;
        for(int i=0; i<broj; i++) {
            niza[i]=d.niza[i];
        }
        memDVD=d.memDVD;
    }


    void dodadiFilm (Film f) {
        if (broj<5) {
            if (memDVD>=f.getMem()) {
                niza[broj]=f;
                ++broj;
                memDVD-=f.getMem();

            }
        }

    }

    void pecatiFilmoviDrugZanr(zanr z) {
        for (int i=0; i<broj; i++) {
            if (z!=niza[i].getZanr()) {
                niza[i].pecati();
            }
        }

    }
    Film getFilm(int i) {
        return niza[i];
    }

    int getBroj() {
        return broj;
    }
    float procentNaMemorijaOdZanr(zanr z) {
        float sum=0.0;
        for(int i=0; i<broj; i++) {
            if (niza[i].getZanr()== z) {
                sum+=niza[i].getMem();
            }
        }

        return sum/broj * 10.00;

    }
};
int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 6) {
        cout<<"===== Testirawe na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
        DVD omileno(40);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";

    }

    return 0;
}
