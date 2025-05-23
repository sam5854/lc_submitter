// Time:  O(nlogn)
// Space: O(1)
// Using template.

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        using namespace std::placeholders;  // for _1, _2, _3...

        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        const int left = binarySearch(0, y - 1, bind(searchColumns, image, true, _1));
        const int right = binarySearch(y + 1, image[0].size() - 1, bind(searchColumns, image, false, _1));
        const int top = binarySearch(0, x - 1, bind(searchRows, image, true, _1));
        const int bottom = binarySearch(x + 1, image.size() - 1, bind(searchRows, image, false, _1));

        return (right - left) * (bottom - top);
    }
    
private:
    template<typename T>
    int binarySearch(int left, int right, const T& find) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
