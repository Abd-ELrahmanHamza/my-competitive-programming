
import java.util.HashSet;
import java.util.Set;

class Solution {

    public int maxDistinct(String s) {
        Set<Character> charSet = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            charSet.add(s.charAt(i));
        }
        return charSet.size();
    }
}
