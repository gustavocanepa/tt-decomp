/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct State {
    int m0;
    void *m4;
    char pad[0xD8];
} State;

extern State D_00793210;
extern int D_007932F0;
extern char D_007932F8[];
extern void *func_004F6678(void *dst, int c, unsigned int n);

State *func_00509518(void)
{
    if (D_007932F0 == 0) {
        D_007932F0 = 1;
        func_004F6678(&D_00793210, 0, sizeof(State));
        D_00793210.m4 = D_007932F8;
    }
    return &D_00793210;
}
