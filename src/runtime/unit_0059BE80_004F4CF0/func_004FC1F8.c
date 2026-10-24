/* compiler: ee-gcc2.9-991111 */
extern char D_00617740[];
extern char D_00617748[];
extern char D_00617750[];
extern int func_004B4488(double);
extern int func_004B47C0(double, double);
extern double dpdiv(double, double);
extern double dpmul(double, double);
extern double func_004B4B00(double, double);
extern int func_004FC168(int);
extern int func_004FD190(int (*out)(), void *ctx, int *remain, char *fmt, ...);

int func_004FC1F8(int (*out)(), void *ctx, int *remain, double x)
{
    int sign = 0;
    int exp = 0;
    int n;
    if (*remain == 0)
        return 0;
    if (func_004B47C0(x, 0.0) < 0) {
        sign = 1;
        x = func_004B4B00(0.0, x);
        out(ctx, remain, 0x2D);
        *remain -= 1;
    }
    if (func_004B47C0(x, 0.1) < 0) {
        while (func_004B47C0(x, 0.1) < 0) {
            exp--;
            x = dpmul(x, 10.0);
        }
    } else if (func_004B47C0(x, 1.0) >= 0) {
        while (func_004B47C0(x, 1.0) >= 0) {
            exp++;
            x = dpdiv(x, 10.0);
        }
    }
    n = func_004FC168(func_004B4488(dpmul(x, 1000000.0)));
    sign += func_004FD190(out, ctx, remain, D_00617740, n);
    if (exp >= 0)
        sign += func_004FD190(out, ctx, remain, D_00617748, exp);
    else
        sign += func_004FD190(out, ctx, remain, D_00617750, exp);
    return sign;
}
