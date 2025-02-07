# 3160. Find the Number of Distinct Colors Among the Balls (All Approaches)
- ## Approach 1:- Using Hashmaps and Array/Set (Memory Limit Exceed)
    - ### Intuition:
        The problem is asking for the number of distinct colors after each query. Each query updates the color of a specific ball. After processing each query, we need to determine how many distinct colors are present among all the balls.
        - We maintain a record of each ball's color.
        - For each query, we update the color of the specified ball.
        - After each update, we calculate how many distinct colors exist by converting the recorded ball colors into a set (since sets automatically handle duplicates).
        - We keep track of the number of distinct colors after each query and return the results.

    - ### Approach:
        1. **Data Structure Setup**:
            - We use a hash map (`color_of_each_ball`) to store the color of each ball. The ball number is the key, and the color is the value.
            - We use an unordered set (`distinct_colors`) to store the distinct colors encountered so far.
        2. **Processing Each Query**:
            - For each query, we update the color of the specified ball in the hash map.
            - We then iterate over the map, inserting each color into the unordered set. This ensures that only distinct colors are stored.
            - After updating the set with the current ball’s color, we append the size of the set (the count of distinct colors) to the result list.
        3. **Returning the Result**:
            - After processing all queries, we return the list of results, which contains the number of distinct colors after each query.
        
    - ### Code Implementation:
        - **Python Solution:**
            ```python3 []
            class Solution:
                def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
                    # Initialize a dictionary to store the color of each ball, with default value 0 (int)
                    color_of_each_ball = defaultdict(int)
                    
                    # List to store the number of distinct colors after each query
                    no_of_distinct_colors_after_query = []

                    # Iterate through each query in the queries list
                    for current_ball, current_color in queries:
                        # Assign the color to the current ball
                        color_of_each_ball[current_ball] = current_color

                        # Calculate the number of distinct colors after updating the current ball's color
                        # Convert the values (colors) of the dictionary to a set to remove duplicates, then get the length of the set
                        no_of_distinct_colors_for_current_query = len(set(color_of_each_ball.values()))

                        # Append the result (number of distinct colors) after the current query to the list
                        no_of_distinct_colors_after_query.append(no_of_distinct_colors_for_current_query)

                    # Return the list of distinct color counts after each query
                    return no_of_distinct_colors_after_query
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - For each query, we are:
            1. Updating the color of a ball in the hash map, which takes **$O(1)$** time on average.
            2. Iterating over the `color_of_each_ball` map to insert the colors into an unordered set. In the worst case, we might need to insert all balls into the set, so this takes **$O(n)$** time, where $n$ is the number of balls (the size of the map).
            3. Calculating the size of the unordered set takes **$O(1)$** time.

            Therefore, the time complexity for each query is **$O(n)$**, and for $q$ queries, the total time complexity is **$O(q \times n)$**.

    - ### Space Complexity:
        - We maintain an unordered map `color_of_each_ball` to store the color of each ball. This requires **$O(n)$** space, where $n$ is the number of balls (or the number of unique balls).
        - We use an unordered set `distinct_colors` to store the distinct colors. In the worst case, the number of distinct colors could be equal to the number of balls, so this requires **$O(n)$** space.
        - The result list `no_of_distinct_colors_after_query` stores one integer for each query, requiring **$O(q)$** space, where $q$ is the number of queries.

            Thus, the overall space complexity is **$O(n+q)$**.
    <hr>

- ## Approach 2:- Optimization
    - ### Intuition:
        The problem involves keeping track of the number of distinct colors after each update to the balls. Each query assigns a new color to a ball, and we need to compute how many distinct colors are in use after each update.

        To efficiently compute the number of distinct colors after each query, we can use two main pieces of information:
        1. **Mapping from balls to their current colors**: This allows us to know the color of each ball when updating or removing it.
        2. **Counting how many times each color is used**: This lets us know when a color becomes unused (its count reaches zero) or when a new color is introduced.

        By keeping track of both the color of each ball and the count of each color, we can efficiently update the distinct color count after each query.

    - ### Approach:
        1. Initialize:
            - A dictionary (`color_of_each_ball`) to store the current color of each ball.
            - A dictionary (`color_count`) to store how many balls are using each color.
            - A variable (`distinct_color_count`) to store the number of distinct colors in use.
        2. For each query:
            - Retrieve the current ball and the new color it should take.
            - If the ball already has a color, decrement the count for the previous color.
            - If the new color is not used by any ball, increment the `distinct_color_count`.
            - Update the ball's color and increment the count for the new color.
        3. Append the current value of `distinct_color_count` to the result list.
        4. After processing all the queries, return the result list, which contains the number of distinct colors after each query.
    
    - ### Code Implementation:
        - **Python Solution:**
            ```python3 []
            class Solution:
                def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
                    # This will store the result of distinct colors after each query
                    no_of_distinct_colors_after_query = []

                    # color_of_each_ball will map each ball to its assigned color
                    # color_count will keep track of the frequency of each color
                    color_of_each_ball = defaultdict(int)
                    color_count = defaultdict(int)

                    # This variable tracks the total number of distinct colors
                    distinct_color_count = 0
                    
                    # Iterate through each query in the queries list
                    for current_ball, current_color in queries:
                        # Get the current color of the ball (0 if it hasn't been assigned a color yet)
                        previous_color = color_of_each_ball.get(current_ball, 0)
                        
                        # If the ball already had a color (i.e., it is not 0), we need to update the distinct color count
                        if previous_color != 0:
                            # Decrease the count of the previous color
                            color_count[previous_color] -= 1
                            
                            # If the previous color count is 0, we need to decrease the distinct color count
                            if color_count[previous_color] == 0:
                                distinct_color_count -= 1
                        
                        # If the current color hasn't been used before, increase the distinct color count
                        if color_count[current_color] == 0:
                            distinct_color_count += 1
                        
                        # Update the color of the current ball
                        color_of_each_ball[current_ball] = current_color
                        
                        # Increase the count of the current color
                        color_count[current_color] += 1

                        # Append the current distinct color count after this query
                        no_of_distinct_colors_after_query.append(distinct_color_count)

                    # Return the final list of distinct color counts after each query
                    return no_of_distinct_colors_after_query
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **Per query**: Each query requires checking and updating values in two dictionaries (for color of balls and color counts). These operations take constant time, i.e., $O(1)$.
        - **Overall Time Complexity**: Given $n$ queries, the total time complexity is **$O(n)$**.

    - ### Space Complexity:
        - **Space Complexity**: We use two dictionaries (`color_of_each_ball` and `color_count`) to store information about the balls and their colors. The space used depends on the number of distinct colors and balls, so the space complexity is **$O(m)$**, where $m$ is the number of distinct colors.
    <hr>