#include<iostream>
#include<cstring>
using namespace std;
class Ucesnik {
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    //constructor
    Ucesnik(const char *ii="",bool p=0,int god=0) {
        ime = new char [strlen(ii)+1];
        strcpy(ime,ii);
        pol=p;
        vozrast=god;
    }
    //copy constructor
    Ucesnik(const Ucesnik &u){
    ime = new char[strlen(u.ime)+1];
    strcpy(ime,u.ime);
    pol= u.pol;
    vozrast=u.vozrast;
    }
    //operator =
    Ucesnik& operator=(const Ucesnik &u){
        if (&u!= this){
        ime = new char[strlen(u.ime)+1];
    strcpy(ime,u.ime);
    pol= u.pol;
    vozrast=u.vozrast;
        }
        return *this;
    }
    // destructor
    ~Ucesnik(){
    delete [] ime;
    }
    // operator >
    bool operator> (Ucesnik &u){
    return this->vozrast>u.vozrast;
    }

    // operator <<
    friend ostream& operator<<(ostream &out, const Ucesnik &u){
      out<<u.ime<<endl;
        if (u.pol==1){
              out<<"maski"<<endl;
                    }
        else {
          out <<"zhenski"<<endl;
        }
          out<<u.vozrast<<endl;
        return out;
    }
    int getVozrast(){
    return vozrast;
    }
};
class Maraton{
private:
    char lokacija[100];
    Ucesnik *niza;
    int br;
    public:
    // lokacija constructor
    Maraton(char *lok){
        strcpy(lokacija,lok);
        br=0;
        niza = new Ucesnik [0];
    }
    //destructor
    ~Maraton(){
    delete [] niza;
    }
    // operator+=
    Maraton& operator +=(const Ucesnik &u){
    Ucesnik *tmp= new Ucesnik [this->br];
        for(int i=0;i<this->br;i++){
        tmp[i]= this->niza[i];
        }
        delete [] niza;
        niza = new Ucesnik [br+1];
        for(int i=0;i<this->br;i++){
        this->niza[i]=tmp[i];
        }
        this->niza[br] = u;
        delete [] tmp;
        br++;
        return *this;
    }
    //prosecno vozrast
    float prosecnoVozrast(){
    float suma=0;
        for(int i=0;i<br;i++){
        suma+=niza[i].getVozrast() ;
        }
        return (float) suma/br;
    }
    // pecati pomladi

    void pecatiPomladi(Ucesnik &u){
        for(int i=0;i<br;i++){
            if (niza[i].getVozrast()<u.getVozrast()){
                cout<<niza[i];
            }
        }
    }



};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime,maski,vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
