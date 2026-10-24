/* compiler: ee-gcc2.9-991111 */
/* Synchronous shared-buffer RPC: serialize request/result access and report
 * a diagnostic on transport failure. Names are provisional layout views. */
struct Client { char unknown0[0x28]; };
struct Packet { int argument, result; char unknown8[0x88]; };
extern int D_005A0D50, D_0078A600;
extern struct Client D_00789D40;
extern struct Packet D_00789E40;
extern const char D_00614950[];
extern int func_004FA860(int);
extern int func_004FA840(int);
extern int func_004DEC40(const char *);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DDF58(int argument) {
    int result;
    if(!D_005A0D50) return 0;
    func_004FA860(D_0078A600);
    D_00789E40.argument=argument;
    if(func_004FE530(&D_00789D40,0x80001302,0,&D_00789E40,0x90,
        &D_00789E40,0x90,0,0)<0) {
        func_004DEC40(D_00614950);
        func_004FA840(D_0078A600);
        return 0;
    }
    result=D_00789E40.result;
    func_004FA840(D_0078A600);
    return result;
}
