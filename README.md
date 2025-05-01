# even-step-cf-trick

Two Codeforces problems illustrating the “smallest change is even” insight—once you know the min and max achievable values (they differ by an even step), you can get **every** value in between.

- **Permutation Warm-Up**  
  - **Min** sum of \|pᵢ–i\| is 0 (identity).  
  - **Max** is reverse order.  
  - Since any swap changes the sum by an even number, all even values from 0 to max are reachable.

- **Zero Path**  
  - Each move adds ±1; path length L=n+m–1.  
  - Min sum = –L, max = +L, and you change parity by 2.  
  - So 0 is reachable iff L is even (i.e. min ≤ 0 ≤ max and (max–min) even).

---

## 💻 Solutions

### 1. `src/permutation_warmup.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  CF “Permutation Warm-Up”
  Trick: sum of |p[i]–i| moves in even steps only.
  All even values from 0 to maxSum are possible.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // maximum sum = sum |i − (n−i+1)| = n²/2 (for even n) or floor(n²/2)
        int maxSum = (n / 2) * 2 * (n - 2*(n/2) + 1) 
                   + ((n%2) ? n/2 * 2 * ((n/2)+1) : 0);
        // but simpler: maxSum = (n/2)*(n - n/2)*2
        maxSum = (n/2) * (n - n/2) * 2;

        // k must be ≤ maxSum, and (maxSum − k) even
        cout << ((k <= maxSum && (maxSum - k) % 2 == 0) ? "YES\n" : "NO\n");
    }
}

