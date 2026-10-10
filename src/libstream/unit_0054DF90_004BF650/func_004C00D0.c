/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x10];
    char lock[0x30];
    void *m40;
    char m44[0x3C];
    char m80[0x14];
    int m94;
} Conn_00552290;

void func_004A4D68(void *lock);
void func_004A4DD8(void *lock);
void func_004BF890(void *h, void *p);
void func_004BF978(void *h, void *p);

void func_004C00D0(Conn_00552290 *c) {
    func_004A4D68(c->lock);
    func_004BF890(c->m40, c->m44);
    if (c->m94 != 0) {
        func_004BF978(c->m40, c->m80);
        c->m94 = 0;
    }
    func_004A4DD8(c->lock);
}
