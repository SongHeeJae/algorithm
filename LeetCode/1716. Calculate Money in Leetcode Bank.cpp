/*
첫 주는 28의 비용이 들고, 그 이후에는 각 주마다 공차가 7인 등차수열이 됩니다.
이를 이용하여 첫 주부터 마지막 전 주까지 비용 합을 구해줍니다.
마지막 주의 첫 비용은, 주 수를 이용하여 구할 수 있습니다.
주 수와 마지막 주의 일수를 이용하여, 마지막 주의 첫 비용부터 끝 비용까지의 합을 구해줍니다.
이를 이용해 상수 시간에 비용의 총합을 구할 수 있습니다.
*/

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;

        int daysOfLastWeek = n % 7;
        int sumOfDaysOfLastWeek = (week + 1 + week + daysOfLastWeek) * daysOfLastWeek / 2;

        int sumOfDaysOfNotLastWeek = week * (56 + (week - 1) * 7) / 2;

        return sumOfDaysOfLastWeek + sumOfDaysOfNotLastWeek;
    }
};
