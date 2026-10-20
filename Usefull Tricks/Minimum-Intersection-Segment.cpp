// Use Segment Tree for Range Minimum

vector<int> minimumIntersect(vector<pair<int, int>> arr) {
    int n = (int)arr.size();

    vector<pair<int, int>> segments = arr;
    sort(segments.begin(), segments.end());

    vector<int> left(n), right(n), len(n), preMin(n, INF);

    for (int i = 0; i < n; i++) {
        left[i] = segments[i].first;
        right[i] = segments[i].second;
        len[i] = right[i] - left[i] + 1;

        preMin[i] = right[i];
        if (i > 0) {
            preMin[i] = min(preMin[i], preMin[i - 1]);
        }
    }

    segmentTree st(len);
    map<pair<int, int>, int> result;

    for (auto [lf, rt] : arr) {
        int ans = rt - lf + 1;
        int first = lower_bound(left.begin(), left.end(), lf) - left.begin();
        int after = upper_bound(left.begin(), left.end(), rt) - left.begin();
        bool disjointLeft = (first > 0 && preMin[first - 1] < lf);
        bool disjointRight = (after < n);

        if (disjointLeft || disjointRight) ans = 0;
        else {
            if (first > 0) {
                ans = min(ans, min(rt, preMin[first - 1]) - lf + 1);
            }

            int last = after - 1;
            int minLen = st.RQ(first, last);
            ans = min(ans, min(rt - left[last] + 1, minLen));
        }

        result[{lf, rt}] = ans;
    }

    vector<int> ans;
    for (auto [lf, rt] : arr) {
        ans.push_back(result[{lf, rt}]);
    }

    return ans;
}
