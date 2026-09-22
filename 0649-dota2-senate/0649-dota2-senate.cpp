class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;

        int n = senate.size();

        // Store the positions of R and D
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();

            radiant.pop();
            dire.pop();

            if (r < d) {
                // R acts first and bans D
                radiant.push(r + n);
            } else {
                // D acts first and bans R
                dire.push(d + n);
            }
        }

        if (!radiant.empty()) {
            return "Radiant";
        }

        return "Dire";
    }
};