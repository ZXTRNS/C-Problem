#include <bits/stdc++.h>
using namespace std;

struct Emp {
    string name;
    long long a, b, c;   // Sal1, Sal2, Sal3
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, Q;
        cin >> N >> Q;

        vector<Emp> arr(N+1); // 1-indexed
        for (int i = 1; i <= N; i++) {
            cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
        }

        vector<array<int,3>> cmds; 
        cmds.reserve(Q);

        // read commands
        for (int i = 0; i < Q; i++){
            int t, u, v;
            cin >> t >> u >> v;
            cmds.push_back({t, u, v});
        }

        // process commands in reverse order
        for (int i = Q-1; i >= 0; i--) {
            int t = cmds[i][0], u = cmds[i][1], v = cmds[i][2];

            if (t == 1) {
                // reverse rows u..v
                reverse(arr.begin() + u, arr.begin() + v + 1);
            }
            else if (t == 2) {
                // undo left shift = right shift
                for (int j = u; j <= v; j++) {
                    long long A = arr[j].a, B = arr[j].b, C = arr[j].c;
                    arr[j].a = C;
                    arr[j].b = A;
                    arr[j].c = B;
                }
            }
        }

        // output
        cout << "Case #" << tc << ":\n";
        for (int i = 1; i <= N; i++) {
            cout << arr[i].name << " " << arr[i].c << "\n";
        }
    }

    return 0;
}
