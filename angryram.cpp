/* From http://fivethirtyeight.com/features/can-you-outrun-the-angry-ram-coming-right-for-oh-god/

You, a hard-driving sheep farmer, are tucked into the southeast corner of your square, 
fenced-in sheep paddock. There are two gates equidistant from you: one at the 
southwest corner and one at the northeast corner. An angry, recalcitrant ram 
enters the paddock from the southwest gate and charges directly at you at a 
constant speed. You run — obviously! — at a constant speed along the eastern 
fence toward the northeast gate in an attempt to escape. The ram keeps charging, 
always directly at you.

How much faster than you does the ram have to run so that he catches you 
just as you reach the gate?

*/



#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


void incrementramposition(float farmx, float farmy, float& ramx, float& ramy, float ramspeed, float timedelta)
{
    float xdist = -ramx;
    float ydist = farmy-ramy;
    float distance = sqrt(xdist*xdist+ydist*ydist);
    ramx = xdist*ramspeed*timedelta/distance;
    ramy = ydist*ramspeed*timedelta/distance;
    return;
}


float findcollisionpoint(float ramspeed, float timedelta) 
{
    float farmx =  0;
    float farmy =  0;
    float ramx  = -1;
    float ramy  =  0;
    
    farmy += timedelta;
    incrementramposition(farmx,farmy,ramx,ramy,ramspeed,timedelta);
    
    
    return ramy;

}


int main()
{



    cout << "ram caught farmer at " << findcollisionpoint(10,.000001) << endl;
}




