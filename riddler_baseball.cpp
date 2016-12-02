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

using namespace std;

class Baseball_League {
    int numberteams;            // number of teams in the league
    int intradivision;   // number of games each team plays inside the division
    int outsidedivision; // number of games each team plays outside the division
    vector<int> winsperteam;
     
  public:
      

};


int main()
{
   return 0;
}

