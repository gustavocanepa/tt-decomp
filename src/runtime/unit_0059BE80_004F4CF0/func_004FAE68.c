/* compiler: ee-gcc2.9-991111 */
extern int func_004FBF88(void);
extern int func_004FBEB8(int a, int b);
extern int D_005A30BC;

int func_004FAE68(int mode, int a, int b)
{
    if (mode == 0) {
        if (D_005A30BC == 0) {
            if (func_004FBF88() == 0)
                return -1;
            D_005A30BC = 1;
        }
        return func_004FBEB8(a, b);
    }
    return -1;
}
