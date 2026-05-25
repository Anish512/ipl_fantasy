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
        bool out;
        bool hatTrick;
        int numRuns;
        int numBallsFaced;
        double strikeRate;
        int numRunsBowled;
        int numBallsBowled;
        double econ;
        int numWickets;
        int wides;
        int dots;
        int noBalls;
        int numWicketsField;
        int misfieldRuns;
    public:
        Player(string n, int nr, int nbf, int nrb, 
            int nbb, int nw, int w, int d, int nb, int nwf, int mf, bool o, bool h){
                name = n;
                numRuns = nr;
                numBallsFaced = nbf;
                strikeRate = calcStrikeRate();
                numRunsBowled = nrb;
                numBallsBowled = nbb;
                econ = calcEconomy();
                numWickets = nw;
                wides = w;
                dots = d;
                noBalls = nb;
                numWicketsField = nwf;
                misfieldRuns = mf;
                out = o;
                hatTrick = h;
        }
        void addRuns(int runs, int ballsFaced){
            numRuns += runs;
            numBallsFaced += ballsFaced;
        }
        void bowlWide(int runs){
            numRunsBowled += runs;
            wides += runs;
        }
        void bowlNoBall(int runs){
            numRunsBowled += runs;
            noBalls++;
        }
        void bowlDot(){
            dots++;
        }
        void addWicket(){
            numWickets++;
            numBallsBowled++;
        }
        void addFieldWicket(){
            numWicketsField++;
        }
        void getOut(){
            numBallsFaced++;
            out = true;
        }
        string getName(){
            return name;
        };
        double calcStrikeRate(){
            if(numBallsFaced == 0){
                strikeRate = 0;
            }else{
                strikeRate = (1.0 * numRuns / numBallsFaced) * 100;
            }
            return strikeRate;
        }
        double calcEconomy(){
            econ = (numBallsBowled == 0) ? 0 : (numRunsBowled / (numBallsBowled / 6.0));
            return econ;
        }      
};
class FantasyPlayer : public Player{
    using Player::Player;
    private:
        int batScore;
        int fieldScore;
        double bowlScore;
        double totalScore;
    public:
        FantasyPlayer(string n, int nr, int nbf, int nrb, int nbb, int nw, 
             int w, int d, int nb, int nwf, int mf, 
             bool o, bool h) : Player(n, nr, nbf, nrb, nbb, nw, w, d, nb, nwf, mf, o, h){}

        void calcScore(FantasyPlayer p){
            totalScore = calcBatScore(p.numRuns, p.out, p.strikeRate, p.numBallsFaced) + calcBowlScore(p.numBallsBowled, p.econ, p.numWickets, p.dots, p.wides, p.noBalls, p.hatTrick) + calcFieldScore(p.numWicketsField, p.misfieldRuns);
        }
        int calcBatScore(int runs, bool out, double sr, int numFaced){
            cout << runs << endl;
            cout << out << endl;
            cout << sr << endl;
            cout << numFaced << endl;
            cout << "a " << batScore << endl; 
            batScore = runs;
            cout << "a " << batScore << endl; 
            double h = runs;
            int i = 0;
            while(h > 50){
                h -= 50;
                i++;
                batScore += 25 * (int)i;
                cout << "a " << batScore << endl; 
            }
            h = runs;
            i = 0;
            while(h >= 75){
                h -= 50;
                i++;
                batScore += 10 * (int)i;
                cout << "a " << batScore << endl; 
            }

            if(numFaced > 6){
                h = sr;
                if(sr > 200){
                    batScore += 15;
                    while(h > 200){
                        h -= 50;
                        batScore += 15;
                        cout << "a " << batScore << endl; 
                    }
                }else if(sr > 175){
                    batScore += 15;
                }
                cout << "a " << batScore << endl; 
            }
            if(out){    
                if(runs == 0){
                    batScore -= 50;
                }else if(runs <= 10){
                    batScore -= 30;
                }else if(runs < 20){
                    batScore -= 10;
                }
            }
            return batScore;
        }
        double calcBowlScore(int numBowled, double e, int numWick, int d, int w, int nb, bool h){
            
            bowlScore = 10.0 * numBowled - (numBowled * (5 / 6.0)) * e;
            cout << bowlScore << " " << numBowled * (5 / 6.0) << endl;
            if(h){
                bowlScore += 50 * numWick;
            }else{
                bowlScore += 25 * numWick;
            }
            
            bowlScore += d;
            
            bowlScore -= 3 * w;
            bowlScore -= 10 * nb;
            return bowlScore;

        }
        int calcFieldScore(int numWick, int mfruns){
            cout << 25 * numWick << endl;
            cout <<  5 * mfruns << endl;
            fieldScore = (25 * numWick) - (5 * mfruns);
            cout << fieldScore << endl;
            return fieldScore;
        }
        void printFantasyScore(){
            cout << "Name: " << name << endl;
            cout << "Fantasy Points: " << batScore << "+" << bowlScore << "+" << fieldScore << "=" << totalScore << endl;
        }
    
};
class DataBase{
    public:
        vector<FantasyPlayer> team;
        DataBase(){
            
        }
        double calcTotalScore(){
            double e = 0;
            for(int i = 0; i < team.size(); i++){
                //e += team.at(i).calcScore(team.);
            }
            return 0;
        }

};

int main(){
    FantasyPlayer gill("Chris Gayle", 22, 18, 0, 0, 0, 
        0, 0, 0, 1, 3, true, false);
    gill.calcScore(gill);
    gill.printFantasyScore();
    return 0;
}
