#include<iostream>
#include<cstring>
using namespace std;
class ZicanInstrument {
protected:
    char ime[20];
    int brZici;
    int osnovnaCena;
public:
    ZicanInstrument (const char *name="", int zici=0, int OsnovnaCena=0){
    strcpy(ime,name);
    brZici=zici;
    osnovnaCena=OsnovnaCena;
    }
    virtual float cena()=0;

    //operator ==
     bool operator == ( ZicanInstrument &z1){
    if(z1.brZici == brZici)
        return true;
    else return false;
    }

    friend ostream &operator <<(ostream &out, const ZicanInstrument &z1){
    return out <<"Pecatenje nesto"<<endl;

    }
    virtual ~ZicanInstrument(){
    }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **i, int n){
    for(int j=0; j<n;i++){
        if (zi==*(i[j])){
        cout<<i[j]->cena()<<endl;
        }
    }

}
class Mandolina: public ZicanInstrument {
private:
    char forma[20];
    public:
    Mandolina (const char *name="", int zici=0, int OsnovnaCena=0, const char *f="")
        : ZicanInstrument (name,zici,OsnovnaCena){
        strcpy(forma,f);
        }
    float cena(){
        if (strcmp(forma,"Neapolitan")==0){
            return (osnovnaCena+(0.15* osnovnaCena));
        }
        else
            return osnovnaCena;
    }
    ~Mandolina(){}
};
class Violina : public ZicanInstrument{
private:
    float golemina;
    public:
    Violina (const char *name="", int zici=0, int OsnovnaCena=0, float g=0.0)
        : ZicanInstrument (name,zici,OsnovnaCena){
        golemina=g;
        }
    float cena(){
        if (golemina==0.25){
            return (osnovnaCena+ (0.1*osnovnaCena));
        }
        else if (golemina ==1.0){
        return ((0.2*osnovnaCena)+osnovnaCena);
        }
        else
            return osnovnaCena;
    }
    ~Violina (){}
};
int main() {
	char ime[20];
	int brojZici;
	float cena;
	char forma[20];
	cin >> ime >> brojZici >> cena >> forma;
	Mandolina m(ime, brojZici, cena, forma);
	int n;
	cin >> n;
	ZicanInstrument **zi = new ZicanInstrument*[2 * n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina;
		cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}
	pecatiInstrumenti(m, zi, 2 * n);
	for(int i = 0; i < 2 * n; ++i) {
		delete zi[i];
	}
	delete [] zi;
	return 0;
}
