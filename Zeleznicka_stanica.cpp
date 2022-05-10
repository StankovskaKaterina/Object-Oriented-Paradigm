#include<iostream>
#include <cstring>
using namespace std;
struct Voz {
    char relacija[50];
    float km;
    int br_patnici;
};
struct ZeleznickaStanica {
    char grad[20];
    Voz niza[30];
    int br_vozovi;
};
void najkratkaRelacija(ZeleznickaStanica *zs, int n, char* grad) {
    int i,j,min=0,flag=0, min_indeks=0;
    for(i=0; i<n; i++) {
        if (strcmp(zs[i].grad,grad)==0) {
            flag=1;

            min=zs[i].niza[0].km;
            for (j=1; j<zs[i].br_vozovi; j++) {

                if (zs[i].niza[j].km<min) {
                    min = zs[i].niza[j].km;
                    min_indeks=j;
                }
                if (zs[i].niza[j].km==min){
                min = zs[i].niza[j].km;
                    min_indeks=j;
                }
            }

break;
        }

    }
    if(flag) {
        cout<<"Najkratka relacija: ";
        cout<<zs[i].niza[min_indeks].relacija;
        cout<<" ("<<min<<" km"<<")";


    }

}



int main() {

    int n,i,j;
    cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0; i<n; i++) {
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin>>zStanica[i].grad>>zStanica[i].br_vozovi;
        for(j=0; j<zStanica[i].br_vozovi; j++) {
            cin>>zStanica[i].niza[j].relacija>>zStanica[i].niza[j].km>>zStanica[i].niza[j].br_patnici;
        }
    }

    char grad[25];
    cin>>grad;

    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
