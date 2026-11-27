/* compiler: ee-gcc2.9-991111 */

extern int D_005A0DA8;
extern int D_005A0E00;
extern char D_005A1F50[];
extern int func_004DF590(int);
extern void func_004FA840(int);
extern int func_004FE530(void *, int, int, void *, int, void *, int,
                       void *, void *);

/* Command gate 2 submits RPC 14 without a payload and returns its DMA reply.
 * The gate retains the shared semaphore, so both RPC outcomes release it. */
int func_004DF6E8(void)
{
    int result;
    if (!func_004DF590(2))
        return 0;
    if (func_004FE530(D_005A1F50, 14, 0, 0, 0, &D_005A0E00, 4, 0, 0) < 0) {
        func_004FA840(D_005A0DA8);
        return 0;
    }
    result = *(int *)((unsigned int)&D_005A0E00 | 0x20000000);
    func_004FA840(D_005A0DA8);
    return result;
}
