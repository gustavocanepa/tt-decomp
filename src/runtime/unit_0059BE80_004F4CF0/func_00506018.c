/* compiler: ee-gcc2.9-991111 */
extern int D_005A4138;
struct Buf { void *addr; char name[252]; };
extern struct Buf D_00791EC0;
extern char D_00791E00[];
extern int D_00791E40;
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_00506018(const char *name, void *addr) {
 int i, r;
 if (D_005A4138 < 0) return 0;
 for (i=0; i<252 && (D_00791EC0.name[i]=name[i]); i++);
 if (i==252) { D_00791EC0.name[251]=0; i=251; }
 D_00791EC0.addr=addr;
 D_00791EC0.name[251]=0;
 r=func_004FE530(D_00791E00,3,0,&D_00791EC0,i+5,&D_00791E40,4,0,0);
 if (r<0) return -1;
 return D_00791E40;
}
