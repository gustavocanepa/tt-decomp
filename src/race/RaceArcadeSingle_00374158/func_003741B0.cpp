/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char p[0x70]; void *race; };
struct Obj { char p[0x6c]; Info *info; char q[0xE2C-0x70]; int mode; };
extern "C" int RaceBase__getLicenseSubNumber(int);
extern "C" int func_0040EE28(void *);
extern "C" int func_003741B0(Obj *o, int *p) {
 *p=-1;
 *p=RaceBase__getLicenseSubNumber(func_0040EE28(o->info->race));
 return o->mode;
}
