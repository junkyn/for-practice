#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int count = 0;
    unordered_set<int> s;
    for(int i = 0; i<nums.size(); i++){
        s.insert(nums[i]);
    }
    return (s.size() > nums.size()/2) ? nums.size()/2 : s.size();
}