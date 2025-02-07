#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Create an unordered_map to store the color of each ball (ball -> color)
        unordered_map<int, int> color_of_each_ball;

        // Vector to store the number of distinct colors after each query
        vector<int> no_of_distinct_colors_after_query;

        // Iterate over each query
        for(int current_index = 0; current_index < queries.size(); ++current_index) {
            // Extract the current ball and its color from the query
            int current_ball = queries[current_index][0];
            int current_color = queries[current_index][1];
            
            // Update the color of the current ball in the map
            color_of_each_ball[current_ball] = current_color;

            // Create an unordered set to store the distinct colors
            unordered_set<int> distinct_colors;

            // Iterate through the map and insert each ball's color into the set
            // Since sets do not allow duplicates, it ensures only distinct colors are kept
            for(auto& ball_color : color_of_each_ball) {
                distinct_colors.insert(ball_color.second);
            }

            // After processing the current query, record the size of the distinct colors set
            no_of_distinct_colors_after_query.push_back(distinct_colors.size());
        }

        // Return the vector containing the number of distinct colors after each query
        return no_of_distinct_colors_after_query;
    }
};