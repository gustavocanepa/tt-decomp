/* gcc-rtti gcc snapshot 2000-10-03 (old C++ ABI): __class_type_info::do_dyncast() (__class_type_info__virtual_02) from tinfo.cc, placed at 0x0050cea0 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
// Methods for type_info for -*- C++ -*- Run Time Type Identification.
// Copyright (C) 1994, 1996, 1998, 1999, 2000 Free Software Foundation

// This file is part of GNU CC.

// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.

// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#pragma implementation "typeinfo"

#ifndef GT4_RUNTIME_STDDEF
#define GT4_RUNTIME_STDDEF
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL 0
#endif

// RTTI support internals for -*- C++ -*-
// Copyright (C) 1994, 1995, 1996, 1998, 1999, 2000 Free Software Foundation

// RTTI support for -*- C++ -*-
// Copyright (C) 1994, 1995, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// __GXX_ABI_VERSION distinguishes the ABI that is being used. Values <100
// indicate the `old' abi, which grew as C++ was defined. Values >=100
// indicate the `new' abi, which is a cross vendor C++ abi, documented at
// `http://reality.sgi.com/dehnert_engr/cxx/'.

#ifndef __TYPEINFO__
#define __TYPEINFO__

#pragma interface "typeinfo"

// Exception Handling support header for -*- C++ -*-
// Copyright (C) 1995, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef __EXCEPTION__
#define __EXCEPTION__

#pragma interface "exception"

extern "C++" {

namespace std {

class exception {
public:
  exception () { }
  virtual ~exception () { }
  virtual const char* what () const;
};

class bad_exception : public exception {
public:
  bad_exception () { }
  virtual ~bad_exception () { }
};

typedef void (*terminate_handler) ();
typedef void (*unexpected_handler) ();

terminate_handler set_terminate (terminate_handler);
void terminate () __attribute__ ((__noreturn__));
unexpected_handler set_unexpected (unexpected_handler);
void unexpected () __attribute__ ((__noreturn__));
bool uncaught_exception ();

}

}

#endif

extern "C++" {

#if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100
namespace __cxxabiv1
{
  class __class_type_info;
}
#endif

namespace std {

class type_info {
public:

  virtual ~type_info ();

private:

  type_info& operator= (const type_info&);
  type_info (const type_info&);

protected:
  const char *__name;

protected:
  explicit type_info (const char *__n): __name (__n) { }

public:

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

  bool before (const type_info& arg) const;
  const char* name () const
    { return __name; }
  bool operator== (const type_info& __arg) const throw();
  bool operator!= (const type_info& __arg) const
    { return !operator== (__arg); }

#else

  bool before (const type_info& __arg) const
    { return __name < __arg.__name; }
  const char* name () const
    { return __name; }
  bool operator== (const type_info& __arg) const
    { return __name == __arg.__name; }
  bool operator!= (const type_info& __arg) const
    { return !operator== (__arg); }
#endif

#if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100
public:

  virtual bool __is_pointer_p () const;

  virtual bool __is_function_p () const;

  virtual bool __do_catch (const type_info *__thr_type, void **__thr_obj,
                         unsigned __outer) const;

  virtual bool __do_upcast (const __cxxabiv1::__class_type_info *__target,
			    void **__obj_ptr) const;
#endif
};

class bad_cast : public exception {
public:
  bad_cast() { }
  virtual ~bad_cast() { }
};

class bad_typeid : public exception {
 public:
  bad_typeid () { }
  virtual ~bad_typeid () { }
};

}

}
#endif

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

struct __user_type_info : public std::type_info {
  __user_type_info (const char *n) : type_info (n) {}

  int upcast (const type_info &target, void *obj, void **res) const;

  void *dyncast (int boff,
                 const type_info &target, void *obj,
                 const type_info &subtype, void *subobj) const;

  static const type_info *const nonvirtual_base_type
      = static_cast <const type_info *> (0) + 1;

  enum sub_kind
  {
    unknown = 0,
    not_contained,

    contained_ambig,
    contained_mask = 4,
    contained_virtual_mask = 1,
    contained_public_mask = 2,
    contained_private = contained_mask,
    contained_public = contained_mask | contained_public_mask
  };

  static inline bool contained_p (sub_kind access_path)
  {
    return access_path >= contained_mask;
  }
  static inline bool contained_public_p (sub_kind access_path)
  {
    return access_path >= contained_public;
  }
  static inline bool contained_nonpublic_p (sub_kind access_path)
  {
    return (access_path & contained_public) == contained_mask;
  }
  static inline bool contained_nonvirtual_p (sub_kind access_path)
  {
    return (access_path & (contained_mask | contained_virtual_mask))
           == contained_mask;
  }
  static inline bool contained_virtual_p (sub_kind access_path)
  {
    return (access_path & (contained_mask | contained_virtual_mask))
           == (contained_mask | contained_virtual_mask);
  }

  struct upcast_result
  {
    void *target_obj;
    sub_kind whole2target;
    const type_info *base_type;

    public:
    upcast_result ()
      :target_obj (NULL), whole2target (unknown), base_type (NULL)
      {}
  };
  struct dyncast_result
  {
    void *target_obj;
    sub_kind whole2target;
    sub_kind whole2sub;
    sub_kind target2sub;

    public:
    dyncast_result ()
      :target_obj (NULL), whole2target (unknown),
       whole2sub (unknown), target2sub (unknown)
      {}
  };

  public:

  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;

  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  public:

  sub_kind find_public_subobj (int boff, const type_info &subtype,
                               void *objptr, void *subptr) const
  {
    if (boff >= 0)
      return ((char *)subptr - (char *)objptr) == boff
              ? contained_public : not_contained;
    if (boff == -2)
      return not_contained;
    return do_find_public_subobj (boff, subtype, objptr, subptr);
  }

  public:

  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};

class __si_type_info : public __user_type_info {
  const __user_type_info &base;

public:
  __si_type_info (const char *n, const __user_type_info &b)
    : __user_type_info (n), base (b) { }

  private:
  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;
  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};

#define BITS_PER_UNIT 8

#if BITS_PER_UNIT == 8
typedef int myint32 __attribute__ ((mode (SI)));
#elif BITS_PER_UNIT == 16
typedef int myint32 __attribute__ ((mode (HI)));
#elif BITS_PER_UNIT == 32
typedef int myint32 __attribute__ ((mode (QI)));
#endif

struct __class_type_info : public __user_type_info {
  enum access { PUBLIC = 1, PROTECTED = 2, PRIVATE = 3 };

  struct base_info {
    const __user_type_info *base;
    myint32 offset: 29;
    bool is_virtual: 1;
    enum access access: 2;
  };

  const base_info *base_list;
  size_t n_bases;

  __class_type_info (const char *name, const base_info *bl, size_t bn)
    : __user_type_info (name), base_list (bl), n_bases (bn) {}

  public:
  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;
  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};
#else

/* new abi support -*- C++ -*-
   Copyright (C) 2000
   Free Software Foundation, Inc.
   Written by Nathan Sidwell, Codesourcery LLC, <nathan@codesourcery.com>  */

#ifndef __CXXABI_H
#define __CXXABI_H 1

#if defined(__cplusplus) && (!defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100)

#error "Not targetting the new abi, supply -fnew-abi"
#endif

#ifdef __cplusplus

namespace __cxxabiv1
{

class __fundamental_type_info
  : public std::type_info
{
public:
  virtual ~__fundamental_type_info ();
public:
  explicit __fundamental_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __array_type_info
  : public std::type_info
{

protected:
  virtual ~__array_type_info ();
public:
  explicit __array_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __function_type_info
  : public std::type_info
{

public:
  virtual ~__function_type_info ();
public:
  explicit __function_type_info (const char *__n)
    : std::type_info (__n)
    { }

protected:
  virtual bool __is_function_p () const;
};

class __enum_type_info
  : public std::type_info
{

public:
  virtual ~__enum_type_info ();
public:
  explicit __enum_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __pbase_type_info
  : public std::type_info
{

public:
  unsigned int __qualifier_flags;
  const std::type_info *__pointee;

public:
  virtual ~__pbase_type_info ();
public:
  explicit __pbase_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : std::type_info (__n), __qualifier_flags (__quals), __pointee (__type)
    { }

public:
  enum __qualifier_masks {
    __const_mask = 0x1,
    __volatile_mask = 0x2,
    __restrict_mask = 0x4,
    __incomplete_mask = 0x8,
    __incomplete_class_mask = 0x10
  };

protected:
  virtual bool __do_catch (const std::type_info *__thr_type,
                           void **__thr_obj,
                           unsigned __outer) const;
protected:
  inline virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                       void **__thr_obj,
                                       unsigned __outer) const;
};

class __pointer_type_info
  : public __pbase_type_info
{

public:
  virtual ~__pointer_type_info ();
public:
  explicit __pointer_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : __pbase_type_info (__n, __quals, __type)
    { }

protected:
  virtual bool __is_pointer_p () const;

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __pointer_to_member_type_info
  : public __pbase_type_info
{

public:
  __class_type_info *__context_class;

public:
  virtual ~__pointer_to_member_type_info ();
public:
  explicit __pointer_to_member_type_info (const char *__n,
                                          int __quals,
                                          const std::type_info *__type,
                                          __class_type_info *__klass)
    : __pbase_type_info (__n, __quals, __type), __context_class (__klass)
    { }

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __class_type_info;

class __base_class_info
{

public:
  const __class_type_info *__base;
  long __offset_flags;

public:
  enum __offset_flags_masks {
    __virtual_mask = 0x1,
    __public_mask = 0x2,
    hwm_bit = 2,
    offset_shift = 8
  };

public:
  bool __is_virtual_p () const
    { return __offset_flags & __virtual_mask; }
  bool __is_public_p () const
    { return __offset_flags & __public_mask; }
  __PTRDIFF_TYPE__ __offset () const
    {

      return static_cast<__PTRDIFF_TYPE__> (__offset_flags) >> offset_shift;
    }
};

class __class_type_info
  : public std::type_info
{

public:
  virtual ~__class_type_info ();
public:
  explicit __class_type_info (const char *__n)
    : type_info (__n)
    { }

public:

  enum __sub_kind
  {
    __unknown = 0,
    __not_contained,

    __contained_ambig,

    __contained_virtual_mask = __base_class_info::__virtual_mask,
    __contained_public_mask = __base_class_info::__public_mask,
    __contained_mask = 1 << __base_class_info::hwm_bit,

    __contained_private = __contained_mask,
    __contained_public = __contained_mask | __contained_public_mask
  };

public:
  struct __upcast_result;
  struct __dyncast_result;

protected:
  virtual bool __do_upcast (const __class_type_info *__dst_type, void **__obj_ptr) const;

protected:
  virtual bool __do_catch (const type_info *__thr_type, void **__thr_obj,
                           unsigned __outer) const;

public:

  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;

public:

  inline __sub_kind __find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                       const void *__obj_ptr,
                                       const __class_type_info *__src_type,
                                       const void *__src_ptr) const;

public:

  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
public:

  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
};

class __si_class_type_info
  : public __class_type_info
{

public:
  const __class_type_info *__base_type;

public:
  virtual ~__si_class_type_info ();
public:
  explicit __si_class_type_info (const char *__n,
                                 const __class_type_info *__base)
    : __class_type_info (__n), __base_type (__base)
    { }

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__sub_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

class __vmi_class_type_info : public __class_type_info {

public:
  unsigned int __flags;
  unsigned int __base_count;
  __base_class_info const __base_info[1];

public:
  virtual ~__vmi_class_type_info ();
public:
  explicit __vmi_class_type_info (const char *__n,
                                  int ___flags)
    : __class_type_info (__n), __flags (___flags), __base_count (0)
    { }

public:
  enum __flags_masks {
    __non_diamond_repeat_mask = 0x1,
    __diamond_shaped_mask = 0x2,
    non_public_base_mask = 0x4,
    public_base_mask = 0x8,

    __flags_unknown_mask = 0x10
  };

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

extern "C"
void *func_005C0F40 (const void *__src_ptr,
                      const __class_type_info *__src_type,
                      const __class_type_info *__dst_type,
                      __PTRDIFF_TYPE__ __src2dst);

extern "C"
void *__cxa_vec_new (__SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     __SIZE_TYPE__ __padding_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void *__cxa_vec_new2 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *));

extern "C"
void *__cxa_vec_new3 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
void __cxa_vec_ctor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_cctor (void *dest_array,
		      void *src_array,
		      __SIZE_TYPE__ element_count,
		      __SIZE_TYPE__ element_size,
		      void (*constructor) (void *, void *),
		      void (*destructor) (void *));

extern "C"
void __cxa_vec_dtor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete (void *__array_address,
                       __SIZE_TYPE__ __element_size,
                       __SIZE_TYPE__ __padding_size,
                       void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete2 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *));

extern "C"
void __cxa_vec_delete3 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
char *__cxa_demangle (const char *__mangled_name,
		      char *__output_buffer,
		      __SIZE_TYPE__ *__length,
		      int *__status);

}

namespace abi = __cxxabiv1;

#else
#endif

#endif

#endif

// The -*- C++ -*- dynamic memory management header.
// Copyright (C) 1994, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef __NEW__
#define __NEW__

#pragma interface "new"

extern "C++" {

namespace std {

  class bad_alloc : public exception {
  public:
    virtual const char* what() const throw() { return "bad_alloc"; }
  };

  struct nothrow_t {};
  extern const nothrow_t nothrow;
  typedef void (*new_handler)();
  new_handler set_new_handler (new_handler);

}

void *operator new (size_t) throw (std::bad_alloc);
void *operator new[] (size_t) throw (std::bad_alloc);
void operator delete (void *) throw();
void operator delete[] (void *) throw();
void *operator new (size_t, const std::nothrow_t&) throw();
void *operator new[] (size_t, const std::nothrow_t&) throw();
void operator delete (void *, const std::nothrow_t&) throw();
void operator delete[] (void *, const std::nothrow_t&) throw();

inline void *operator new(size_t, void *place) throw() { return place; }
inline void *operator new[](size_t, void *place) throw() { return place; }
}

#endif

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

namespace
{

inline void*
convert_to_base (void *addr, bool is_virtual, myint32 offset)
{
  if (!addr)
    return NULL;

  if (!is_virtual)
    return (char *) addr + offset;

  return *((void **) ((char *) addr + offset));
}

}

extern "C" void
func_005BFB88 (void *addr, const char *name);

bool __class_type_info::
do_dyncast (int boff, sub_kind access_path,
            const type_info &target, void *objptr,
            const type_info &subtype, void *subptr,
            dyncast_result &__restrict result) const

{
  if (objptr == subptr && *this == subtype)
    {

      result.whole2sub = access_path;
      return false;
    }
  if (*this == target)
    {
      result.target_obj = objptr;
      result.whole2target = access_path;
      if (boff >= 0)
        result.target2sub = ((char *)subptr - (char *)objptr) == boff
              ? contained_public : not_contained;
      else if (boff == -2)
        result.target2sub = not_contained;
      return false;
    }
  bool result_ambig = false;
  for (size_t i = n_bases; i--;)
    {
      dyncast_result result2;
      void *p;
      sub_kind sub_access = access_path;
      p = convert_to_base (objptr,
			   base_list[i].is_virtual,
			   base_list[i].offset);
      if (base_list[i].is_virtual)
	sub_access = sub_kind (sub_access | contained_virtual_mask);
      if (base_list[i].access != PUBLIC)
        sub_access = sub_kind (sub_access & ~contained_public_mask);

      bool result2_ambig
          = base_list[i].base->do_dyncast (boff, sub_access,
                                           target, p, subtype, subptr, result2);
      result.whole2sub = sub_kind (result.whole2sub | result2.whole2sub);
      if (result2.target2sub == contained_public
          || result2.target2sub == contained_ambig)
        {
          result.target_obj = result2.target_obj;
          result.whole2target = result2.whole2target;
          result.target2sub = result2.target2sub;

          return result2_ambig;
        }

      if (!result_ambig && !result.target_obj)
        {

          result.target_obj = result2.target_obj;
          result.whole2target = result2.whole2target;
          result_ambig = result2_ambig;
        }
      else if (result.target_obj && result.target_obj == result2.target_obj)
        {

          result.whole2target =
              sub_kind (result.whole2target | result2.whole2target);
        }
      else if ((result.target_obj && result2.target_obj)
               || (result_ambig && result2.target_obj)
               || (result2_ambig && result.target_obj))
        {

          sub_kind new_sub_kind = result2.target2sub;
          sub_kind old_sub_kind = result.target2sub;

          if (contained_nonvirtual_p (result.whole2sub))
            {

              if (old_sub_kind == unknown)
                old_sub_kind = not_contained;
              if (new_sub_kind == unknown)
                new_sub_kind = not_contained;
            }
          else
            {
              const __user_type_info &t =
                  static_cast <const __user_type_info &> (target);

              if (old_sub_kind >= not_contained)
                ;
              else if (contained_nonvirtual_p (new_sub_kind))

                old_sub_kind = not_contained;
              else
                old_sub_kind = t.find_public_subobj (boff, subtype,
                                                     result.target_obj, subptr);

              if (new_sub_kind >= not_contained)
                ;
              else if (contained_nonvirtual_p (old_sub_kind))

                new_sub_kind = not_contained;
              else
                new_sub_kind = t.find_public_subobj (boff, subtype,
                                                     result2.target_obj, subptr);
            }

          if (contained_p (sub_kind (new_sub_kind ^ old_sub_kind)))
            {

              if (contained_p (new_sub_kind))
                {

                  result.target_obj = result2.target_obj;
                  result.whole2target = result2.whole2target;
                  result_ambig = false;
                  old_sub_kind = new_sub_kind;
                }
              result.target2sub = old_sub_kind;
              if (result.target2sub == contained_public)
                return false;
            }
          else if (contained_p (sub_kind (new_sub_kind & old_sub_kind)))
            {

              result.target_obj = NULL;
              result.target2sub = contained_ambig;
              return true;
            }
          else
            {

              result.target_obj = NULL;
              result.target2sub = not_contained;
              result_ambig = true;
            }
        }

      if (result.whole2sub == contained_private)

        return result_ambig;
    }

  return result_ambig;
}

#else

namespace std {

};

namespace {

using namespace std;
using namespace abi;

struct vtable_prefix {
  ptrdiff_t whole_object;
  const __class_type_info *whole_type;
  const void *origin;
};

template <typename T>
inline const T *
adjust_pointer (const void *base, ptrdiff_t offset)
{
  return reinterpret_cast <const T *>
    (reinterpret_cast <const char *> (base) + offset);
}

inline void const *
convert_to_base (void const *addr, bool is_virtual, ptrdiff_t offset)
{
  if (is_virtual)
    {
      const void *vtable = *static_cast <const void *const *> (addr);

      offset = *adjust_pointer<ptrdiff_t> (vtable, offset);
    }

  return adjust_pointer<void> (addr, offset);
}

inline bool contained_p (__class_type_info::__sub_kind access_path)
{
  return access_path >= __class_type_info::__contained_mask;
}
inline bool public_p (__class_type_info::__sub_kind access_path)
{
  return access_path & __class_type_info::__contained_public_mask;
}
inline bool virtual_p (__class_type_info::__sub_kind access_path)
{
  return (access_path & __class_type_info::__contained_virtual_mask);
}
inline bool contained_public_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & __class_type_info::__contained_public)
          == __class_type_info::__contained_public);
}
inline bool contained_nonpublic_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & __class_type_info::__contained_public)
          == __class_type_info::__contained_mask);
}
inline bool contained_nonvirtual_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & (__class_type_info::__contained_mask
                          | __class_type_info::__contained_virtual_mask))
          == __class_type_info::__contained_mask);
}

static const __class_type_info *const nonvirtual_base_type =
    static_cast <const __class_type_info *> (0) + 1;

};

namespace __cxxabiv1
{

struct __class_type_info::__upcast_result
{
  const void *dst_ptr;
  __sub_kind part2dst;
  int src_details;
  const __class_type_info *base_type;

  public:
  __upcast_result (int d)
    :dst_ptr (NULL), part2dst (__unknown), src_details (d), base_type (NULL)
    {}
};

struct __class_type_info::__dyncast_result
{
  const void *dst_ptr;
  __sub_kind whole2dst;
  __sub_kind whole2src;
  __sub_kind dst2src;
  int whole_details;

  public:
  __dyncast_result (int details_ = __vmi_class_type_info::__flags_unknown_mask)
    :dst_ptr (NULL), whole2dst (__unknown),
     whole2src (__unknown), dst2src (__unknown),
     whole_details (details_)
    {}
};

inline __class_type_info::__sub_kind __class_type_info::
__find_public_src (ptrdiff_t src2dst,
                   const void *obj_ptr,
                   const __class_type_info *src_type,
                   const void *src_ptr) const
{
  if (src2dst >= 0)
    return adjust_pointer <void> (obj_ptr, src2dst) == src_ptr
            ? __contained_public : __not_contained;
  if (src2dst == -2)
    return __not_contained;
  return __do_find_public_src (src2dst, obj_ptr, src_type, src_ptr);
}

extern "C" void *
func_005C0F40 (const void *src_ptr,
                const __class_type_info *src_type,
                const __class_type_info *dst_type,
                ptrdiff_t src2dst);

};
#endif
