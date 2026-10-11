/* compiler: ee-gcc2.96-nsa-nosib */
extern char D_005A0B88[];
void func_004A4930(void *lock);
void func_004A4970(void *lock);
void func_004C89B0(void *dev, int port, int arg);

void func_004C7820(void *dev, int port, int arg) {
    int i;
    func_004A4930(D_005A0B88);
    if (port != 2) {
        func_004C89B0(dev, port, arg);
    } else {
        for (i = 0; i < 2; i++)
            func_004C89B0(dev, i, arg);
    }
    func_004A4970(D_005A0B88);
}
