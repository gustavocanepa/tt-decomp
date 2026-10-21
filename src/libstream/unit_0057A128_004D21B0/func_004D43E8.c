/* compiler: ee-gcc2.9-991111 */
struct Module { struct Module *next; char *name; unsigned short version, attribute; int id; };
struct ErxInfo { char pad[0x18]; struct Module *modules; };
struct ErxInfo *func_004D9DD8(int);
int func_005038D8(void);
int func_00503928(void);
int func_004D43E8(int id,int flags) {
 int err=0;
 int intr;
 struct Module *m;
 if(flags & ~0x40) { flags &= 0x40; err=0x81050016; }
 intr=func_005038D8();
 for(m=func_004D9DD8(0)->modules;m;m=m->next) {
 if(id != m->id) continue;
 m->attribute |= flags;
 break;
 }
 if(intr) func_00503928();
 return m ? err : 0x8105902D;
}
