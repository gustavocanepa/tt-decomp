extern char D_0076A028[]; /* mutex */
extern "C" int func_0042C728(void *obj);
extern "C" void func_004A4D68(void *mutex);
extern "C" void func_004A4DD8(void *mutex);
extern "C" void func_0042C6D0(int index);

extern "C" void func_0042C7E8(void *obj) {
    int index = -1;
    if (obj)
        index = func_0042C728(obj);
    if (index >= 0) {
        func_004A4D68(D_0076A028);
        func_0042C6D0(index);
        func_004A4DD8(D_0076A028);
    }
}
