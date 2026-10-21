/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0046E9C8(int) throw();
extern "C" void func_0046E9F8(int) throw();
extern "C" int func_0046EA28(int) throw();
extern "C" void func_0046EC00(int,void *,int) throw();
extern "C" int func_004729C0(void *,int *,int,int,int,int) throw();
extern "C" void func_004FAAA0(int);
extern "C" void func_00472DC8(unsigned int a, int b, int c, int d, int e, int f, int g, void *data) {
 struct Packet { char buf[0x60]; int desc; char pad[0xc]; } p;
 p.desc = ((a >> 6) & 0xffff) | (((c >> 6) & 0xff) << 16) | (b << 24);
 int n = func_004729C0(&p,&p.desc,d,e,f,g);
 if (n) {
  __asm__ volatile("sync" ::: "memory");
  func_004FAAA0(0);
  func_0046E9C8(2);
  func_0046EC00(2,&p,6);
  func_0046EC00(2,data,n);
  func_0046EA28(2);
  func_0046E9F8(2);
 }
}
