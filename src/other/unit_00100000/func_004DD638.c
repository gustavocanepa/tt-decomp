/* compiler: ee-gcc2.9-991111 */
struct Chan { int m0; int state; int m8; int result; char pad[0x324]; };
extern struct Chan D_007869D0[];
int func_004DE018(int port);

int func_004DD638(int port)
{
    int r; if ((r = func_004DE018(port)) < 0) return r; D_007869D0[port].result = r; D_007869D0[port].state = 1; return r;
}
