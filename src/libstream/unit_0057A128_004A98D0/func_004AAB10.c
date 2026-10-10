/* compiler: ee-gcc2.96-nsa-nosib */
void func_004A98D0(void *a);
void func_004AA8A0(void *a, int b, int c);
void func_004AABA8(void *a);

void func_004AAB10(void *a, int b, int c, int flag)
{
    func_004A98D0(a);
    func_004AA8A0(a, b, c);
    if (flag == 0)
        func_004AABA8(a);
}
