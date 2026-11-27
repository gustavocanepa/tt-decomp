/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0xA8]; virtual ~Base(); };
struct Elem : Base {
 char tail[0x44];
 Elem() __asm__("func_0047EEB8");
 virtual ~Elem();
};
struct Holder { Elem a[128]; };
extern Holder D_0058E0A0;
inline void *operator new(unsigned int,void *p) { return p; }
extern "C" void func_00481850(int init,int prio) {
 if(prio==0xFFFF) {
  if(init==1) new (&D_0058E0A0) Holder;
 }
 if(prio==0xFFFF && init==0) D_0058E0A0.~Holder();
}
