// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "CurrentC.h"
#include "tao/Sequence_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "CurrentC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int CORBA::Current::_tao_class_id = 0;

CORBA::Current_ptr
CORBA::tao_Current_life::tao_duplicate (
    CORBA::Current_ptr p
  )
{
  return CORBA::Current::_duplicate (p);
}

void
CORBA::tao_Current_life::tao_release (
    CORBA::Current_ptr p
  )
{
  CORBA::release (p);
}

CORBA::Current_ptr
CORBA::tao_Current_life::tao_nil (
    void
  )
{
  return CORBA::Current::_nil ();
}

CORBA::Boolean
CORBA::tao_Current_life::tao_marshal (
    CORBA::Current_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

CORBA::Current_ptr
CORBA::tao_Current_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return CORBA::Current::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
CORBA::tao_Current_cast::tao_upcast (
    void *src
  )
{
  CORBA::Current **tmp =
    ACE_static_cast (CORBA::Current **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        CORBA::Current,
        CORBA::tao_Current_life
      >;
  template class
    TAO_Objref_Out_T<
        CORBA::Current,
        CORBA::tao_Current_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::Current, \
        CORBA::tao_Current_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::Current, \
        CORBA::tao_Current_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:232

CORBA::Current::Current (void)
{}

CORBA::Current::~Current (void)
{}

void
CORBA::Current::_tao_any_destructor (void *_tao_void_pointer)
{
  Current *tmp = ACE_static_cast (Current *, _tao_void_pointer);
  CORBA::release (tmp);
}

CORBA::Current_ptr
CORBA::Current::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return Current::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

CORBA::Current_ptr
CORBA::Current::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return Current::_nil ();
    }

  return
      ACE_reinterpret_cast (
          Current_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &Current::_tao_class_id
                )
            )
        );
}

CORBA::Current_ptr
CORBA::Current::_duplicate (Current_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void *CORBA::Current::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;

  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::CORBA, Current)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptr_arith_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }

  if (retv != 0)
    {
      this->_add_ref ();
    }

  return retv;
}

const char* CORBA::Current::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Current:1.0";
}

CORBA::Boolean
CORBA::Current::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_Current[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  30,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f4375),
  ACE_NTOHL (0x7272656e),
  ACE_NTOHL (0x743a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/Current:1.0
    8,
  ACE_NTOHL (0x43757272),
  ACE_NTOHL (0x656e7400),  // name = Current
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_Current (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_Current),
    (char *) &_oc_CORBA_Current,
    0,
    sizeof (CORBA::Current)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_Current,
    &_tc_TAO_tc_CORBA_Current
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:52

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Current_ptr _tao_elem
  )
{
  CORBA::Current_ptr _tao_objptr =
    CORBA::Current::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Current_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::Current>::insert (
      _tao_any,
      CORBA::Current::_tao_any_destructor,
      CORBA::_tc_Current,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Current_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::Current>::extract (
        _tao_any,
        CORBA::Current::_tao_any_destructor,
        CORBA::_tc_Current,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<CORBA::Current,CORBA::Current_var>;
  template class TAO::Any_Impl_T<CORBA::Current>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<CORBA::Current, CORBA::Current_var>
# pragma instantiate TAO::Any_Impl_T<CORBA::Current>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
