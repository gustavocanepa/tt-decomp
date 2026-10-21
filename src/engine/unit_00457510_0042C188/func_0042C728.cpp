/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" unsigned int func_004A8368(const char *) throw();
extern "C" void func_004F8588(void *, const void *, int) throw();
extern unsigned char D_006D0E79[];
struct Entry { const char *name; int a,b; };
extern Entry D_00585E98[];
extern "C" int func_0042C728(const char *arg0) {
    char buf[64];
    func_004F8588(buf,arg0,64);
    unsigned int n = func_004A8368(buf);
    for(unsigned int i=0;i<n;i++) {
        int c = buf[i];
        if (*(unsigned char *)(0x616779+c) & 1) c += 32;
        buf[i] = c;
    }
    int result=-1;
    for (unsigned int i=0;i<10;i++) {
        if (func_004A8268(buf,D_00585E98[i].name)==0) {
            result=i;
            break;
        }
    }
    return result;
}
