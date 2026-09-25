class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int maxLength = 0;

        int[] lastSeen = new int[128];

        for (int i = 0; i < 128; i++) {
            lastSeen[i] = -1;
        }

        for (int right = 0; right < s.length(); right++) {
            char current = s.charAt(right);

            if (lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }

            lastSeen[current] = right;

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}