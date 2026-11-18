#include "types.h"

typedef struct Self { char *vtbl; s32 m4; s32 m8; char *mC; char m10[4]; } Self;
extern char D_005DA498[];
extern char D_0076FC88[];
void func_0047C268(void *);

void func_0047BE70(Self *self) {
    self->vtbl = D_005DA498;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = D_0076FC88;
    func_0047C268(self->m10);
}
