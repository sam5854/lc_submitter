// Time:  O(n)
// Space: O(1)
// Forward declaration of the read4 API.
// shorter version of Solution2

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (i4_ < n4_ || (i4_ = 0) < (n4_ = read4(buf4_)))) {
            buf[i++] = buf4_[i4_++];
        }
        return i;
    }

private:
    char buf4_[4];
    int i4_ = 0, n4_ = 0;
};
