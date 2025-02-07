#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Vector to store the number of distinct colors after each query
        vector<int> no_of_distinct_colors_after_query;
        
        // unordered_map to store the color of each ball (ball -> color)
        // This simulates defaultdict(int) from Python
        unordered_map<int, int> color_of_each_ball;
        
        // unordered_map to store the count of each color (color -> count)
        unordered_map<int, int> color_count;
        
        // Variable to keep track of the number of distinct colors in use
        int distinct_color_count = 0;
        
        // Iterate over each query
        for (auto& query : queries) {
            int current_ball = query[0];   // Get the current ball (represented by an integer)
            int current_color = query[1];  // Get the new color for the current ball

            // Get the previous color of the current ball, default to 0 if the ball has no color
            int previous_color = color_of_each_ball.count(current_ball) > 0 ? color_of_each_ball[current_ball] : 0;
            
            // If the previous color was not 0, we need to update the color counts
            if (previous_color != 0) {
                // Decrease the count of the previous color since it's no longer associated with the current ball
                color_count[previous_color]--;
                
                // If the count of the previous color reaches 0, we decrease the distinct color count
                if (color_count[previous_color] == 0) {
                    distinct_color_count--;
                }
            }

            // If the current color hasn't been used before (its count is 0), increase the distinct color count
            if (color_count[current_color] == 0) {
                distinct_color_count++;
            }

            // Update the color of the current ball in the map
            color_of_each_ball[current_ball] = current_color;
            
            // Increase the count for the current color since it's now associated with a ball
            color_count[current_color]++;

            // Append the current number of distinct colors to the result vector
            no_of_distinct_colors_after_query.push_back(distinct_color_count);
        }

        // Return the final result vector containing the distinct color count after each query
        return no_of_distinct_colors_after_query;
    }
};