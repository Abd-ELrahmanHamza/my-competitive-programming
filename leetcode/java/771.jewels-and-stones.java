
class Solution {

    public int numJewelsInStones(String jewels, String stones) {
        int[] freq = new int[2 * 26];
        int ans = 0;
        for (int i = 0; i < stones.length(); i++) {
            if (Character.isUpperCase(stones.charAt(i))) {
                freq[stones.charAt(i) - 'A' + 26]++;
            } else {
                freq[stones.charAt(i) - 'a']++;
            }
        }
        for (int i = 0; i < jewels.length(); i++) {
            if (Character.isUpperCase(jewels.charAt(i))) {
                ans += freq[jewels.charAt(i) - 'A' + 26];
            } else {
                ans += freq[jewels.charAt(i) - 'a'];
            }
        }
        return ans;
    }
}
