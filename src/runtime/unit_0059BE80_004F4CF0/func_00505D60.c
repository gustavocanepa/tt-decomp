/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    int a;
    int b;
} Msg;
extern int func_004FAC50(int, Msg *);

int func_00505D60(int a, char b) {
    Msg m;
    m.a = a;
    m.b = b;
    return func_004FAC50(-7, &m);
}
