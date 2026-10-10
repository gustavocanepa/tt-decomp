extern "C" char D_0058C558[];
extern "C" char D_0058C588[];
extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_004AC9B8(void *list, void *item);

extern "C" void func_0047C698(void *item) {
    void *lock = D_0058C558;
    func_004A4D68(lock);
    func_004AC9B8(D_0058C588, item);
    func_004A4DD8(lock);
}
