/* compiler: ee-gcc2.9-991111 */
extern int D_005A0DA8;
extern void *D_005A0DB8;
int func_004FA860(int sema);
int func_004FA840(int sema);

void *func_004E1818(void *handler)
{
    void *old;

    func_004FA860(D_005A0DA8);
    old = D_005A0DB8;
    D_005A0DB8 = handler;
    do { func_004FA840(D_005A0DA8); } while (0);
    return old;
}
