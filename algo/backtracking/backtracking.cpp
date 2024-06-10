#include "backtracking.h"
namespace algorithm
{
    std::vector<std::vector<std::string>> backtracking::solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> board(n, std::vector<std::string>(n, "."));
        return board;
    }

    void backtracking::permunate(std::string S, int l, int r, std::vector<std::string>& res) {
        if (l == r) {
            // std::cout << S << std::endl;
            res.push_back(S);
            return;
        }

        for (int i = l; i <= r; i++) {
            std::swap(S[l], S[i]);
            permunate(S, l + 1, r, res);
            std::swap(S[l], S[i]);
        }
    }

    std::vector<std::string> backtracking::find_permutation(std::string S)
    {
        std::vector<std::string>  res;
        permunate(S, 0, S.length() - 1, res);
        return res;
    }

}