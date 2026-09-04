#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <forward_list>
#include <vector>
using namespace std;
class Player{
    public:
        string name;
        int points;
        int assists;
        int drebounds;
        int orebounds;
        int steals;
        int blocks;
        int freeThrowsMissed;
        int turnovers;
        int fouls;
        int plusminus;
        Player(string n, int p, int a, int dr, int ore, int s, int b, int ftmi, int t, int f, int pm){
            name = n;
            points = p;
            assists = a;
            drebounds = dr;
            orebounds = ore;
            steals = s;
            blocks = b;
            freeThrowsMissed = ftmi;
            turnovers = t;
            fouls = f;
            plusminus = pm;
        }
};
class FantasyPlayer : public Player{
    public:

}


int main(){
    return 0;
}