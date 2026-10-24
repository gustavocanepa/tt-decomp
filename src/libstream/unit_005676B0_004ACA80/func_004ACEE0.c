#include "types.h"

struct Pair { s32 a; s32 b; };
typedef struct Pair Pair; struct Obj { char pad[0x34]; Pair p; }; typedef struct Obj Obj;

int func_004AE9C0(Obj *); /* declared non-void: the next temporary takes $v1 */
static inline void clear(Pair *p) { p->a = 0; p->b = 0; }
void func_004ACF80(Obj *, s32);

void func_004ACEE0(Obj *self, s32 x) {
    func_004AE9C0(self);
    clear(&self->p);
    func_004ACF80(self, x);
}
