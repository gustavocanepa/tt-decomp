/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern int D_005A3164;
extern char D_006179C8[];
extern int func_004FA820(struct SemaParam *param);

void func_004FF2F0(void) {
    struct SemaParam param;

    if (D_005A3164 == -1) {
        param.initCount = 1;
        param.maxCount = 1;
        param.option = (unsigned int)D_006179C8; /* "SceStdioFioSema" */
        D_005A3164 = func_004FA820(&param);
    }
}
