/* compiler: ee-gcc2.9-991111 */
/* Operation 13 carries a string and a buffer of 64-byte records. A negative
 * record count skips cache writeback, preserving the original request mode. */
struct Client { char unknown0[0x24]; void *server; };
struct Metadata { int words[16]; };
struct Command {
    int argument0, argument1, argument2, record_count;
    struct Metadata *records;
    char text[1024];
};
extern struct Client D_00782AC0;
extern struct Command D_00782B70;
extern int D_005A0BF4, D_005A0BF0, D_00784080;
extern int func_004FA870(int);
extern int func_004FA840(int);
extern char *func_004F8588(char *, const char *, unsigned);
extern void func_004FDAF8(void *, int);
extern void func_004DB328(void *);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_004DBE08(int argument0, int argument1, const char *text,
                 int argument2, int record_count, struct Metadata *records) {
    if(!D_00782AC0.server) return -100;
    if(func_004FA870(D_005A0BF4)<0) return -200;
    if(!text || !*text) {func_004FA840(D_005A0BF4);return -210;}
    D_00782B70.argument0=argument0;
    D_00782B70.argument1=argument1;
    D_00782B70.argument2=argument2;
    D_00782B70.record_count=record_count;
    D_00782B70.records=records;
    func_004F8588(D_00782B70.text,text,1023);
    D_00782B70.text[1023]=0;
    if(record_count>=0) func_004FDAF8(records,record_count*sizeof(*records));
    if(func_004FE530(&D_00782AC0,13,1,&D_00782B70,0x414,&D_00784080,4,
        func_004DB328,0)) {func_004FA840(D_005A0BF4);return -91;}
    D_005A0BF0=13;
    return 0;
}
