/* compiler: ee-gcc2.9-991111 */
typedef struct Bits { unsigned long f0:14; unsigned long f1:2; unsigned long f2:8; unsigned long f3:8; } Bits;
typedef union HdrU { Bits b; unsigned long l; } HdrU;
struct Chan { int m0; int state; char pad[0x32C]; };
struct Buf { unsigned char value; char pad[3]; int state; };
extern struct Chan D_007869D0[];
void func_004DD5C0(int);
int func_004DD638(int);
struct Buf *func_004DD6F8(int);
int func_004DD760(int);
int func_004DEB18(int, int, int *, unsigned char *);
unsigned char func_004DD3A0(int port) {
    unsigned char value;
    int len;
    HdrU h;
    if (D_007869D0[port].state == 0) {
        if (func_004DD638(port) < 0) return 0;
    }
    if (func_004DD760(port) != 0) {
        struct Buf *buf = func_004DD6F8(port);
        if (buf->state == 0 && func_004DD638(port) < 0) goto fail;
        value = buf->value;
        goto done;
    } else {
        h.b.f0 = 12;
        h.b.f1 = 2;
        h.b.f2 = 1;
        h.b.f3 = 1;
        if (func_004DEB18(port, (int)h.l, &len, &value) >= 0) goto done;
    }
fail:
    D_007869D0[port].state = 0;
    func_004DD5C0(port);
    return 0;
done:
    return value;
}
