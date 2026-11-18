/* newlib 1.9.0: abort from libc/stdlib/abort.c, glued to abs from libc/stdlib/abs.c
 * (placed at 0x004f4cf0 / 0x005a2e80). Third-party code, see THIRD_PARTY.md for its license
 * and origin. */
extern int func_004A4490(int sig);	/* raise */
extern void func_00100220(int status) __attribute__ ((noreturn));	/* _exit */

void func_004F4CF0(void)
{
  while (1)
    {
      func_004A4490(6);	/* SIGABRT */
      func_00100220(1);
    }
}

int func_005A2E80(int i)	/* abs */
{
  return (i < 0) ? -i : i;
}
