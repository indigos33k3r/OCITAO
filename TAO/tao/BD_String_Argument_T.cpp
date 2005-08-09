// $Id$

#ifndef TAO_BD_STRING_ARGUMENT_T_C
#define TAO_BD_STRING_ARGUMENT_T_C

#include "tao/BD_String_Argument_T.h"

#if !defined (__ACE_INLINE__)
#include "tao/BD_String_Argument_T.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (tao,
           BD_String_Argument_T,
           "$Id$")

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
CORBA::Boolean
TAO::In_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::marshal (
    TAO_OutputCDR & cdr
  )
{
  return cdr << from_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
void
TAO::In_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  this->Insert_Policy::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ===========================================================

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
CORBA::Boolean
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::marshal (
    TAO_OutputCDR & cdr
  )
{
  return cdr << from_S (this->x_, BOUND);
}

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
CORBA::Boolean
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  delete [] this->x_;
  return cdr >> to_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
void
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  this->Insert_Policy::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ==============================================================

template<typename S,
         typename S_out,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
CORBA::Boolean
TAO::Out_BD_String_Argument_T<S,S_out,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  return cdr >> to_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename S_out,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
void
TAO::Out_BD_String_Argument_T<S,S_out,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  this->Insert_Policy::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ============================================================

template<typename S,
         typename S_var,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
CORBA::Boolean
TAO::Ret_BD_String_Argument_T<S,S_var,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  return cdr >> to_S (this->x_.out (), BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename S_var,
         typename to_S,
         typename from_S,
         size_t BOUND,
         typename Insert_Policy>
void
TAO::Ret_BD_String_Argument_T<S,S_var,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  this->Insert_Policy::any_insert (any, from_S (this->x_.in (), BOUND));
  (*any) <<= from_S (this->x_.in (), BOUND);
}

#endif /* TAO_HAS_INTERCEPTORS */

#endif /* TAO_BD_STRING_ARGUMENT_T_C */
