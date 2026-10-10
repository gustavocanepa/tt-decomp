struct Mutex;
extern "C" Mutex D_00769FC8;
extern "C" void func_004A4D68(Mutex *m);
extern "C" void func_004A4DD8(Mutex *m);

struct Shared {
    int m0;
    int refs;
};

extern "C" Shared D_00769FF8;
extern "C" void func_0042C978(Shared *s);
extern "C" void func_0042C660(void);

extern "C" void func_0042BAF8(int id)
{
    func_004A4D68(&D_00769FC8);
    if (id == -1) {
        if (--D_00769FF8.refs == 0) {
            func_0042C978(&D_00769FF8);
            func_0042C660();
        }
    }
    func_004A4DD8(&D_00769FC8);
}
