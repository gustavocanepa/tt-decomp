/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct List { s32 count; s32 pad; s32 *items; };
struct R6C { char pad[0x60]; List *list; };

typedef char *(*GetFn)(char *, s32);
typedef s32 (*Test2)(char *, R6C *, char *);
typedef void (*Act)(char *, char *, s32, float);

extern "C" void func_002D5388(char *arg0, char *arg1, float fp0) {
    s32 i = 0;
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *s4 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    R6C *a1 = *(R6C **)(arg0 + 0x6C);
    s32 n = a1->list->count;
    if (n > 0) {
        do {
            VEntry *e3 = (VEntry *)(*(char **)s4 + 0x1B8);
            char *c = (char *)(*(R6C **)(arg0 + 0x6C))->list->items[i];
            i++;
            char *s1 = *(char **)(c + 0x18);
            if (((Test2)e3->fn)(s4 + e3->delta, *(R6C **)(arg0 + 0x6C), c) != 0 && *(unsigned char *)(s1 + 0x565) == 0) {
                char *a3 = *(char **)(c + 0x4840);
                VEntry *e4 = (VEntry *)(*(char **)(a3 + 8) + 0x108);
                ((Act)e4->fn)(a3 + e4->delta, arg1, *(s32 *)(arg0 + 0x36BC), fp0);
            }
        } while (i < n);
    }
}
