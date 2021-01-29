// Copyright 2020-2021	Salvatore Barone <salvatore.barone@unina.it>
// 
// This file is part of CNN-VHDL
// 
// This is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or any later version.
// 
// This is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
// 
// You should have received a copy of the GNU General Public License along with
// RMEncoder; if not, write to the Free Software Foundation, Inc., 51 Franklin
// Street, Fifth Floor, Boston, MA 02110-1301, USA.

#include "trunc.h"

truncate::ax_integer::ax_integer(uint8_t nab, int8_t value) : internal_type(int8), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, int16_t value)  : internal_type(int16), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, int32_t value)  : internal_type(int32), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, int64_t value)  : internal_type(int64), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, uint8_t value)  : internal_type(uint8), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, uint16_t value) : internal_type(uint16), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, uint32_t value) : internal_type(uint32), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, uint64_t value) : internal_type(uint64), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer::ax_integer(uint8_t nab, internal_type_t type, uint64_t value) : internal_type(type), actual_value(value), apprx_mask(0xffffffffffffffff)
{
  num_approx_bits = (nab < getMaxApprxGrade() ? nab : getMaxApprxGrade());
  axmask();
}

truncate::ax_integer& truncate::ax_integer::operator+=(const ax_integer& rhs)
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    actual_value = (((int64_t) (actual_value & apprx_mask)) + ((int64_t) (rhs.actual_value & rhs.apprx_mask)));
  else
  // or... (read below!)
  //if ( !is_signed() && !rhs.is_signed())
  //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
  // Otherwise, if the unsigned operand's conversion rank is greater or equal to
  // the conversion rank of the signed operand, the signed operand is converted
  // to the unsigned operand's type.
  // In our case, this condition equals to the following.
  // Otherwise, both operands are converted to the unsigned counterpart of the
  // signed operand's type.
  // For convenience, operands are converted both to uint64_t.
    actual_value = (((uint64_t) (actual_value & apprx_mask)) + ((uint64_t) (rhs.actual_value & rhs.apprx_mask)));
  return *this;
}

truncate::ax_integer& truncate::ax_integer::operator-=(const ax_integer& rhs)
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    actual_value = (((int64_t) (actual_value & apprx_mask)) - ((int64_t) (rhs.actual_value & rhs.apprx_mask)));
  else
  // or... (read below!)
  //if ( !is_signed() && !rhs.is_signed())
  //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
  // Otherwise, if the unsigned operand's conversion rank is greater or equal to
  // the conversion rank of the signed operand, the signed operand is converted
  // to the unsigned operand's type.
  // In our case, this condition equals to the following.
  // Otherwise, both operands are converted to the unsigned counterpart of the
  // signed operand's type.
  // For convenience, operands are converted both to uint64_t.
    actual_value = (((uint64_t) (actual_value & apprx_mask)) - ((uint64_t) (rhs.actual_value & rhs.apprx_mask)));
  return *this;
}

truncate::ax_integer& truncate::ax_integer::operator*=(const ax_integer& rhs)
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    actual_value = (((int64_t) (actual_value & apprx_mask)) * ((int64_t) (rhs.actual_value & rhs.apprx_mask)));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    actual_value = (((uint64_t) (actual_value & apprx_mask)) * ((uint64_t) (rhs.actual_value & rhs.apprx_mask)));
  return *this;
}

truncate::ax_integer& truncate::ax_integer::operator/=(const ax_integer& rhs)
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    actual_value = (((int64_t) (actual_value & apprx_mask)) / ((int64_t) (rhs.actual_value & rhs.apprx_mask)));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    actual_value = (((uint64_t) (actual_value & apprx_mask)) / ((uint64_t) (rhs.actual_value & rhs.apprx_mask)));
  return *this;
}



truncate::ax_integer truncate::ax_integer::operator+(const ax_integer& rhs) const
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((int64_t) (actual_value & apprx_mask)) + ((int64_t) (rhs.actual_value & rhs.apprx_mask))));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((uint64_t) (actual_value & apprx_mask)) + ((uint64_t) (rhs.actual_value & rhs.apprx_mask))));
}

truncate::ax_integer truncate::ax_integer::operator-(const ax_integer& rhs) const
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((int64_t) (actual_value & apprx_mask)) - ((int64_t) (rhs.actual_value & rhs.apprx_mask))));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((uint64_t) (actual_value & apprx_mask)) - ((uint64_t) (rhs.actual_value & rhs.apprx_mask))));
}

truncate::ax_integer truncate::ax_integer::operator*(const ax_integer& rhs) const
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((int64_t) (actual_value & apprx_mask)) * ((int64_t) (rhs.actual_value & rhs.apprx_mask))));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((uint64_t) (actual_value & apprx_mask)) * ((uint64_t) (rhs.actual_value & rhs.apprx_mask))));
}

truncate::ax_integer truncate::ax_integer::operator/(const ax_integer& rhs) const
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((int64_t) (actual_value & apprx_mask)) / ((int64_t) (rhs.actual_value & rhs.apprx_mask))));
  else
    // or... (read below!)
    //if ( !is_signed() && !rhs.is_signed())
    //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
    // Otherwise, if the unsigned operand's conversion rank is greater or equal to
    // the conversion rank of the signed operand, the signed operand is converted
    // to the unsigned operand's type.
    // In our case, this condition equals to the following.
    // Otherwise, both operands are converted to the unsigned counterpart of the
    // signed operand's type.
    // For convenience, operands are converted both to uint64_t.
    return ax_integer(
      num_approx_bits < rhs.num_approx_bits ? num_approx_bits : rhs.num_approx_bits,
      internal_type > rhs.internal_type ? internal_type : rhs.internal_type,
      (uint64_t)(((uint64_t) (actual_value & apprx_mask)) / ((uint64_t) (rhs.actual_value & rhs.apprx_mask))));
}

bool truncate::ax_integer::operator==(const ax_integer& rhs) const
{
  if ((actual_value & apprx_mask) == (rhs.actual_value & rhs.apprx_mask))
    return true;
  return false;
}

bool truncate::ax_integer::operator< (const ax_integer& rhs) const
{
  // If both operands are signed or both are unsigned, the operand with lesser
  // conversion rank is converted to the operand with the greater integer
  // conversion rank.
  // For convenience, operands are converted either tu int64_t or uint64_t,
  // respectively.
  if (is_signed() && rhs.is_signed())
    return ((int64_t) (actual_value & apprx_mask)) < ((int64_t) (rhs.actual_value & rhs.apprx_mask));
  
  // or... (read below!)
  //if ( !is_signed() && !rhs.is_signed())
  //  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
  
  // Otherwise, if the unsigned operand's conversion rank is greater or equal to
  // the conversion rank of the signed operand, the signed operand is converted
  // to the unsigned operand's type.
  // In our case, this condition equals to the following.
  // Otherwise, both operands are converted to the unsigned counterpart of the
  // signed operand's type.
  // For convenience, operands are converted both to uint64_t.
  return ((uint64_t) (actual_value & apprx_mask)) < ((uint64_t) (rhs.actual_value & rhs.apprx_mask));
}

uint8_t truncate::ax_integer::getMaxApprxGrade () const
{
  switch (internal_type)
  {
    case int8:  return 7U;
    case int16: return 15U;
    case int32: return 31U;
    case int64: return 63U;
    case uint8: return 8U;
    case uint16: return 16U;
    case uint32: return 32U;
    case uint64: return 64U;
    default: return 0U;
  }
}

void truncate::ax_integer::axmask()
{
  if (num_approx_bits == 0)
    apprx_mask = 0xffffffffffffffff;
  else
  {
    apprx_mask = 1UL;
    apprx_mask <<= num_approx_bits;
    apprx_mask -= 1;
    apprx_mask = ~apprx_mask;
  }
}

bool truncate::ax_integer::is_signed() const
{
  if (internal_type == int8 || internal_type == int16 || internal_type == int32 || internal_type == int64)
    return true;
  return false;
}
