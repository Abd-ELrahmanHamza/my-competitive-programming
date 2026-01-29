/*
 * @lc app=leetcode id=2976 lang=java
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

    public record Child(int v, long c) {

    }

    public record Node(int v, long c) {

    }

    private long minPath(int source, int dest, long[][] minCosts, List<List<Child>> adjList) {
        if (minCosts[source][dest] != Long.MAX_VALUE) {
            return minCosts[source][dest];
        }
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> Long.compare(a.c, b.c));
        pq.add(new Node(source, 0));

        while (!pq.isEmpty()) {
            Node top = pq.poll();

            if (minCosts[source][top.v] < top.c) {
                continue;
            }

            for (Child child : adjList.get(top.v)) {
                if (top.c + child.c < minCosts[source][child.v]) {
                    minCosts[source][child.v] = top.c + child.c;
                    pq.add(new Node(child.v, minCosts[source][child.v]));
                }
            }
        }
        if (minCosts[source][dest] == Long.MAX_VALUE) {
            return minCosts[source][dest] = -1;
        }
        return minCosts[source][dest];
    }

    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        List<List<Child>> adjList = new ArrayList<>();
        long[][] minCosts = new long[26][26];
        for (int i = 0; i < 26; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                minCosts[i][j] = Long.MAX_VALUE;
                if (i == j) {
                    minCosts[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < original.length; i++) {
            adjList.get(original[i] - 'a').add(new Child(changed[i] - 'a', cost[i]));
        }
        long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            long c = minPath(source.charAt(i) - 'a', target.charAt(i) - 'a', minCosts, adjList);
            if (c == -1) {
                return -1;
            }

            ans += c;
        }
        return ans;
    }
}
// @lc code=end

