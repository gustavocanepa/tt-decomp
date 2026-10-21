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

extern "C" void func_0034E488(void *, char *);

typedef char *(*GetFn)(char *, s32);
typedef s32 (*Test1)(char *, char *);
typedef s32 (*Test2)(char *, R6C *, char *);
typedef void (*Act)(char *, char *, s32, float);

extern "C" void func_002D5FC8(char *arg0, float fp0) {
    s32 i = 0;
    char *s6 = arg0 + 0xE60;
    R6C *s3 = *(R6C **)(arg0 + 0x6C);
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *s4 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    func_0034E488(*(void **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80), s6);
    s32 n = (*(List *volatile *)&s3->list)->count;
    {
        for (; i < n;) {
            VEntry *e2 = (VEntry *)(*(char **)(arg0 + 0x64) + 0x4D8);
            char *c = (char *)s3->list->items[i];
            i++;
            if (((Test1)e2->fn)(arg0 + e2->delta, c) != 0) {
                VEntry *e3 = (VEntry *)(*(char **)s4 + 0x1B8);
                if (((Test2)e3->fn)(s4 + e3->delta, s3, c) != 0) {
                    char *a3 = *(char **)(c + 0x4840);
                    VEntry *e4 = (VEntry *)(*(char **)(a3 + 8) + 0x160);
                    ((Act)e4->fn)(a3 + e4->delta, s6, 1, fp0);
                }
            }
        }
    }
}
