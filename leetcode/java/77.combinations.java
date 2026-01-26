
import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=77 lang=java
 *
 * [77] Combinations
 */
// @lc code=start
class Solution {

    List<List<Integer>> ans;

    void solve(int n, int k, int i, List<Integer> curList) {
        if (curList.size() == k) {
            ans.add(curList);
            return;
        }
        if (i > n) {
            return;
        }
        solve(n, k, i + 1, new ArrayList<>(curList));
        curList.add(i);
        solve(n, k, i + 1, new ArrayList<>(curList));
    }

    public List<List<Integer>> combine(int n, int k) {
        ans = new ArrayList();
        solve(n, k, 1, new ArrayList());
        return ans;
    }
}
// @lc code=end

