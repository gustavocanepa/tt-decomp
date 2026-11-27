/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Context { char pad[0x18]; char *car; };
extern "C" int func_002F8A68(void *);
extern "C" int func_002F8A98(void *);
extern "C" int func_00301300(void *);
extern "C" int func_003067F0(void *);
extern "C" int func_002E9140(void *);
extern "C" int func_002D9330(void *, Context *ctx) {
    int result = 0;
    char *p = ctx->car;
    if (func_00301300(p) == 0) {
        int count = func_003067F0(p);
        if (func_002F8A68(p) && func_002F8A98(p)) {
            result = 2;
        } else {
            p += 0x824;
            int valid = 1;
            int i = 0;
            if (count > 0) {
                result = 4;
            } else {
                do {
                    if (func_002E9140(p) == 0) valid = 0;
                    p += 0x34;
                    i++;
                    if (!valid) goto done;
                } while (i < 4);
                result = 5;
            }
        }
    } else {
        result = 3;
    }
done:
    return result;
}
