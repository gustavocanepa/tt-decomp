/* compiler: ee-gcc2.9-991111 */
int func_005038D8(void);
void func_00503928(void);
void func_004FD140(void);
void func_004FC3D0(void (*fn)(void), int *result, unsigned int mask, void *a, void *b);

void func_004FD260(void *a, void *b)
{
    int result = 0;
    int state = func_005038D8();
    func_004FC3D0(func_004FD140, &result, 0xFFFFFFFF, a, b);
    if (state)
        func_00503928();
}
