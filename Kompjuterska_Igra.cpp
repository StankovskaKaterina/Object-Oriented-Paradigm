#include<iostream>
using namespace std;
struct Igrac {
    char ime[15];
    int nivo;
    int poeni;
};
struct KompjuterskaIgra {
    char ime[20];
    Igrac niza[30];
    int br_igraci;
};

void najdobarIgrac(KompjuterskaIgra *lista, int n) {
    int max=0,i,maxp=0,j,najdobar=0;// max e indeks na najpopularnata igra
    for(i=1; i<n; i++) {
        if (lista[i].br_igraci>lista[max].br_igraci) {
            max=i;
        }
    }
    KompjuterskaIgra najpopularna=lista[max];
    for(i=1; i<najpopularna.br_igraci; i++) {
        if (najpopularna.niza[i].poeni>najpopularna.niza[maxp].poeni) {
            najdobar=i;
            maxp++;
        }
        if (najpopularna.niza[i].poeni==najpopularna.niza[maxp].poeni){
            if(najpopularna.niza[i].nivo>najpopularna.niza[maxp].nivo){
            najdobar=i;
            }
            else if(najpopularna.niza[i].nivo<najpopularna.niza[maxp].nivo){
            najdobar=maxp;
            }
        }

    }
    cout<<"Najdobar igrac e igracot so korisnicko ime ";
    cout<<najpopularna.niza[najdobar].ime;
    cout<<" koj ja igra igrata ";
    cout<<najpopularna.ime;
}

int main() {
    int n,m;
    char ime[20];
    cin>>n;
    KompjuterskaIgra igri[100];
    for (int i=0; i<n; i++) {
        KompjuterskaIgra nova;
        cin>>nova.ime>>nova.br_igraci;
        Igrac pole[30];
        for (int j=0; j<nova.br_igraci; j++) {
            Igrac nov;
            cin>>nov.ime>>nov.nivo>>nov.poeni;
            nova.niza[j]=nov;
        }
        igri[i]=nova;
    }

    najdobarIgrac(igri,n);
    return 0;
}
