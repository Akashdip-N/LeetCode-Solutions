/*
    https://leetcode.com/problems/product-of-array-except-self
*/
/*
    Solution Approach: Using Prefix and Suffix Products
    Time Complexity: O(n)
    Space Complexity: O(1) (excluding output array)
    n = size of the input array

    Explanation:
        - We create an output array initialized to 1.
        - First, we calculate the prefix products for each index.
        - Then, we calculate the suffix products in reverse order and
            multiply them with the prefix products.
        - The output array will contain the product of all elements
            except the one at the current index.
        - We return the output array as the result.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // Calculate prefix products
        for (int i = 1; i < n; ++i)
            result[i] = result[i - 1] * nums[i - 1];

        // Calculate suffix products and multiply with prefix products
        int suffixProduct = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffixProduct *= nums[i + 1];
            result[i] *= suffixProduct;
        }

        return result;
    }
};
