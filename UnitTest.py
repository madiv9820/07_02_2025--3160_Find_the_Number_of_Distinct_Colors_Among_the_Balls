from Solution import Solution
from timeout_decorator import timeout
import unittest

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: (4, [[1,4],[2,5],[1,3],[3,4]], [1,2,2,3]),
                            2: (4, [[0,1],[1,2],[2,2],[3,4],[4,5]], [1,2,2,3,4]),
                            3: (5, [[0,1],[1,2],[2,3],[3,4],[4,5]], [1,2,3,4,5]),
                            4: (3, [[0,1],[1,1],[2,1]], [1,1,1]),
                            5: (4, [[0,1],[1,2],[2,2],[0,3],[3,4]], [1,2,2,2,3]),
                            6: (0, []),
                            7: (3, [[0,1],[1,2],[0,2],[1,3],[2,1]], [1,2,2,3,3]),
                            8: (5, [[0,10],[1,20],[2,30],[3,40],[4,50]], [1,2,3,4,5]),
                            9: (3, [[0,5],[0,10],[0,15],[0,5],[0,20]], [1,1,1,1,1]),
                            10: (1000, [[i, i+1] for i in range(1000)], [i+1 for i in range(1000)]),
                            11: (1, [[0,5],[0,10],[0,5],[0,15]], [1,1,1,1]),
                            12: (5, [[0,1],[1,2],[2,3],[0,4],[1,5],[2,6],[0,1],[1,2]], [1,2,3,4,5,6,5,4])}
        self.__solution = Solution()
        return super().setUp()
    
    @timeout(1)
    def test_example_case_1(self):
        limit, queries, expected = self.__testcases[1]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_example_case_2(self):
        limit, queries, expected = self.__testcases[2]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_basic_case(self):
        limit, queries, expected = self.__testcases[3]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_no_color_change(self):
        limit, queries, expected = self.__testcases[4]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_changing_color(self):
        limit, queries, expected = self.__testcases[5]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_no_balls_colored_initially(self):
        limit, queries, expected = self.__testcases[6]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_reusing_colors(self):
        limit, queries, expected = self.__testcases[7]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_all_balls_colored_simultaneously_with_different_colors(self):
        limit, queries, expected = self.__testcases[8]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_same_ball_recolored_multiple_times(self):
        limit, queries, expected = self.__testcases[9]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_limit_case_with_large_input(self):
        limit, queries, expected = self.__testcases[10]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_single_ball_multiple_queries(self):
        limit, queries, expected = self.__testcases[11]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)
    @timeout(1)
    def test_edge_case_color_removal(self):
        limit, queries, expected = self.__testcases[12]
        self.assertEqual(self.__solution.queryResults(limit, queries), expected)

if __name__ == '__main__':
    unittest.main()