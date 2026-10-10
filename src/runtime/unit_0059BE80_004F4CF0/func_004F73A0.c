/* newlib 1.9.0 libc/stdlib/rand.c: rand(), compiled with strict aliasing (unlike most of newlib):
   the D_005A30A8 load is kept across the store. The file has no notice of its own
   (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    char pad[0xA8];
    unsigned long long _rand_next; /* _new._reent._rand_next */
};

extern struct _reent *D_005A30A8; /* D_005A30A8 */
#define _REENT D_005A30A8
#define RAND_MAX 0x7fffffff

int func_004F73A0(void)
{
    /* This multiplier was obtained from Knuth, D.E., "The Art of
       Computer Programming," Vol 2, Seminumerical Algorithms, Third
       Edition, Addison-Wesley, 1998, p. 106 (line 26) & p. 108 */
    _REENT->_rand_next =
        _REENT->_rand_next * __extension__ 6364136223846793005LL + 1;
    return (int)((_REENT->_rand_next >> 32) & RAND_MAX);
}
