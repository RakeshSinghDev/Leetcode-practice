class Solution {
public:
int dayOfYear(string date){
    int daysInMonth[]={
        31,28,31,30,31,30,31,31,30,31,30,31
    };

    int month = stoi(date.substr(0,2));
    int day = stoi(date.substr(3,2));

    int totalDays = day;

    for(int i=0; i<month-1; i++){
        totalDays +=daysInMonth[i];
    }
    return totalDays;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return max(0,end-start+1);

        
    }
};