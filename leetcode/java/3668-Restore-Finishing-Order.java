
import java.util.Arrays;

class Solution {

    public int[] recoverOrder(int[] order, int[] friends) {
        int[] result = new int[friends.length];
        Arrays.sort(friends);
        int i = 0;
        for (int id : order) {
            if (Arrays.binarySearch(friends, id) >= 0) {
                result[i++] = id;
            }
        }
        return result;
    }
}
