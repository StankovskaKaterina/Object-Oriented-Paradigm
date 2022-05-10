#include<iostream>
//#include<string.h>
#include<cstring>
using namespace std;

class Zichara {
private:
    char *mesto;
    int cenaDen;
public:
    Zichara () {}
    Zichara (const char *m="", int cena=0) {
        mesto = new char [strlen(m)+1];
        strcpy(mesto,m);
        cenaDen=cena;
    }
    ~Zichara(){
    delete [] mesto;
    }

    Zichara(const Zichara &z) {
        mesto=new char [strlen(z.mesto)+1];
        strcpy(mesto,z.mesto);
        cenaDen=z.cenaDen;

    }
    char* getMesto() {
        return mesto;
    }
    Zichara& operator= (const Zichara &z){
        if (this!=&z){
        mesto=new char [strlen(z.mesto)+1];
        strcpy(mesto,z.mesto);
        cenaDen=z.cenaDen;
        }
        return *this;
    }

    int getDnevna(){
    return cenaDen;
    }

};

class PlaninarskiDom {
private:
    static char ime[15];
    int cena[2];
    char klasa;
    bool daliZichara;
    Zichara *zicaraMesto;
public:
    PlaninarskiDom() {
        static const char *ime=" ";
        int *cena=0;
        bool daliZichara=false;
        Zichara *zicaraMesto=0;
    }
    //konstruktor so argumenti
    PlaninarskiDom( const char *i, int *c, char k) {
        strcpy(ime,i);
        for(int i=0; i<2; i++) {
            cena[i]= c[i];
        }
        klasa=k;
    }
    //copy constructor
    PlaninarskiDom(const PlaninarskiDom &pd) {
        strncpy(ime,pd.ime,15);
        for(int i=0; i<2; i++) {
            cena[i]=pd.cena[i];
        }
        klasa=pd.klasa;
        daliZichara=pd.daliZichara;
        Zichara *zicaraMesto;
    }

    ~PlaninarskiDom(){}
    // operator =
    PlaninarskiDom& operator=(const PlaninarskiDom &pd){
        if (this!=&pd){
        strncpy(ime,pd.ime,15);
        for(int i=0; i<2; i++) {
            cena[i]=pd.cena[i];
        }
        klasa=pd.klasa;
        daliZichara=pd.daliZichara;
        Zichara *zicaraMesto;
        }
        return *this;
    }
    // setZichara
    void setZichara(Zichara r) {
        zicaraMesto=&r;
        daliZichara=true;
        klasa++;
    }
    //operator <<
    friend ostream &operator<<(ostream &out,const PlaninarskiDom &p)
    {
        if(p.daliZichara)out<<p.ime<<" klasa:"<<p.klasa<<" so Zichara"<<endl;
        else out<<p.ime<<" klasa:"<<p.klasa<<endl;
        return out;
    }
    //operator <=
    bool operator<=(char znak)
    {
        if(klasa>=znak) return true;
        return false;
    }
    void presmetajDnevenPrestoj(int den, int mesec, int &Cena){
    try
        {
            if(!(den>=1&&den<=31) || !(mesec>=1&&mesec <=12)) throw 1;
            if(mesec>=4&&mesec <=8)
            {
                if(daliZichara==true) Cena=cena[0]+zicaraMesto->getDnevna();
                else Cena=cena[0];
            }
            else
            {
                if(daliZichara==true) Cena=cena[1]+zicaraMesto->getDnevna();
                else Cena=cena[1];
            }
        }
        catch(int)
        {
            throw;
        }
    }

};

int main() {

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15],mestoZichara[30],klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin>>imePlaninarskiDom;
    for (int i=0; i<2; i++) cin>>ceni[i];
    cin>>klasa;
    cin>>daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin>>mestoZichara>>dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
        Zichara r(mestoZichara,dnevnakartaZichara);
        pom.setZichara(r);
        p=pom;
    } else {
        PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
        p=*pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den,mesec;
    cin>>den>>mesec;
    try {
        p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout<<"Informacii za PlaninarskiDomot:"<<endl;
        cout<<p;
        if (p<='D')
            cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
    } catch (int) {
        cout<<"Mesecot ili denot e greshno vnesen!";
    }
}
