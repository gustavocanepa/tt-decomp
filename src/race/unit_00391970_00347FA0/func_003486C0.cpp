/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0x1C]; virtual ~Base(); };
struct Mic : Base {
 char tail[0xC];
 Mic() __asm__("func_0034F448");
 virtual ~Mic();
};
struct Holder { Mic a[3]; };
extern Holder D_00583F38;
inline void *operator new(unsigned int,void *p) { return p; }
extern "C" void func_003486C0(int init,int prio) {
 if(prio==0xFFFF) {
  if(init==1) new (&D_00583F38) Holder;
 }
 if(prio==0xFFFF && init==0) D_00583F38.~Holder();
}
