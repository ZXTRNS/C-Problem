#include <stdio.h>
#include <stdint.h>

typedef long long ll;

// compute (XL, XR) for given index idx at level m (where K = 2^m - 1)
void get_range(ll idx, int m, ll *xl, ll *xr) {
    if (m == 1) {               // base: level 1 has only one segment [1,1]
        *xl = 1;
        *xr = 1;
        return;
    }
    // K_prev = 2^(m-1) - 1
    ll pow_prev = 1LL << (m - 1);       // 2^(m-1)
    ll K_prev = pow_prev - 1;           // 2^(m-1) - 1
    ll center = K_prev + 1;             // center index = 2^(m-1)

    if (idx == center) {
        *xl = 1;
        *xr = center;
        return;
    } else if (idx < center) {
        // belongs to the left block (level m-1)
        get_range(idx, m - 1, xl, xr);
        return;
    } else {
        // belongs to right block: map to idx - center in level m-1 then shift by K_prev
        ll subxl, subxr;
        get_range(idx - center, m - 1, &subxl, &subxr);
        *xl = subxl + K_prev;
        *xr = subxr + K_prev;
        return;
    }
}

int main(void) {
    ll A, B;
    if (scanf("%lld %lld", &A, &B) != 2) return 0;

    // precompute minimal m such that 2^m - 1 >= B
    int m = 1;
    while (((1LL << m) - 1) < B) m++;  // safe: 1<<m fits in 64-bit for m <= 62

    // For each index in [A..B], compute and print
    for (ll i = A; i <= B; ++i) {
        ll xl, xr;
        // find smallest level mm such that 2^mm -1 >= i (ensure recursion works)
        // In practice using the global m is fine because if i <= B <= 2^m -1,
        // the recursion will reduce m as needed. But for safety we can compute mm:
        int mm = m;
        while (((1LL << mm) - 1) < i) mm++;

        get_range(i, mm, &xl, &xr);
        printf("%lld %lld\n", xl, xr);
    }

    return 0;
}
