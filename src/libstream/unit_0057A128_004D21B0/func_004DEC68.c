/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(void);

extern Handler D_0078A640;
extern void *D_0078A644;

int func_004DF780(int);
int func_005038D8(void);
void func_00503928(void);

Handler func_004DEC68(Handler handler)
{
    Handler old;
    int state;

    if (func_004DF780(1) != 0)
        return 0;
    state = func_005038D8();
    old = D_0078A640;
    D_0078A640 = handler;
    __asm__ volatile("sw $gp, %0" : "=m"(D_0078A644));
    if (state)
        func_00503928();
    return old;
}
