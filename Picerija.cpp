#include <iostream>
#include <cstring>

using namespace std;
class Pica {
private:
    char ime [15];
    int cena;
    char* sostojki;
    int popust;
public:

    // argument constructor
    Pica (const char *imee=" ",int cenaa=0 , const char *soss=" ", int namaluvanje=0) {
        strcpy(ime,imee);
        cena=cenaa;
        sostojki = new char[strlen(soss)+1];
        strcpy(sostojki,soss);
        int popust=namaluvanje;
    }
//pecati
    void pecati() {
        cout<<ime<<" - "<<sostojki<<", "<<cena;
    }
    bool istiSe(Pica p) {
        return (strcmp(sostojki, p.sostojki)==0);
    }
    // copy constructor
    Pica(const Pica &p) {
        strcpy(ime,p.ime);
        cena=p.cena;
        sostojki= new char[strlen(p.sostojki)+1];
        strcpy(sostojki,p.sostojki);
        int popust=p.popust;
    }
    // operator =
    Pica& operator=(Pica &p) {
        if (this!=&p) {
            strcpy(ime,p.ime);
            cena=p.cena;
            delete [] sostojki;
            sostojki= new char[strlen(p.sostojki)+1];
            strcpy(sostojki,p.sostojki);
            int popust=p.popust;
        }
        return *this;
    }

    int getPopust() {
        return popust;
    }
    int getCena() {
        return cena;
    }
    ~Pica() {
        delete [] sostojki;
    }
};

class Picerija {
private:
    char ime[15];
    Pica *pici;
    int br;
public:
    //ime constructor
    Picerija(const char* ime="") {
        strncpy(this->ime,ime,14);
        this->ime[14]=0;
        pici = NULL;
        br=0;
    }
    // constructor
    Picerija(const char* ime, Pica* pici, int br){
    strncpy(this->ime,ime,14);
    this->ime[14]=0;
    this->br=br;
       this->pici = new Pica[br];
        for(int i=0; i<br;i++){
            this->pici[i] = pici [i];
        }

    }
    //copy constructor
    Picerija (const Picerija &p) {
        strcpy(ime,p.ime);
        br=p.br;
        pici= new Pica [br];
        for(int i=0; i<br; i++) {
            pici[i]=p.pici[i];
        }
    }
    // operator =
    Picerija& operator=(const Picerija &p) {
        if (this!=&p) {
            strcpy(ime,p.ime);
            br=p.br;
            delete [] pici;
            pici= new Pica [br];
            for(int i=0; i<br; i++) {
                pici[i]=p.pici[i];
            }
        }
        return *this;
    }
    //destructor
    ~Picerija() {
        delete [] pici;
    }

    const char *getIme() {
        return this->ime;
    }
    void setIme(const char* ime) {
        strcpy(this->ime,ime);
        this->ime[14]=0;
    }


    void piciNaPromocija() {
        for(int i=0; i<br; i++) {
            if (pici[i].getPopust()!=0) {
                pici[i].pecati();
               cout << " " << pici[i].getCena() - (pici[i].getCena()*(pici[i].getPopust() / 100)) << endl;
            }

        }
    }

    Picerija& operator+=(Pica &p) {
        bool imaIsta=false;
        for(int i=0; i<br; i++)
            if (pici[i].istiSe(p))
                imaIsta=true;
                if (!imaIsta) {
                    Pica* tmp = new Pica[br +1];
                    for(int i=0; i<br; i++)
                        tmp[i] = pici[i];
                        tmp[br++] = p;
                        delete [] pici;
                        pici = tmp;


                }
return *this;

        }



};

int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(ime, cena, sostojki, popust);
		p1+=p;
	}

	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2+=p;

	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();

	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();

	return 0;
}
