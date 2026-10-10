/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern int D_005A3168;
extern int D_005A316C;
extern char D_00617940[];
extern char D_00617950[];
extern int func_004FA820(struct SemaParam *p); /* CreateSema */

void func_004FEC60(void)
{
    struct SemaParam p;

    if (D_005A3168 == -1) {
        p.initCount = 1;
        p.maxCount = 1;
        p.option = (unsigned int)D_00617940;
        D_005A3168 = func_004FA820(&p);
        p.option = (unsigned int)D_00617950;
        D_005A316C = func_004FA820(&p);
    }
}
