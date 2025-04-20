// Time:  O(|V| + |E|)
// Space: O(|V|)

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> result = {startUrl};
        unordered_set<string> lookup(result.cbegin(), result.cend());
        for (int i = 0; i < result.size(); ++i) {
            const auto& from_url = result[i];
            const auto& name = hostname(from_url);
            for (const auto& to_url: htmlParser.getUrls(from_url)) {
                if (!lookup.count(to_url) && name == hostname(to_url)) {
                    result.emplace_back(to_url);
                    lookup.emplace(to_url);
                }
            }
        }
        return result;
    }

private:
    string hostname(const string& url) {
        static const string scheme = "http://";
        return url.substr(0, url.find('/', scheme.length()));
    }
};
