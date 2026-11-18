/* compiler: ee-gcc2.96-nsa-g */
/* double -> unsigned conversion helper (libgcc soft-float): values >= 2^63 are biased down first. */
unsigned int func_00508ED0(double d)
{
	if (d >= 9223372036854775808.0)
		return (int)(d + -9223372036854775808.0);
	return (int)d;
}
