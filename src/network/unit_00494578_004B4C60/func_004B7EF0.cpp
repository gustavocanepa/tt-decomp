/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pad { char pad[0x49C]; int busy; };
extern "C" Pad *D_0059834C;
extern "C" int D_00598350;
extern "C" void func_004B7A28(int,int,int,int,int,int,int,int) throw();
extern "C" void func_004B7EF0(void) {
    Pad *p=D_0059834C;
    if (p != 0) {
        if (p->busy == 0) {
            int *count=&D_00598350;
            int n=*count+1;
            *count=n;
            if(n>=5) {
                *count=0;
                func_004B7A28(1,0,0,0,0,0,0,0);
            }
        }
    }
}
