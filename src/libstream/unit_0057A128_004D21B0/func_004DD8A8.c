/* compiler: ee-gcc2.9-991111 */
struct Req {
    unsigned long long a : 14;
    unsigned long long b : 2;
    unsigned long long c : 8;
    unsigned long long d : 8;
};
extern int func_004DEB18(int, struct Req, int *, int);
int func_004DD8A8(int dev, int arg) {
    struct Req req;
    int out;
    int r;
    req.a = 2;
    req.b = 2;
    req.c = 3;
    req.d = 1;
    r = func_004DEB18(dev, req, &out, arg);
    if (r < 0) return r;
    return out;
}
