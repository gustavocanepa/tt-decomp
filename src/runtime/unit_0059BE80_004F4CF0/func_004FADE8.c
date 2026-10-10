/* compiler: ee-gcc2.9-991111 */
extern int D_005A30BC;
extern int func_004FBF88(void);
extern int func_004FBD40(int a, int b);

int func_004FADE8(int mode, int a, int b)
{
    if (mode == 1 || mode == 2) {
        if (D_005A30BC == 0) {
            if (func_004FBF88() == 0)
                return -1;
            D_005A30BC = 1;
        }
        return func_004FBD40(a, b);
    }
    return -1;
}
