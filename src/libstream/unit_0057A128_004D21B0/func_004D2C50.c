/* compiler: ee-gcc2.9-991111 */
typedef struct State {
    char pad0[0xC];
    int func_005AE360;
    char pad10[8];
    unsigned int a;
    unsigned int b;
} State;

extern State D_0077A008;
extern void func_004D9D90(unsigned int *a, unsigned int *b);

int func_004D2C50(int query) {
    State *s = &D_0077A008;
    if (!s->func_005AE360)
        return 0x81058001;
    if (query)
        func_004D9D90(&s->a, &s->b);
    else {
        s->a = 0xFFFFFFFF;
        s->b = 0xFFFFFFFF;
    }
    return 0;
}
