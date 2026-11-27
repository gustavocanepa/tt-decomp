#include "types.h"
extern "C" void func_00562008(int *first, int *last, int val) {
    (void)&val;
    while (first != last) {
        int tmp = val; val++; *first++ = tmp;
    }
}
