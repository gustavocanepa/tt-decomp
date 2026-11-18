/* compiler: ee-gcc2.9-991111 */
/* Operation 15 carries two arguments and a terminated 1024-byte string.
 * Submission retains the lock for later completion handling; all failures
 * after acquiring it release it. Semantic argument names remain unknown. */
struct Client { char unknown0[0x24]; void *server; };
struct Command { int argument0, argument1, argument2; char unknownC[8]; char text[1024]; };
extern struct Client D_00782AC0;
extern struct Command D_00782B70;
extern int D_005A0BF4, D_005A0BF0, D_00784080;
extern void func_004DB328(void *);
extern int func_004FA870(int);
extern int func_004FA840(int);
extern char *func_004F8588(char *, const char *, unsigned);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DC1F8(int argument0, int argument1, const char *text) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    if(!text || !*text) {func_004FA840(D_005A0BF4);return -210;}
    func_004F8588(D_00782B70.text,text,1023);
    D_00782B70.argument0=argument0;
    D_00782B70.argument1=argument1;
    D_00782B70.text[1023]=0;
    D_00782B70.argument2=0;
    if(func_004FE530(&D_00782AC0,15,1,&D_00782B70,0x414,
        &D_00784080,4,func_004DB328,0)) {
        func_004FA840(D_005A0BF4);
        return -91;
    }
    D_005A0BF0=15;
    return 0;
}
