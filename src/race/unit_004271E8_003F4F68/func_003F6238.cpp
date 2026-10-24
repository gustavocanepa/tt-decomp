#include "types.h"
extern "C" void func_003F6238(int unused, u64 x, u64 *arr, int n) {
    int pos = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) return;
        if (x < arr[i]) { pos = i; break; }
    }
    if (pos != -1) {
        int j = n - 1;
        while (pos < j) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[pos] = x;
    }
}
