/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x005971E0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Fb {
    int _flags;
    char pad[0x34];
    int _fileno;
};

extern "C" void func_004E57B0(Fb *) throw();
extern "C" long func_004E7A80(Fb *, long, int, int) throw();
extern "C" int func_004FAEE0(const char *, int, int);

extern "C" Fb *func_004E8470(Fb *self, const char *filename, int mode, int prot)
{
  if (self->_fileno >= 0)
    return 0;
  int posix_mode;
  int read_write;
  if (mode & 8)
    mode |= 2;
  if ((mode & 3) == 3) {
    posix_mode = 2;
    read_write = 0;
  }
  else if (mode & 2)
    posix_mode = 1, read_write = 4;
  else if (mode & 1)
    posix_mode = 0, read_write = 8;
  else
    posix_mode = 0, read_write = 12;
  if (mode & 0x80)
    {
      mode &= ~0x80;
    }
  if ((mode & 0x10) || mode == 2)
    posix_mode |= 0x400;
  if (mode & 8)
    posix_mode |= 8, read_write |= 0x1000;
  if (!(mode & 0x20) && mode != 1)
    posix_mode |= 0x200;
  if (mode & 0x40)
    posix_mode |= 0x800;
  int fd = func_004FAEE0(filename, posix_mode, prot);
  if (fd < 0)
    return 0;
  self->_fileno = fd;
  self->_flags = (self->_flags & ~0x100C) | (read_write & 0x100C);
  if (mode & 4) {
    if (func_004E7A80(self, 0, 2, 3) == -1)
      return 0;
  }
  func_004E57B0(self);
  return self;
}
