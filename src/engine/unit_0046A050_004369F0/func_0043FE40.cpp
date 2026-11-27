#include "types.h"

struct Item { s32 w[9]; };
struct Table { char pad[0x30]; Item *items; };
struct Ctx { char pad[0x6E20]; Table *t; };
extern "C" Ctx *func_0043B138(Item *);

extern "C" Ctx *func_0043FE40(s16 *id, Ctx *ctx) {
    s32 i = *id;
    if (i >= 0) {
        ctx = func_0043B138(&ctx->t->items[i]);
    }
    return ctx;
}
