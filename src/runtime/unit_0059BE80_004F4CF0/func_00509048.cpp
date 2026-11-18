/* compiler: ee-gcc2.96-no-strict-aliasing */
/* crtbegin-style __do_global_ctors: register the EH frame table, run the constructor list in
 * reverse (the list may be -1 terminated by count, else NULL terminated), then register the
 * destructor runner with atexit. */
typedef void (*func_ptr)(void);

extern "C" {
extern char D_00619600[];
extern char D_007931F0[];
extern func_ptr D_0057866C[];
void func_0050B7C8(void *, void *);
int func_004F4D20(void (*)(void));
void func_00508FB8(void);

int func_00509048(void)
{
	func_0050B7C8(D_00619600, D_007931F0);
	{
		unsigned long nptrs = (unsigned long) D_0057866C[0];
		int i;
		if (nptrs == (unsigned long) -1)
			for (nptrs = 0; D_0057866C[nptrs + 1] != 0; nptrs++);
		for (i = nptrs; i != 0; i--)
			D_0057866C[i] ();
	}
	return func_004F4D20(func_00508FB8);
}
}
