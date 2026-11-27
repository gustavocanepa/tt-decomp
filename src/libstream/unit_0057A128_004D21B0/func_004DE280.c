/* compiler: ee-gcc2.9-991111 */
struct Packet { int socket; int result; char pad[0x88]; };
extern struct Packet D_00789E40;
extern char D_00789D40[];
extern int D_0078A600;
void func_004DEC40(char *, ...);
void func_004FA840(int);
int func_004FA860(int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);
int func_004DE280(int socket) {
    struct Packet *p;
    int r;
    func_004FA860(D_0078A600);
    p = &D_00789E40;
    p->socket = socket;
    if (func_004FE530(D_00789D40, 0x80001315, 0, p, 0x90, p, 0x90, 0, 0) < 0) {
        func_004DEC40("sceDbcInitSocket: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    r = p->result;
    func_004FA840(D_0078A600);
    return r;
}
