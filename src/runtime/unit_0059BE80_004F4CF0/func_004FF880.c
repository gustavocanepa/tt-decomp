/* compiler: ee-gcc2.9-991111 */
/* Submit operation 253 after a backend compatibility check and empty-table check.
 * Shared response RAM is func_005AE2E8 through its uncached alias before unlocking.
 * Operation semantics and the unused packet word remain provisional. */
struct Request { int argument; int unknown4; };
extern struct Request D_0078DD00;
extern char D_0078F400;
extern int D_0078E940, D_005A315C;
extern int func_004FF348(int);
extern void func_004FF378(void);
extern int func_004FF470(void);
extern int func_004FF678(void);
extern int func_004FECD0(void);
extern unsigned int func_004FEDD8(void *, int, int, void *, int, void *, int,
    void (*)(void *), void *, int);
int func_004FF880(int argument) {
    int result;
    func_004FF348(253);
    if (!D_005A315C) func_004FF470();
    if (func_004FF678()) {
        func_004FF378();
        return 0xFFFEFFFC;
    }
    if (func_004FECD0()) {
        func_004FF378();
        return -16;
    }
    D_0078DD00.argument = argument;
    if ((int)func_004FEDD8(&D_0078F400, 253, 0, &D_0078DD00, 8,
                         &D_0078E940, 4, 0, 0, 0) < 0) {
        func_004FF378();
        return -11;
    }
    result = *(int *)((unsigned)&D_0078E940 | 0x20000000);
    func_004FF378();
    return result;
}
