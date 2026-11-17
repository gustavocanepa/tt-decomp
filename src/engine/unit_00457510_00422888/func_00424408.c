/* Converts a2 and forwards it with a0 and a1 to func_00424450, returning a0. Not the original
   form: a dead flag computed from a0 || a2 and the same local reused for a2 (a permuter find) give
   a0 the first saved register as in retail; every plain one-call version swaps $s0/$s1. */
typedef int s32;
s32 func_00423F60(s32);
void func_00424450(s32, s32, s32);

s32 func_00424408(s32 a0, s32 a1, s32 a2)
{
    s32 t;
    if (a0 || a2)
        t = 1;
    else
        t = 1;
    if (t) {
        t = a2;
        func_00424450(a0, a1, func_00423F60(t));
    }
    return a0;
}
