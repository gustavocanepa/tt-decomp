union Text {unsigned short* ptr;unsigned short units[2];};
struct S {char pad[20];Text text;};
extern "C" void func_00483DA8(S* s,unsigned short* dst) {
 int n=0;
 unsigned short* p=s->text.ptr;
 while(p[n])++n;
 for(int i=0;i<n;++i)dst[i]=s->text.ptr[i]&0x7f;
 dst[n]=0;
}
