
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

    public record Node(int dest, int c) {

    }

    public int minCost(int n, int[][] edges) {
        List<List<Node>> adjList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(new Node(edge[1], edge[2]));
            adjList.get(edge[1]).add(new Node(edge[0], 2 * edge[2]));
        }
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.c - b.c);
        int[] dist = new int[n];
        for (int i = 0; i < n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[0] = 0;
        pq.add(new Node(0, 0));

        while (!pq.isEmpty()) {
            Node top = pq.poll();
            if (top.c > dist[top.dest]) {
                continue;
            }

            for (Node child : adjList.get(top.dest)) {
                if (top.c + child.c < dist[child.dest]) {
                    dist[child.dest] = top.c + child.c;
                    pq.add(new Node(child.dest, dist[child.dest]));
                }
            }
        }
        return dist[n - 1] == Integer.MAX_VALUE ? -1 : dist[n - 1];
    }
}
