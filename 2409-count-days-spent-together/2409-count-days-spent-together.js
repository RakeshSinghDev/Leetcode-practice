/**
 * @param {string} arriveAlice
 * @param {string} leaveAlice
 * @param {string} arriveBob
 * @param {string} leaveBob
 * @return {number}
 */
var countDaysTogether = function(arriveAlice, leaveAlice, arriveBob, leaveBob) {
    const daysInMonth = [31,28,31,30,31,30,31,31,30,31,30,31];

    function dayOfYear(date){
        const month = Number(date.substring(0,2));
        const day = Number(date.substring(3,5));

        let totalDays = day;
        
        for(let i=0; i<month-1; i++){
            totalDays +=daysInMonth[i];

        }
        return totalDays;
    } 
    const start = Math.max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
    const end =  Math.min(dayOfYear(leaveAlice),dayOfYear(leaveBob));

    return Math.max(0,end-start+1);
    
};