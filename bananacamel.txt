// Saw the following paragraph in a Wired article on an new find in prime numbers
// http://www.wired.com/2016/03/mathematicians-discovered-prime-conspiracy/

// "Soundararajan was drawn to study consecutive primes after hearing a lecture 
// at Stanford by the mathematician Tadashi Tokieda, of the University of Cambridge, 
// in which he mentioned a counterintuitive property of coin-tossing: If Alice 
// tosses a coin until she sees a head followed by a tail, and Bob tosses a coin 
// until he sees two heads in a row, then on average, Alice will require four 
// tosses while Bob will require six tosses (try this at home!), even though 
// head-tail and head-head have an equal chance of appearing after two coin tosses."

// It seemed counterintuitive, so I wrote a program to try it out.

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


int main()
{

    int OUTERLOOPCOUNT = 1000;  // Let's run 1000 simulations.

    int headtailtotal = 0;
    int headheadtotal = 0;
    srand(time(0));

    int HEAD = 0;  
    int TAIL = 1;

    int i = OUTERLOOPCOUNT;
    while (i > 0)
    {    
        int count = 1;
        bool lasthead = false;
        bool headtailfound = false;
        bool headheadfound = false;

        while (not headtailfound or not headheadfound)
        {
            
            int randomval = rand() % 2;  
            if (lasthead)
            {
                if (randomval == HEAD and not headheadfound)
                {
                    headheadfound = true;
                    headheadtotal += count;
                }
                if (randomval == TAIL)
                {
                    if (not headtailfound)
                    {
                        headtailfound = true;
                        headtailtotal += count;
                    }
                    lasthead = false;
                }
            }
            else
            {
                if (randomval == HEAD)
                {
                    lasthead = true;
                }
            }
 
            count++;
        }         

        i--;
    }

    cout << "HEADHEAD average = " << float(headheadtotal)/OUTERLOOPCOUNT << endl;
    cout << "HEADTAIL average = " << float(headtailtotal)/OUTERLOOPCOUNT << endl;

}


// I am definitely seeing the HEAD-HEAD average of 6 tosses, the HEAD-TAIL of 4 tosses.

// Why is this? 

// On examination, the reason is fairly subtle.
// Say I am trying to throw HT.
// If my first toss is an H, and my second toss is an H,
// a third toss of T will give me the HT sequence.
// But if I am trying to throw HH,
// If my first toss in an H, and my second toss is a T,
// there is no third toss that can give me HH.
// The best I can do is get HH on the 4th toss.

// A wrong HH toss interferes with your ability to throw
// an HH toss more than a wrong HT toss interferes
// with your ability to throw an HT toss.



