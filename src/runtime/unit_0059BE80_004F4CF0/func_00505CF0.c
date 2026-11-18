/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    int a;
    int b;
    int c;
} Msg;
extern int func_004FAC50(int, Msg *);

int func_00505CF0(int a, int b, unsigned short c) {
    Msg m;
    m.a = a;
    m.b = b;
    m.c = c;
    return func_004FAC50(-5, &m);
}
