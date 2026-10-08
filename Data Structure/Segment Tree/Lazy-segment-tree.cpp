#include <bits/stdc++.h>
using namespace std;

//For avoiding overflow: use long long int instead of int, and use 1LL for multiplication
struct segmentTree{
   vector<int> arr, segTree, lazyTree;
   int n;

   segmentTree(const vector<int> &input) {
       n = (int)input.size();
       arr = input;
       segTree.resize(4 * n);
       lazyTree.resize(4 * n);

       buildSegmentTree(0, 0, n - 1);
   }

   void buildSegmentTree(int indx, int left, int right) {
       if (left == right) {
            segTree[indx] = arr[left];
            return;
       }

       int mid = (left + right) >> 1;
       buildSegmentTree(2 * indx + 1, left, mid);
       buildSegmentTree(2 * indx + 2, mid + 1, right);

       segTree[indx] = segTree[2 * indx + 1] + segTree[2 * indx + 2];
   }

   // Point Operation: Update and calling
   void pointUpdate(int indx, int left, int right, int point, int val) {
       if (left == right) {
           segTree[indx] = val;
           arr[left] = val;
           return;
       }

       int mid = (left + right) >> 1;
       if (point <= mid) pointUpdate(2 * indx + 1, left, mid, point, val);
       else pointUpdate(2 * indx + 2, mid + 1, right, point, val);

       segTree[indx] = segTree[2 * indx + 1] + segTree[2 * indx + 2];
   }

   void PU(int point, int val) {
       pointUpdate(0, 0, n - 1, point, val);
   }

   // Range Operations: Update & Query with Lazy Propagation
   void lazyUpdate(int indx, int left, int right) {
       if (lazyTree[indx]) {
            segTree[indx] += (right - left + 1) *1LL* lazyTree[indx];
            if (left != right) {
                 lazyTree[2 * indx + 1] += lazyTree[indx];
                 lazyTree[2 * indx + 2] += lazyTree[indx];
            }
            lazyTree[indx] = 0;
       }
   }

   void rangeUpdate(int indx, int left, int right, int l, int r, int val) {
       lazyUpdate(indx, left, right);

       if (l > right || r < left || left > right) return;
       if (left >= l and r >= right) {
            segTree[indx] += (right - left + 1) *1LL* val;
            if (left != right) {
                 lazyTree[2 * indx + 1] += val;
                 lazyTree[2 * indx + 2] += val;
            }
            return;
       }

       int mid = (left + right) >> 1;
       rangeUpdate(2 * indx + 1, left, mid, l, r, val);
       rangeUpdate(2 * indx + 2, mid + 1, right, l, r, val);

       segTree[indx] = segTree[2 * indx + 1] + segTree[2 * indx + 2];
   }

   int rangeQuery(int indx, int left, int right, int l, int r) {
       lazyUpdate(indx, left, right);

       if (l > right || r < left || left > right) return 0;
       if (left >= l and r >= right) return segTree[indx];

       int mid = (left + right) >> 1;
       return rangeQuery(2 * indx + 1, left, mid, l, r) + 
                rangeQuery(2 * indx + 2, mid + 1, right, l, r);
   }

   // Range Operation: Shortcut calling 
   void RU(int l, int r, int val) {
       rangeUpdate(0, 0, n - 1, l, r, val);
   }

   int RQ(int l, int r) {
       return rangeQuery(0, 0, n - 1, l, r);
   }

};

int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q; 
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
     cin >> arr[i];
    }

    segmentTree Tree(arr);

    while(q--) {
        int type, l, r; 
        cin >> type >> l >> r;

        if (type == 1) {
           int val; 
           cin >> val;
           Tree.RU(l, r, val);
        } else {
            cout << Tree.RQ(l, r) << "\n";
        }
    }
     
    return 0;
}