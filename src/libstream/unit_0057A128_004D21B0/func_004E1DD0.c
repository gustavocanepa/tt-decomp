/* compiler: ee-gcc2.9-991111 */
extern int D_005A0D90;
extern int D_005A2934;
extern char D_0078B110[];
extern void func_004FD2D0(const char *fmt, ...);
extern int func_004E1E70(unsigned int, unsigned int, void *, int, void *);

int func_004E1DD0(void)
{
    D_005A2934 = 1;
    if (D_005A0D90 > 0)
        func_004FD2D0("sceCdStResume call\n");
    return func_004E1E70(0, 0, 0, 8, D_0078B110);
}
