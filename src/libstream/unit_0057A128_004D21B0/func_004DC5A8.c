/* compiler: ee-gcc2.9-991111 */
/* Submit operation 14 with flag 16 and two string fields; completion is tagged
 * as pending operation 19. The metadata prefix is deliberately left intact. */
struct Client { char unknown0[0x24]; void *server; };
struct Metadata { char unknown0[32]; char text[32]; };
struct Command { int argument0, argument1, flags, unknownC; struct Metadata *metadata; char text[1024]; };
extern struct Client D_00782AC0;
extern struct Metadata D_00782B00;
extern struct Command D_00782B70;
extern int D_005A0BF4, D_005A0BF0, D_00784080;
extern int func_004FA870(int);
extern int func_004FA840(int);
extern void func_004FAAA0(int);
extern void func_004DB328(void *);
extern char *func_004F8588(char *, const char *, unsigned);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DC5A8(int argument0, int argument1, const char *text, const char *metadata_text) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    if(!text || !*text || !metadata_text) {func_004FA840(D_005A0BF4);return -210;}
    D_00782B70.argument0=argument0;
    D_00782B70.argument1=argument1;
    D_00782B70.flags=16;
    func_004F8588(D_00782B70.text,text,1023);
    D_00782B70.text[1023]=0;
    func_004F8588(D_00782B00.text,metadata_text,32);
    D_00782B70.metadata=&D_00782B00;
    func_004FAAA0(0);
    if(func_004FE530(&D_00782AC0,14,1,&D_00782B70,0x414,&D_00784080,4,
        func_004DB328,0)) {func_004FA840(D_005A0BF4);return -91;}
    D_005A0BF0=19;
    return 0;
}
