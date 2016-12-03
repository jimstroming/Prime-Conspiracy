/* ========================================================================== */
/*                                                                            */
/*   Filename.cpp                                                             */
/*   (c) 2012 Author                                                          */
/*  
from http://fivethirtyeight.com/features/can-you-solve-the-puzzle-of-the-baseball-division-champs/

Assume you have a sport (lets call it baseball) in which each team plays 162 games in 
a season. Assume you have a division of five teams (call it the AL East) where each 
team is of exact equal ability. Specifically, each team has a 50 percent chance of 
winning each game. What is the expected value of the number of wins for the team that
finishes in first place?

Need to make an assumption about interdivision vs intradivision games.
Lets start with the way the schedule is done currently.
19 games against each of your 4 division opponents.
86 games outside your division.

/* ========================================================================== */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <tuple>
#include <algorithm>


class Baseball_Division {
    int numberteams;            // number of teams in the division
    int intradivisionperteam;   // number of games each team plays against each team in their division
    int outsidedivision; // number of games each team plays outside the division
    float get_random();
  public:
    Baseball_Division(int, int, int);
    std::vector<int> playseason(float);
    void playmultipleseasons(int, float, float&, std::vector<int>&);
    
};

Baseball_Division::Baseball_Division(int a, int b, int c) {
    numberteams = a;
    intradivisionperteam = b;
    outsidedivision = c;
}

float Baseball_Division::get_random()
{
    static std::random_device rd;
    static std::default_random_engine e (rd());
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(e);
}

std::vector<int> Baseball_Division::playseason(float winningpercentage){
    std::vector<int> winsperteam;  // wins each team wins per season    

    // construct the winsperteam vector and initialize to zero
    for(int i=0; i < numberteams; i++)
        winsperteam.push_back(0);    
        
    // play the interdivision games
    for (int teamnumber = 0; teamnumber < numberteams; teamnumber++)
    {
        for (int x = 0; x < outsidedivision; x++)
        {
            if (get_random() > winningpercentage)
                winsperteam[teamnumber] += 1;    
        }
    }
    // play the intradivision games    

    for (int teamnumber = 0; teamnumber < numberteams-1; teamnumber++)
    {
        for (int opponent = teamnumber+1; opponent < numberteams; opponent++)
        {
            for (int x = 0; x < intradivisionperteam; x++)
            {
                if (get_random() > winningpercentage)
                    winsperteam[teamnumber] += 1;
                else
                    winsperteam[opponent] += 1;
            }
        }
    }    
    
    return(winsperteam);

}

void Baseball_Division::playmultipleseasons(int numberseasons, float winningpercentage, float &averagenumberofwinsperwinner, std::vector<int> &pennantsperteam){

    for(int i=0; i < numberteams; i++)
        pennantsperteam.push_back(0);    
    
    int totalgameswonbywinner = 0; 
        
    for(int x=0; x < numberseasons; x++)
    {   
        std::vector<int> winsperteam = playseason(winningpercentage);
        int winningnumbergames = *max_element(winsperteam.begin(),winsperteam.end());
        totalgameswonbywinner += winningnumbergames;
        for (int x=0; x<numberteams; x++)
        {
            if(winsperteam[x] == winningnumbergames)
                pennantsperteam[x] += 1;  // in the event of a tie, give each team the pennant   
        }    
    }            
    averagenumberofwinsperwinner = float(totalgameswonbywinner)/numberseasons;
        
    // return std::make_tuple(averagenumberofwinsperwinner, pennantsperteam);
}





int main()
{

   float averagenumberofwinsperwinner;    
   int numberofseasons = 1000;
   std::vector<int> pennantsperteam;  // # pennants each team won
   Baseball_Division alw(5,19,86);
   
   alw.playmultipleseasons(numberofseasons, 0.5, averagenumberofwinsperwinner, pennantsperteam);


   std::cout << "Simulated " << numberofseasons << " seasons. The best average pennant winner won " << averagenumberofwinsperwinner << " games." << std::endl;
   
   return 0;
}

/*
Simulated 1000 seasons. The best average pennant winner won 88.793 games.
root@DESKTOP-PBTFIO5:/mnt/c/Users/Jim/Desktop/pythonprojects/github2/Prime-Conspiracy# ./a.out
Simulated 1000 seasons. The best average pennant winner won 88.942 games.
root@DESKTOP-PBTFIO5:/mnt/c/Users/Jim/Desktop/pythonprojects/github2/Prime-Conspiracy# ./a.out
Simulated 1000 seasons. The best average pennant winner won 88.617 games.
root@DESKTOP-PBTFIO5:/mnt/c/Users/Jim/Desktop/pythonprojects/github2/Prime-Conspiracy# ./a.out
Simulated 1000 seasons. The best average pennant winner won 88.864 games.
root@DESKTOP-PBTFIO5:/mnt/c/Users/Jim/Desktop/pythonprojects/github2/Prime-Conspiracy# ./a.out
Simulated 1000 seasons. The best average pennant winner won 88.959 games. 

So, the best average pennant winner won approximately 88.8 games. */