/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x5C];
    void (*m5C)(void);
    char pad60[8];
    void (*m68)(void);
} Handlers_0055C2A8;

extern Handlers_0055C2A8 D_0059D4A8;

void func_004C6DF0(int mask, int a, int b);
void func_004C6EB0(int mask, int a);
void func_004C6CC0(void);
void func_004C6CE0(void);
void func_004CF3C0(int n, void (*fn)(void), int arg);

void func_004C6D00(void) {
    func_004C6DF0(0x3FFF, 0, 0);
    func_004C6EB0(0x3FFF, 0);
    {
        void (*f)(void) = func_004C6CC0;
        D_0059D4A8.m68 = f;
        D_0059D4A8.m5C = f;
    }
    func_004CF3C0(1, func_004C6CE0, 0);
}
