/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(int);

extern Handler D_005A4478[];
extern void func_00506AC0(int sig);
extern void func_004FA4D0(int sig, void (*f)(int));
extern void func_004FA4E0(int sig, void (*f)(int));

Handler func_005063B8(int sig, Handler h)
{
    Handler old;

    if ((unsigned int)(sig - 1) >= 13)
        return (Handler)0xFFFFFFFF;
    old = D_005A4478[sig];
    D_005A4478[sig] = h;
    if ((unsigned int)(sig - 1) < 3)
        func_004FA4D0(sig, func_00506AC0);
    else
        func_004FA4E0(sig, func_00506AC0);
    return old;
}
