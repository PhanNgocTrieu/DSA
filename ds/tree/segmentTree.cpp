#include <vector>
#include <iostream>

/**
 * @class SegmentTree
 * @brief A class to represent a Segment Tree data structure for efficient range queries and updates.
 */
class SegmentTree {
private:
    std::vector<int> tree; ///< The segment tree represented as a vector.
    std::vector<int> data; ///< The original input data.
    int n; ///< The size of the input data.

    /**
     * @brief Builds the segment tree.
     * @param node The current node in the segment tree.
     * @param start The starting index of the segment.
     * @param end The ending index of the segment.
     */
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start]; ///< Leaf node will have a single element.
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node + 1, start, mid); ///< Recursively build the left child.
            buildTree(2 * node + 2, mid + 1, end); ///< Recursively build the right child.
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; ///< Internal node will have the sum of both children.
        }
    }

    /**
     * @brief Updates the segment tree.
     * @param node The current node in the segment tree.
     * @param start The starting index of the segment.
     * @param end The ending index of the segment.
     * @param idx The index of the element to be updated.
     * @param val The new value of the element.
     */
    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            data[idx] = val; ///< Update the data array.
            tree[node] = val; ///< Update the leaf node.
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                updateTree(2 * node + 1, start, mid, idx, val); ///< Update the left child.
            } else {
                updateTree(2 * node + 2, mid + 1, end, idx, val); ///< Update the right child.
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; ///< Update the internal node.
        }
    }

    /**
     * @brief Queries the segment tree for the sum in a given range.
     * @param node The current node in the segment tree.
     * @param start The starting index of the segment.
     * @param end The ending index of the segment.
     * @param L The starting index of the query range.
     * @param R The ending index of the query range.
     * @return The sum of the elements in the range [L, R].
     */
    int queryTree(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0; ///< Range represented by a node is completely outside the given range.
        }
        if (L <= start && end <= R) {
            return tree[node]; ///< Range represented by a node is completely inside the given range.
        }
        int mid = (start + end) / 2;
        int leftSum = queryTree(2 * node + 1, start, mid, L, R); ///< Query the left child.
        int rightSum = queryTree(2 * node + 2, mid + 1, end, L, R); ///< Query the right child.
        return leftSum + rightSum; ///< Return the sum of results.
    }

public:
    /**
     * @brief Constructs the SegmentTree object.
     * @param input The input data to build the segment tree from.
     */
    SegmentTree(const std::vector<int>& input) {
        data = input;
        n = data.size();
        tree.resize(4 * n); ///< Resize the tree to accommodate the segment tree structure.
        buildTree(0, 0, n - 1); ///< Build the segment tree.
    }

    /**
     * @brief Updates an element in the segment tree.
     * @param idx The index of the element to be updated.
     * @param val The new value of the element.
     */
    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val); ///< Update the segment tree.
    }

    /**
     * @brief Queries the sum of elements in a given range.
     * @param L The starting index of the query range.
     * @param R The ending index of the query range.
     * @return The sum of the elements in the range [L, R].
     */
    int query(int L, int R) {
        return queryTree(0, 0, n - 1, L, R); ///< Query the segment tree.
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    std::cout << "Sum of values in given range = " << segTree.query(1, 3) << std::endl;

    segTree.update(1, 10);

    std::cout << "Updated sum of values in given range = " << segTree.query(1, 3) << std::endl;

    return 0;
}