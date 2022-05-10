#include<iostream>
#include<cstring>
using namespace std;

class Lekar{
protected:
    int faksimil;
    char ime[11];
    char prezime[11];
    float pocetnaPlata;
public:
    Lekar(int faks=0, char* name="", char *surname="", double plata=0){
    faksimil=faks;
    strcpy(ime, name);
    strcpy(prezime, surname);
    pocetnaPlata=plata;
    }
    void pecati() {
        cout<<faksimil<<": "<<ime<<" "<<prezime<<endl;
    }
    double plata(){
    return pocetnaPlata;
    }
};


class MaticenLekar : public Lekar {
private:
int brPacienti;
double * kotizacii;
Lekar lekari;
public:
    // default constructor
    MaticenLekar(){
    brPacienti=0;
    this->lekari=NULL;
    kotizacii= new double [0];
    }
    //constructor
    MaticenLekar(const Lekar lekari, int broj, double * kot){
    this->lekari=lekari;
    brPacienti=broj;
    kotizacii= new double [500];
    for(int i=0; i<broj;i++){
        kotizacii[i]=kot[i];
    }
    }
    //Prosek kotizacii
    double prosekKotizacii(){
    double suma=0.0;
        for(int i=0;i<brPacienti;i++){
        suma+=kotizacii[i];
        }
        return suma/brPacienti;
    }
    // pecati
    void pecati() {
        lekari.pecati();
        cout<<"Prosek na kotizacii: "<<prosekKotizacii()<<endl;
    }
    // plata()
    double plata(){
    return((prosekKotizacii()*0.3)+lekari.plata());
    }


};
int main() {
    int n;
    cin>>n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime [20];
    char prezime [20];
    double osnovnaPlata;

    Lekar * lekari = new Lekar [n];
    MaticenLekar * maticni = new MaticenLekar [n];

    for (int i=0; i<n; i++) {
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
    }

    for (int i=0; i<n; i++) {
        cin >> pacienti;
        for (int j=0; j<pacienti; j++) {
            cin >> kotizacii[j];
        }
        maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
        for (int i=0; i<n; i++) {
            lekari[i].pecati();
            cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
        }
    } else {
        cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
        for (int i=0; i<n; i++) {
            maticni[i].pecati();
            cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
        }
    }

    delete [] lekari;
    delete [] maticni;

    return 0;
}
