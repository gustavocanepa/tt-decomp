/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern s32 D_005A293C;
extern char D_0078B118[];
extern "C" s32 func_004E2370(s32, s32, s32, s32, void *);

extern "C" long long func_004E2300(void) {
    D_005A293C = 1;
    return func_004E2370(0, 0, 0, 8, D_0078B118);
}
