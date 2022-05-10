#include<iostream>
#include<cstring>
using namespace std;

class NBAPlayer {
protected:
    char *ime;
    char tim[40];
    double brPoeni;
    double brAsistencii;
    double brSkokovi;
public:
    NBAPlayer (){
    ime = new char[0];
        brPoeni=brAsistencii=brSkokovi=0;
        strcpy(tim,"");
    }
    // argument constructor
    NBAPlayer (const char* name, const char *mom_tim, double p, double a, double s) {
        ime = new char [strlen(name)+1];
        strcpy(ime,name);
        strcpy(tim,mom_tim);
        brPoeni=p;
        brAsistencii=a;
        brSkokovi=s;
    }
    //copy constructor
    NBAPlayer(const NBAPlayer &nba) {
        ime = new char [strlen(nba.ime)+1];
        strcpy(ime,nba.ime);
        strcpy(tim,nba.tim);
        brPoeni=nba.brPoeni;
        brAsistencii=nba.brAsistencii;
        brSkokovi=nba.brSkokovi;
    }
    //operator =
    NBAPlayer & operator = (const NBAPlayer &nba){
        if (this!=&nba){
        ime = new char [strlen(nba.ime)+1];
        strcpy(ime,nba.ime);
        strcpy(tim,nba.tim);
        brPoeni=nba.brPoeni;
        brAsistencii=nba.brAsistencii;
        brSkokovi=nba.brSkokovi;
        }
        return *this;
    }
    /*
    // destructor
    ~NBAPlayer (){
    delete [] ime;
    }*/

    //rating
    double rating (){
    return (brPoeni*0.45 + brAsistencii*0.3 + brSkokovi*0.25);
    }
    //print
    void print(){
    cout<<ime<<" - "<< tim<<endl;
    cout<<"Points: "<<brPoeni<<endl;
    cout<<"Assists: "<<brAsistencii<<endl;
    cout<<"Rebounds: "<<brSkokovi<<endl;
    cout<<"Rating: "<<rating()<<endl;
    }
};
class AllStarPlayer : public NBAPlayer{
private:
    double poeni;
    double asistencii;
    double skokovi;
    public:
    //default constructor
    AllStarPlayer(): NBAPlayer(){
    poeni=asistencii=skokovi=0;
    }


    AllStarPlayer(const char * ime, const char * tim, double p, double a, double r,
                  double allP, double allA, double allR) : NBAPlayer(ime,tim,p,a,r) {
    poeni=allP;
    asistencii=allA;
    skokovi=allR;
    }


    AllStarPlayer (NBAPlayer &np, double p, double a, double s):NBAPlayer(np){
    poeni=p;
    asistencii=a;
    skokovi=s;
    }
    //copy constructor
    AllStarPlayer(const AllStarPlayer &asp):NBAPlayer(asp){
    poeni=asp.poeni;
    asistencii=asp.asistencii;
    skokovi=asp.skokovi;
    }
    //operator =
    AllStarPlayer& operator =(const AllStarPlayer &asp){
        if (this!=&asp){
            delete [] ime;
           ime = new char [strlen(asp.ime)+1];
        strcpy(ime,asp.ime);
        strcpy(tim,asp.tim);
        brPoeni=asp.brPoeni;
        brAsistencii=asp.brAsistencii;
        brSkokovi=asp.brSkokovi;
        poeni=asp.poeni;
    asistencii=asp.asistencii;
    skokovi=asp.skokovi;
        }
        return *this;
    }
    /*
      //destructor
    ~AllStarPlayer(){
    delete [] ime;
    }
    */
    //AllStar rating
    double allStarRating(){
    return (poeni*0.3 + asistencii*0.4 +skokovi*0.3);
   }
    // prepokrivanje na rating
    double  rating()
    {
    return (NBAPlayer::rating()+ allStarRating())/2;
    }
    //print
    void print(){
    NBAPlayer::print();
    cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<rating()<<endl;
    }



};
int main() {

    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer * players = new NBAPlayer[5];
    AllStarPlayer * asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            players[i].print();
        }
    } else if (n == 2) {

        for (int i=0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarAssists);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    } else if (n == 3) {

        for (int i=0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints,allStarAssists,allStarAssists);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
