#include <iostream>
#include "Solution.hpp"

struct testcase {
    int limit;
    vector<vector<int>> queries;
    vector<int> expected;
};

class UnitTest {
private:
    unordered_map<int, testcase> testcases;
    Solution solution;
    bool compare(vector<int>& a, vector<int>& b) {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    void test_example_case_1() {
        int limit = testcases[1].limit;
        vector<vector<int>>& queries = testcases[1].queries;
        vector<int>& expected = testcases[1].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_example_case_1: " << (match ? "passed": "failed") << endl;
    }
    void test_example_case_2() {
        int limit = testcases[2].limit;
        vector<vector<int>>& queries = testcases[2].queries;
        vector<int>& expected = testcases[2].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_example_case_2: " << (match ? "passed": "failed") << endl;
    }
    void test_basic_case() {
        int limit = testcases[3].limit;
        vector<vector<int>>& queries = testcases[3].queries;
        vector<int>& expected = testcases[3].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_basic_case: " << (match ? "passed": "failed") << endl;
    }
    void test_no_color_change() {
        int limit = testcases[4].limit;
        vector<vector<int>>& queries = testcases[4].queries;
        vector<int>& expected = testcases[4].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_no_color_change: " << (match ? "passed": "failed") << endl;
    }
    void test_changing_color() {
        int limit = testcases[5].limit;
        vector<vector<int>>& queries = testcases[5].queries;
        vector<int>& expected = testcases[5].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_changing_color: " << (match ? "passed": "failed") << endl;
    }
    void test_no_balls_colored_initially() {
        int limit = testcases[6].limit;
        vector<vector<int>>& queries = testcases[6].queries;
        vector<int>& expected = testcases[6].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_no_balls_colored_initially: " << (match ? "passed": "failed") << endl;
    }
    void test_reusing_colors() {
        int limit = testcases[7].limit;
        vector<vector<int>>& queries = testcases[7].queries;
        vector<int>& expected = testcases[7].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_reusing_colors: " << (match ? "passed": "failed") << endl;
    }
    void test_all_balls_colored_simultaneously_with_different_colors() {
        int limit = testcases[8].limit;
        vector<vector<int>>& queries = testcases[8].queries;
        vector<int>& expected = testcases[8].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_all_balls_colored_simultaneously_with_different_colors: " << (match ? "passed": "failed") << endl;
    }
    void test_same_ball_recolored_multiple_times() {
        int limit = testcases[9].limit;
        vector<vector<int>>& queries = testcases[9].queries;
        vector<int>& expected = testcases[9].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_same_ball_recolored_multiple_times: " << (match ? "passed": "failed") << endl;
    }
    void test_limit_case_with_large_input() {
        int limit = testcases[10].limit;
        vector<vector<int>>& queries = testcases[10].queries;
        vector<int>& expected = testcases[10].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_limit_case_with_large_input: " << (match ? "passed": "failed") << endl;
    }
    void test_single_ball_multiple_queries() {
        int limit = testcases[11].limit;
        vector<vector<int>>& queries = testcases[11].queries;
        vector<int>& expected = testcases[11].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_single_ball_multiple_queries: " << (match ? "passed": "failed") << endl;
    }
    void test_edge_case_color_removal() {
        int limit = testcases[12].limit;
        vector<vector<int>>& queries = testcases[12].queries;
        vector<int>& expected = testcases[12].expected;

        vector<int> result = solution.queryResults(limit, queries);
        bool match = compare(result, expected);
        cout << "test_edge_case_color_removal: " << (match ? "passed": "failed") << endl;
    }
public:
    UnitTest() {
        testcases = {{1, {4, {{1,4},{2,5},{1,3},{3,4}}, {1,2,2,3}}},
                     {2, {4, {{0,1},{1,2},{2,2},{3,4},{4,5}}, {1,2,2,3,4}}},
                     {3, {5, {{0,1},{1,2},{2,3},{3,4},{4,5}}, {1,2,3,4,5}}},
                     {4, {3, {{0,1},{1,1},{2,1}}, {1,1,1}}},
                     {5, {4, {{0,1},{1,2},{2,2},{0,3},{3,4}}, {1,2,2,2,3}}},
                     {6, {0, {}, {}}},
                     {7, {3, {{0,1},{1,2},{0,2},{1,3},{2,1}}, {1,2,1,2,3}}},
                     {8, {5, {{0,10},{1,20},{2,30},{3,40},{4,50}}, {1,2,3,4,5}}},
                     {9, {3, {{0,5},{0,10},{0,15},{0,5},{0,20}}, {1,1,1,1,1}}},
                     {11, {1, {{0,5},{0,10},{0,5},{0,15}}, {1,1,1,1}}},
                     {12, {5, {{0,1},{1,2},{2,3},{0,4},{1,5},{2,6},{0,1},{1,2}}, {1,2,3,3,3,3,3,3}}}};
        
        vector<vector<int>> x(1000);
        vector<int> y(1000);
        for(int i = 0; i < 1000; i++) x[i] = {i, i+1};
        for(int i = 0; i < 1000; i++) y[i] = i+1;
        
        testcases[10] = {1000, x, y};
    }
    void test() {
        test_example_case_1();
        test_example_case_2();
        test_basic_case();
        test_no_color_change();
        test_changing_color();
        test_no_balls_colored_initially();
        test_reusing_colors();
        test_all_balls_colored_simultaneously_with_different_colors();
        test_same_ball_recolored_multiple_times();
        test_limit_case_with_large_input();
        test_single_ball_multiple_queries();
        test_edge_case_color_removal();
    }
};

int main() {
    UnitTest test;
    test.test();
    return 0;
}