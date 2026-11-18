struct Elem { char bytes[48]; };
struct S { long mask;Elem elems[10];int words[16];unsigned char bytes[8];unsigned char flag; };
extern "C" void func_003F9A50(Elem *);
extern "C" void func_003F9B40(S *s) { s->mask=-1;for(int i=0;i<10;i++)func_003F9A50(&s->elems[i]);char *base=(char*)s->elems;int value=0x157529FF;for(int i=15;i>=0;i--)((int*)(base+0x1E0))[i]=value;for(int i=7;i>=0;i--)base[0x220+i]=0;s->flag=0; }
