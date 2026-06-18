/*
    1 hour minute angle = 360
    1 minute angle = 360/60 = 6 

    12 hour angle = 360
    1 hour angle = 360 / 12 = 30

    hour hand also keep moves with minute hand 
    
    so angle per minute in hour is : 30/60 = 0.5

    formula to calculate angle is :

        hourAngle = (hour % 12) * 30 + minutes * 0.5

        minuteAngle = minutes * 6


    diff = |hourAngle - minuteAngle|

    Since there are two possible angles between the hands on a circle, return the smaller one:

    min(diff, 360 - diff)



*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes;
        double hourAngle = 30.0 * (hour) + 0.5 * minutes;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};