/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long long s64 __attribute__((aligned(4)));

struct E {
    s64 q0;
    s64 q1;
    s64 q2;
    f32 key() { return *(f32 *)((char *)this + 4); }
} __attribute__((aligned(4)));

struct List {
    s32 n;
    E e[1];
};

extern "C" void func_003CAE28(List *l) {
    s32 i, j;
    for (i = 0; i < l->n; i++) {
        E tmp = l->e[i];
        for (j = 0; j < i; j++) {
            if (l->e[j].key() > tmp.key()) {
                E t = l->e[j];
                l->e[j] = tmp;
                tmp = t;
            }
        }
        l->e[i] = tmp;
    }
}
