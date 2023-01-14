//You are given an integer n, which indicates that there are n courses labeled
//from 1 to n. You are also given an array relations where relations[i] = [
//prevCoursei, nextCoursei], representing a prerequisite relationship between course
//prevCoursei and course nextCoursei: course prevCoursei has to be taken before course
//nextCoursei. Also, you are given the integer k.
//
// In one semester, you can take at most k courses as long as you have taken
//all the prerequisites in the previous semesters for the courses you are taking.
//
// Return the minimum number of semesters needed to take all courses. The
//testcases will be generated such that it is possible to take every course.
//
//
// Example 1:
//
//
//Input: n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
//Output: 3
//Explanation: The figure above represents the given graph.
//In the first semester, you can take courses 2 and 3.
//In the second semester, you can take course 1.
//In the third semester, you can take course 4.
//
//
// Example 2:
//
//
//Input: n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
//Output: 4
//Explanation: The figure above represents the given graph.
//In the first semester, you can only take courses 2 and 3 since you cannot
//take more than two per semester.
//In the second semester, you can take course 4.
//In the third semester, you can take course 1.
//In the fourth semester, you can take course 5.
//
//
//
// Constraints:
//
//
// 1 <= n <= 15
// 1 <= k <= n
// 0 <= relations.length <= n * (n-1) / 2
// relations[i].length == 2
// 1 <= prevCoursei, nextCoursei <= n
// prevCoursei != nextCoursei
// All the pairs [prevCoursei, nextCoursei] are unique.
// The given graph is a directed acyclic graph.
//
//
// Related Topics Dynamic Programming Bit Manipulation Graph Bitmask \U0001f44d 759 \U0001f44e 6
//1


//leetcode submit region begin(Prohibit modification and deletion)
#include "bits/stdc++.h"
using namespace std;
class Solution {
    vector<vector<int>>adj;
    int n;
    int k;
    vector<int> dp;

    int solve(int mask)
    {
        if(mask ==((1<<n)-1)){
            return 0;
        }
        if(dp[mask]!=-1)
            return dp[mask];
        vector<int> indeg(n,0);
        for(int i = 0; i <n;i++){
            if(mask &(1<<i)) {
                // course i taken
                continue;
            }
            //course i not taken.
            for(auto v:adj[i]){
                // who are dependent on
                // this course i?
                indeg[v]++;
            }
        }
        // We have all the info about the courses
        // that we can take now
        int coursesBitmap = 0;
        for(int i = 0; i < n; i++){
            if(indeg[i]==0 && !(mask&(1<<i)))
            {
                // indeg 0 and also not take yet
                coursesBitmap =  coursesBitmap | (1<<i);
            }
        }
        // now temp contains all the courses
        // that we can take next.
        // But we can only take k of them.
        // How many courses do we have here?

        int numCourses = __builtin_popcount(coursesBitmap);
        int ans = n+1;
        if(numCourses > k){
            // select k courses
            int course_bitmap_copy= coursesBitmap;
            for(;course_bitmap_copy>0;course_bitmap_copy = (course_bitmap_copy -1)&coursesBitmap){
                // Initially course_bitmap_copy contains all the courses we didn't take(1's).
                // Now initially we have the bitmask with highest possible value which
                // has all the non-taken courses set to 1. We should decrease it further and check
                // subset of courses with number of 1's = k
                int cnt  = __builtin_popcount(course_bitmap_copy);
                if(cnt !=k)
                    continue;
                ans = min(ans,1+solve(mask|course_bitmap_copy));
                // change the mask since we have taken those courses
            }
        }
        else {
            ans = min(ans, 1 + solve(mask | coursesBitmap));
        }
        dp[mask]=ans;
        return ans;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        this->n = n;
        this->k = k;
        this->dp.assign(1<<n,-1);
        this->adj.clear();
        this->adj.resize(n);
        for(int i = 0; i < relations.size();i++){
            int x,y;
            x = relations[i][0];
            y= relations[i][1];
            x--;
            y--;
            adj[x].push_back(y);
        }
        return solve(0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
