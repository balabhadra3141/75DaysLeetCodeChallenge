class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int area = h * (right - left);
        maxWater = max(maxWater, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
    }
};