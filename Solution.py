from collections import defaultdict
from typing import List

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