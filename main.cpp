class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int max = 0;
        multimap<int, int> tempMap;
        
        for (int i = 0; i < boxTypes.size(); ++i) {
            vector<int> &tempBoxType = boxTypes[i];
            
            tempMap.insert(std::pair<int, int>(tempBoxType[1], tempBoxType[0]));
        }
        
        multimap<int, int>::reverse_iterator iter = tempMap.rbegin();
        multimap<int, int>::reverse_iterator endIter = tempMap.rend();
        
        for (; iter != endIter; ++iter) {
            if (iter->second <= truckSize) {
                max += iter->first * iter->second;
                truckSize -= iter->second;
            }
            else {
                max += truckSize * iter->first;
                break;
            }
        }
        
        return max;
    }
};
