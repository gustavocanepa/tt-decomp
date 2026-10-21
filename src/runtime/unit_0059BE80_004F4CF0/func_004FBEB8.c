/* compiler: ee-gcc2.9-991111 */
struct Node { int x; volatile int count; unsigned char *bytes; };
struct Tty { char pad[24]; struct Node *node; };
extern struct Tty D_0078BE50;
extern void func_004FBB68(struct Node *);
int func_004FBEB8(char *buf, int size) {
    int i = 0;
    while (i < size) {
        char *out = buf + i;
        int next = i + 1;
        while (D_0078BE50.node->count == 0) { }
        *out = *D_0078BE50.node->bytes;
        func_004FBB68(D_0078BE50.node);
        if (*out == 10 || *out == 13) return next;
        i = next;
    }
    return i;
}
