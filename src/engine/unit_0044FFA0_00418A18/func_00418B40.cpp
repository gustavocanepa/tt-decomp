/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;
struct Table { char pad[10]; unsigned short stride; char padC[4]; char data[1]; };
extern "C" Table *func_00418AB8(void **, int) throw();
extern "C" int func_00418BF0(Table *, u64);
extern "C" void *func_00418B40(void **arg0, int arg1, u64 arg2) {
    int index = func_00418BF0(func_00418AB8(arg0, arg1), arg2);
    if (index == -1) return 0;
    Table *table = func_00418AB8(arg0, arg1);
    char *data = table->data;
    return data + table->stride * index;
}
