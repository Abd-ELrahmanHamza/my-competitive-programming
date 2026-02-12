
import java.util.HashMap;
import java.util.Map;

class Solution {

    public int longestBalanced(String s) {
        int ans = 0, n = s.length();

        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            Map<Integer, Integer> valueFreq = new HashMap<>();

            for (int j = i; j < n; j++) {
                int c = s.charAt(j) - 'a';
                freq[c]++;
                valueFreq.put(freq[c], valueFreq.getOrDefault(freq[c], 0) + 1);
                if (valueFreq.getOrDefault(freq[c] - 1, 0) == 1) {
                    valueFreq.remove(freq[c] - 1);
                } else if (valueFreq.getOrDefault(freq[c] - 1, 0) > 1) {
                    valueFreq.put(freq[c] - 1, valueFreq.get(freq[c] - 1) - 1);
                }
                if (valueFreq.size() == 1) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
            int first = s.charAt(i) - 'a';
            freq[first]--;
        }
        return ans;
    }
}
