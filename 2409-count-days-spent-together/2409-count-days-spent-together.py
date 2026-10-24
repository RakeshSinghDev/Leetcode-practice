
class Solution:
    def countDaysTogether(self, arriveAlice, leaveAlice,
                          arriveBob, leaveBob):
        daysInMonth = [31,28,31,30,31,30,31,31,30,31,30,31]

        def dayOfYear(date):
            month = int(date[0:2])
            day = int(date[3:5])
            totalDays = day

            for i in range(month - 1):
                totalDays += daysInMonth[i]

            return totalDays

        start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob))
        end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob))

        return max(0, end - start + 1)
    
        