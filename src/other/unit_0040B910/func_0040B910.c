/* Splits a packed 64-bit pair (low word, high word) into two arguments for func_0040B940. */
typedef int s32;
typedef long s64;

void func_0040B940(void *arg0, s32 lo, s32 hi, s32 arg3);

void func_0040B910(void *arg0, s64 pair, s32 arg2)
{
    func_0040B940(arg0, (s32)(pair & 0xFFFFFFFF), (s32)(pair >> 32), arg2);
}
