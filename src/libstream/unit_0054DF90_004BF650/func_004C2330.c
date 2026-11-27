/* compiler: ee-gcc2.96-no-strict-aliasing */
void func_004F4348(int);
void func_00575DA0(void *);
int func_004F43A8(void *, void *);
void func_004F43F0(void *, void *);
void func_004F45D8(void *, int, int, void *, int);

struct Request {
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    int arg5;
};

struct Client {
    int sema;
    char pad4[0x38];
    struct Request *request;
};

int func_004C2330(struct Client *client, int arg1, int arg2, int arg3, void *arg4, void *arg5, int arg6) {
    if (arg6 != 0) {
        func_004F43F0(arg4, arg5);
    } else {
        func_004F43A8(arg4, arg5);
    }
    func_004F4348(client->sema);
    client->request->arg0 = arg1;
    client->request->arg1 = arg2;
    client->request->arg2 = arg3;
    client->request->arg3 = arg4;
    client->request->arg4 = arg5;
    client->request->arg5 = (int) (arg6 != 0);
    func_004F45D8(client, 4, 0, client->request, 0x40);
    return client->request->arg2;
}
