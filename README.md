# [3160. Find the Number of Distinct Colors Among the Balls](https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls)

**Type:** Medium <br>
**Topics:** Array, Hash Table, Simulation 
<hr>

You are given an integer `limit` and a 2D array `queries` of size `n x 2`.

There are `limit + 1` balls with **distinct** labels in the range `[0, limit]`. Initially, all balls are uncolored. For every query in `queries` that is of the form `[x, y]`, you mark ball `x` with the color `y`. After each query, you need to find the number of distinct colors among the balls.

Return an array `result` of length `n`, where `result[i]` denotes the number of distinct colors *after* <code>i<sup>th</sup></code> query.

**Note** that when answering a query, lack of a color *will not* be considered as a color.
<hr>

- ### Examples:
    - **Example 1:** <br>
    **Input:** limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]] <br>
    **Output:** [1,2,2,3] <br>
    **Explanation:** <br>
    ![](https://assets.leetcode.com/uploads/2024/04/17/ezgifcom-crop.gif)
    After query 0, ball 1 has color 4.<br>
    After query 1, ball 1 has color 4, and ball 2 has color 5.<br>
    After query 2, ball 1 has color 3, and ball 2 has color 5.<br>
    After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.

    - **Example 2:** <br>
    **Input:** limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]] <br>
    **Output:** [1,2,2,3,4] <br>
    **Explanation:** <br>
    ![](https://assets.leetcode.com/uploads/2024/04/17/ezgifcom-crop2.gif)
    After query 0, ball 0 has color 1. <br>
    After query 1, ball 0 has color 1, and ball 1 has color 2. <br>
    After query 2, ball 0 has color 1, and balls 1 and 2 have color 2. <br>
    After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4. <br>
    After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.
<hr>

- ### Constraints:
    - <code>1 <= limit <= 10<sup>9</sup></code>
    - <code>1 <= n == queries.length <= 10<sup>5</sup></code>
    - `queries[i].length == 2`
    - `0 <= queries[i][0] <= limit`
    - <code>1 <= queries[i][1] <= 10<sup>9</sup></code>
<hr>

- ### Hints:
    - Use two HashMaps to maintain the color of each ball and the set of balls with each color.
<hr>