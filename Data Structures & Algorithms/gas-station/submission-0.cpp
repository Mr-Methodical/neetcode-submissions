class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if there ends up being enough fuel then we are actually good and we just need to find where it starts
        int gas_delta = 0;
        int start_index = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            gas_delta += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (gas_delta < 0) {
                gas_delta = 0; // starting over
                start_index = i + 1;
            }
        }
        // what determines it is basically is there enough gas to get across
        return (total < 0) ? -1 : start_index;
    }
};
