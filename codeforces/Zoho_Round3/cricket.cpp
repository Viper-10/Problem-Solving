#include<iostream>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<vector>
#define WICKET "W"
#define NO_OF_BATSMAN 3
#define NO_OF_BOWLERS 2
using namespace std;
class Batsman{
public : 
    int runs, balls;
    bool notOut;
    float contribution, strikeRate; 

    Batsman(){
        runs = 0, balls = 0, contribution = 0;
        notOut = true;  
    }

    Batsman(int runs, int balls){
        this->runs = runs; 
        this->balls = balls; 
        notOut = true; 
    }

    void calculateContribution(int totalScoreByTeam){ 
        this->contribution = round(((float)runs*100)/(float)totalScoreByTeam);
    }

    void calculateStrikeRate(){
        strikeRate = round(((float)runs*100)/(float)balls);
    }
};
class Bowlers{
public : 
    int balls; 
    int runs; 
    int wickets; 
    int overs; 
    int contribution; 

    Bowlers(){
        overs = 0; 
        runs = 0; 
        wickets = 0; 
        balls = 0; 
        contribution = 0; 
    }

    Bowlers(int overs, int runs, int wickets, int balls){   
        this->overs = overs; 
        this->runs = runs; 
        this->wickets = wickets; 
        this->balls = balls; 
    }

    void calculateContribution(int totalWicketsByTeam){
        this->contribution = round((float)((wickets * 100)/(float) totalWicketsByTeam));
    }

};
class Match{
public : 
    int firstInningOversEndIndex, team1Score, team2Score, team1Extras, team2Extras, team1WicketsLost, team2WicketsLost;
    string team1, team2; 
    vector<string> players1, players2; 
    unordered_set<string> setPlayers1, setPlayers2; 
    vector<vector<string>> overs; 
    unordered_map<string, Batsman> batsmanStats; 
    unordered_map<string, Bowlers> bowlerStats; 
    

    Match(){
        firstInningOversEndIndex = 4; 
        team1Score = 0; 
        team2Score = 0; 
        team1Extras = 0; 
        team2Extras = 0; 
        team1WicketsLost = 0; 
        team2WicketsLost = 0; 
    } 

    void setTeamNames(string team1, string team2){
        this->team1 = team1; 
        this->team2 = team2; 
    } 

    void setTeam(vector<string>& team, bool isTeam1){
        if(isTeam1){
            players1 = team; 
            for(string& player : team){
                setPlayers1.insert(player);
            }
        }else{
            players2 = team; 
            for(string& player : team){
                setPlayers2.insert(player); 
            }
        } 

        for(int i = 0;i < NO_OF_BATSMAN; ++i){
            Batsman b; 
            batsmanStats[team[i]] = b; 
        }

        for(int i = NO_OF_BATSMAN; i < NO_OF_BATSMAN+NO_OF_BOWLERS; ++i){
            Bowlers b;
            bowlerStats[team[i]] = b; 
        }
    }

    void print(){
        cout << "Team names : " << endl; 
        cout << team1 << " " << team2 << endl << endl; 

        cout << "Team 1 Players : " << endl; 
        for(string& s : players1){
            cout << s << " ";
        }
        cout << endl << endl; 
        cout << "Team 2 Players : " << endl; 

        for(string& s : players2){
            cout << s << " "; 
        }

        cout << endl << endl; 
        

        cout << "First Inning ends at over Index : " << firstInningOversEndIndex << endl;

        cout << endl; 
        
        cout << "Overs : " << endl; 
        for(vector<string>& over : overs){
            for(string& ball : over){
                cout << ball << " "; 
            }
            cout << endl;
        }

        cout << endl << endl; 
        cout << "Players stats" << endl; 


        cout << endl << endl << "BATSMAN" << endl << endl; 

        for(unordered_map<string, Batsman>::iterator it= batsmanStats.begin(); it != batsmanStats.end(); ++it){
            cout << it->first << (it->second.notOut ? "*" : "") << "\t" << it->second.runs <<  " runs" <<"\t" << it->second.balls << " balls " << "Contribution :" << it->second.contribution << "%" << "\tStrike Rate : " << it->second.strikeRate << "%" <<  endl;
        }   

        cout << endl << endl; 

        cout << "BOWLERS" << endl << endl; 

        for(unordered_map<string, Bowlers>::iterator it= bowlerStats.begin(); it != bowlerStats.end(); ++it){

            cout << it->first << "\t" << it->second.overs << "." << it->second.balls << " overs" << "\t" << it->second.runs
             << " runs" << "\t" << it->second.wickets << " wickets" << "\t" << "Contribution :" << it->second.contribution << "%" << endl;  
        }
        
        cout << endl << endl; 

        cout << "Team Scores : " << team1Score << "/" << team1WicketsLost << " " << team2Score << "/" << team2WicketsLost << endl;
        cout << "Total extras : " << team1Extras << " " << team2Extras;
    }

    void createStatistics(bool isTeam1){
        bool isFirstStriker = true, isFirstBowler = true; 
        bool firstWicket = true, inningsEnded = false;  

        string first = isTeam1 ? players1[0] : players2[0]; 
        string second = isTeam1 ? players1[1] : players2[1]; 
        
        string bowler1 = isTeam1 ? players2[3] : players1[3]; 
        string bowler2 = isTeam1 ? players2[4] : players1[4]; 

        int teamScore = 0, totalExtras = 0; 
        int i = isTeam1 ? 0 : firstInningOversEndIndex+1;   
        int n = isTeam1 ? firstInningOversEndIndex+1 : overs.size();  

        while (i < n){
            vector<string>& over = overs[i]; 

            for(string& score : over){ 
                string batsman = isFirstStriker ? first : second; 
                string bowler = isFirstBowler ? bowler1 : bowler2; 

                int runsScored = score[0]-'0';

                if(score == WICKET){
                    updateBowlerStats(bowler, 0, 1, 1); 
                    updateBatsmanStats(batsman, 0, false);

                    if(isTeam1){
                        team1WicketsLost++; 
                    }else team2WicketsLost++; 

                    if(!firstWicket){
                        inningsEnded = true; 
                        break; 
                    }

                    else{
                        if(isFirstStriker){
                            first = isTeam1 ? players1[2] : players2[2]; 
                        }else{
                            second = isTeam1 ? players1[2] : players2[2]; 
                        }
                        firstWicket = false; 
                    }
                }

                else if(extras(score)){
                    teamScore += runsScored; 
                    teamScore += wideOrNoBall(score);
                
                    totalExtras += wideOrNoBall(score); 

                    updateBatsmanStats(batsman, runsScored);
                    updateBowlerStats(bowler, wideOrNoBall(score)+runsScored, 0);

                    isFirstStriker = switchStrikerIfOddRuns(isFirstStriker, runsScored); 
                }

                else{
                    teamScore += runsScored; 

                    updateBatsmanStats(batsman, runsScored);
                    updateBowlerStats(bowler, runsScored, 1);

                    isFirstStriker = switchStrikerIfOddRuns(isFirstStriker, runsScored); 
                }

            }
            // at the over end strikers and bowlers are reversed
            isFirstBowler = !isFirstBowler; 
            isFirstStriker = !isFirstStriker; 

            if(inningsEnded){
                break; 
            }
            i++; 
        }

        // setting appropriate Team score; 
        if(isTeam1){
            team1Score = teamScore; 
            team1Extras = totalExtras; 
        }else{
            team2Score = teamScore; 
            team2Extras = totalExtras; 
        }
    }

    void calculateContributions(){
        calculateContributionsAndStrikeRate(true, team1Score); 
        calculateContributionsAndStrikeRate(false, team2Score); 
    }
private : 
    void calculateContributionsAndStrikeRate(bool isTeam1, int teamScore, int wickets = 2){  
        vector<string> players = isTeam1 ? players1 : players2; 
        int maxContribution = 0; 

        for(int i = 0;i < NO_OF_BATSMAN; ++i){
            string& player = players[i]; 
            Batsman& b = batsmanStats[player]; 
            b.calculateStrikeRate();
            b.calculateContribution(teamScore);
        }

        for(int i = NO_OF_BATSMAN; i < NO_OF_BATSMAN+NO_OF_BOWLERS; ++i){
            string& player = players[i]; 
            Bowlers& b = bowlerStats[player]; 
            b.calculateContribution(wickets); 
        }
    }

    bool switchStrikerIfOddRuns(bool flag, int runs){
        return runs%2 == 0 ? flag : !flag; 
    }
    void updateBatsmanStats(string& batsman, int runs, bool notOut = true){
        batsmanStats[batsman].balls += 1;
        batsmanStats[batsman].runs += runs; 
        batsmanStats[batsman].notOut = notOut; 
    }

    void updateBowlerStats(string& bowler, int runs, int balls,int wicket = 0){
        bowlerStats[bowler].runs += runs; 
        bowlerStats[bowler].balls += balls; 
        bowlerStats[bowler].wickets += wicket; 

        if(bowlerStats[bowler].balls == 6){
            bowlerStats[bowler].balls = 0; 
            bowlerStats[bowler].overs += 1; 
        }
    }

    bool extras(const string& score){
        return score.size() > 1; 
    }

    bool wideOrNoBall(const string& score){
        return score[1] == 'W' || score[1] == 'N';
    }
}; 
void takeOversInput(Match& m){
    int numberOfWicketsSoFar = 0; 

    vector<vector<string>> overs = {
        {"0", "1", "0Wd", "1", "6", "0", "1"}, 
        {"W", "0", "0", "2", "1", "1"}, 
        {"1", "2", "2", "4", "0", "1"}, 
        {"4", "4", "2", "0Nb", "6", "4", "W"}, 
        {"0", "0", "1", "4", "2", "0"}, 
        {"0", "1", "6", "W", "0", "0"}, 
        {"4", "4", "6", "0Wd", "1", "1", "1"}, 
        {"0Nb", "4", "2", "1", "0", "6"}
    }; 

    for(int i = 0;i < 4; ++i){
        vector<string>& over = overs[i];
        for(string& ball : over){
            if(ball == "W"){
                numberOfWicketsSoFar++; 
            }

            if(numberOfWicketsSoFar == 2){
                m.firstInningOversEndIndex = i; 
            }
        }
    }

    m.overs = overs; 
}
void takeInput(Match& m){

    // take team name and team players input
    string team1 = "Punjab"; 
    string team2 = "Chennai"; 

    vector<string> players1 = {"Smith", "Dhawan", "Agarwal", "Patel", "Singh"}; 

    vector<string> players2 = {"Dhoni", "Conway", "Rayudu", "Bravo", "Jadeja"}; 

    m.setTeamNames(team1, team2);
    m.setTeam(players1, true); 
    m.setTeam(players2, false); 

    takeOversInput(m); 
}
int main(){

    Match m; 
    takeInput(m); 
    
    m.createStatistics(true);
    m.createStatistics(false); 
    m.calculateContributions();
    m.print(); 

    cout << endl << endl; 
    if(m.team1Score > m.team2Score){
        cout << m.team1 << " won over " << m.team2 << endl;  
    }else {
        cout << m.team2 << " won over " << m.team1 <<  endl;
    }

    return 0; 
}