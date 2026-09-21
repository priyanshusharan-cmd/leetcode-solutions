class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;

        while (read < chars.size()) {
            char current = chars[read];
            int count = 0;

            // Count consecutive characters
            while (read < chars.size() && chars[read] == current) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if greater than 1
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};