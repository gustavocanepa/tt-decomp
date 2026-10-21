/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C2D50(int, void *, int, int);
extern "C" void *func_004F6678(void *, int, unsigned);
struct Block { int a, b, c, d; };
struct Request { int unused, type, index; int pad[3]; int size; Block data; };
extern "C" int func_004C13D8(char *self, Request *request) {
    int type = request->type;
    int index = request->index;
    switch (type) {
    case 2: {
        int *p = (int *)(self + index * 4);
        ++*p;
        func_004F6678((void *)(index * 16 + (int)self + 0x6c), 0, 16);
        break;
    }
    case 4: break;
    case 1: {
        int *p = (int *)(self + index * 4);
        ++*p;
        *(Block *)(self + index * 16 + 0x6c) = request->data;
        break;
    }
    case 5: {
        int *p = (int *)(self + index * 4);
        func_004C2D50(p[2], &request->data, request->size, 1);
        break;
    }
    }
    return 0;
}
