#include <iostream>
#include <cstring>
using namespace std;
class Transport
{
protected:
    char destinacija[30];
    int osnovnaCena;
    int rastojanie;
public:
    Transport(){}
    Transport(char destinacija[],int osnovnaCena,int rastojanie)
    {
        strcpy(this->destinacija,destinacija);
        this->osnovnaCena = osnovnaCena;
        this->rastojanie = rastojanie;
    }
    void setDestinacija(char destinacija[])
    {
        strcpy(this->destinacija,destinacija);
    }
    void setOsnovnaCena(int osnovnaCena)
    {
        this->osnovnaCena = osnovnaCena;
    }
    char* getDestinacija()
    {
        return destinacija;
    }
    int getRastojanie()
    {
        return rastojanie;
    }

    //virtual cenaTransport() = 0;
    virtual int cenaTransport()
    {
        return osnovnaCena;
    }
    bool operator < (Transport &t)
    {
        return this->rastojanie < t.rastojanie;
    }
    ~Transport(){}

};
class AvtomobilTransport : public Transport
{
private:
    bool sofer;
public:
    AvtomobilTransport(){}
    AvtomobilTransport(char destinacija[],int osnovnaCena,int rastojanie,bool sofer): Transport(destinacija,osnovnaCena,rastojanie)
    {
        this->sofer = sofer;
    }
    int cenaTransport()
    {
        int c = Transport::cenaTransport();
        if(sofer)
        {
            c = c + c*20/100;
        }
        return c;
    }
    ~AvtomobilTransport(){}
};
class KombeTransport : public Transport
{
private:
    int brPatnici;
public:
    KombeTransport(){}
    KombeTransport(char destinacija[],int osnovnaCena,int rastojanie,int brPatnici): Transport(destinacija,osnovnaCena,rastojanie)
    {
        this->brPatnici = brPatnici;
    }
    int cenaTransport()
    {
        int c = Transport::cenaTransport();
        c = c - (200 * brPatnici);
        return c;
    }
    ~KombeTransport(){}
};
void pecatiPoloshiPonudi(Transport **ponudi,int n,AvtomobilTransport &T)
{

    int br=0;
    for(int i=0;i<n;i++)
    {

        if(ponudi[i]->cenaTransport()>T.cenaTransport())
            br++;
    }
    int j=0;
    Transport **temp = new Transport *[br];
    for(int i=0;i<n;i++)

    {
        if(ponudi[i]->cenaTransport()>T.cenaTransport())
    {
        temp[j] = ponudi[i];
        j++;
    }


    }
    Transport *pom;
    for(int i=0;i<br;i++)
    {
        for(int j=0;j<br-1-i;j++)
        {
            if(temp[j]->cenaTransport()>temp[j+1]->cenaTransport())
            {
                pom = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = pom;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]->getDestinacija()<<" "<<temp[i]->getRastojanie()<<" "<<temp[i]->cenaTransport()<<endl;
    }
}
int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
