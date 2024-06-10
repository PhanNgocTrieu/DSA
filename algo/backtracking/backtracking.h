#ifndef _BACK_TRACKING_H__
#define _BACK_TRACKING_H__
#include "common.h"

/*
    @brief
        Backtracking is a problem-solving algorithmic technique that involves finding a solution ]
        incrementally by trying different options and undoing them if they lead to a dead end.

    void FIND_SOLUTIONS( parameters):
        if (valid solution):
            store the solution
            Return
        for (all choice):
            if (valid choice):
                APPLY (choice)
                FIND_SOLUTIONS (parameters)
                BACKTRACK (remove choice)
        Return
*/
namespace algorithm
{
    class backtracking
    {
    public:
        enum PROBLEM_NAME
        {
            HELLO_WORLD = 0,
            N_QUEEN,

        };

    public:
        static backtracking &getInstance()
        {
            static backtracking *ins = new backtracking();
            return *ins;
        }

        void execute_problem(uint32_t problemId)
        {
            static std::map<uint32_t, std::function<void()>> m_problemMapping = {
                {0, hello_world},
                {1, n_queen_call},
                {2, find_permutation_call}
            };

            auto foundIt = m_problemMapping.find(problemId);
            if (foundIt == m_problemMapping.end())
            {
                std::cout << "Could not find the problem in set" << std::endl;
                return;
            }
            foundIt->second();
        }

    protected:
        backtracking()
        {
        }

    protected: // This function to asynchronous for calling
        static void hello_world(void)
        {
            std::cout << "Hello World" << std::endl;
        }

        static void n_queen_call(void)
        {
        }

        static void find_permutation_call(void)
        {
            auto get_arr = backtracking::getInstance().find_permutation("ABC");
            for (auto elem : get_arr) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }

    protected: // Database of Problem
        /**
         * @brief
         *      The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
         *      Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
         *      Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
         *
         * @param n
         * @return std::vector<std::vector<std::string>> return
         */
        std::vector<std::vector<std::string>> solveNQueens(int n);

        /**
         * @brief Given a string S. 
         *        The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 
         * 
         * @param S 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> find_permutation(std::string S);

    protected:
        void permunate(std::string S, int l, int r, std::vector<std::string>& res);
        
    protected:
        uint32_t m_problemId = 0;
        std::map<uint32_t, std::function<void()>> m_problemMapping;
    };
}
#endif // _BACK_TRACKING_H__