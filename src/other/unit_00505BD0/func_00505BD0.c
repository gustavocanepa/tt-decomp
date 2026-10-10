/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    unsigned int id;
    int a;
    int b;
    void *buf;
} Msg;

extern char D_00791DC8[];
extern int func_004FAC50(int, Msg *);

int func_00505BD0(unsigned short id, int a, int b) {
    Msg m;
    m.id = id;
    m.a = a;
    m.b = b;
    m.buf = (void *)((unsigned int)D_00791DC8 | 0x20000000);
    return func_004FAC50(1, &m);
}
