/* compiler: ee-gcc2.9-991111 */
typedef struct Request {
    int type;
    int arg;
} Request;

extern void func_004DA348(void *ctx, Request *req);
extern void func_004DA3B0(void *ctx, Request *req, int arg);
extern void func_004FAAA0(int id);

int func_004DA248(void *ctx, Request *req) {
    switch (req->type) {
    case 1:
        func_004DA348(ctx, req);
        break;
    case 2:
        func_004DA3B0(ctx, req, req->arg);
        break;
    default:
        return -1;
    }
    func_004FAAA0(0);
    func_004FAAA0(2);
    return 0;
}
