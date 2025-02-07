from collections import defaultdict
from typing import List

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