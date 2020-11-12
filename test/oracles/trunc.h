#ifndef TRUNC_H
#define TRUNC_H

#include <inttypes.h>

namespace truncate {

class ax_integer
{
  public:
    
    ////////////////////////////////////////////////////////////////////////////
    /// Constructors
    explicit ax_integer(uint8_t nab, int8_t value);
    explicit ax_integer(uint8_t nab, int16_t value);
    explicit ax_integer(uint8_t nab, int32_t value);
    explicit ax_integer(uint8_t nab, int64_t value);
    explicit ax_integer(uint8_t nab, uint8_t value);
    explicit ax_integer(uint8_t nab, uint16_t value);
    explicit ax_integer(uint8_t nab, uint32_t value);
    explicit ax_integer(uint8_t nab, uint64_t value);
    
    ////////////////////////////////////////////////////////////////////////////
    /// Assignment operators
    ax_integer& operator=(int8_t value) {internal_type = int8; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(int16_t value) {internal_type = int16; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(int32_t value) {internal_type = int32; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(int64_t value) {internal_type = int64; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(uint8_t value) {internal_type = uint8; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(uint16_t value) {internal_type = uint16; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(uint32_t value) {internal_type = uint32; actual_value = (uint64_t)value; return *this;}
    ax_integer& operator=(uint64_t value) {internal_type = uint64; actual_value = (uint64_t)value; return *this;}
    
    ////////////////////////////////////////////////////////////////////////////
    /// Arithmetical operators
    ax_integer& operator+=(const ax_integer& fp);
    ax_integer& operator-=(const ax_integer& fp);
    ax_integer& operator*=(const ax_integer& fp);
    ax_integer& operator/=(const ax_integer& fp);
    ax_integer operator+(const ax_integer& rhs) const;
    ax_integer operator-(const ax_integer& rhs) const;
    ax_integer operator*(const ax_integer& rhs) const;
    ax_integer operator/(const ax_integer& rhs) const;
    
    ////////////////////////////////////////////////////////////////////////////
    /// Relational operators
    bool operator==(const ax_integer& rhs) const;
    inline bool operator!=(const ax_integer& rhs) const {return !(*this == rhs);}
    bool operator< (const ax_integer& rhs) const;
    inline bool operator> (const ax_integer& rhs) const {return rhs < *this;}
    inline bool operator<=(const ax_integer& rhs) const {return !(*this > rhs);}
    inline bool operator>=(const ax_integer& rhs) const {return !(*this < rhs);}
    
    ////////////////////////////////////////////////////////////////////////////
    /// Cast operators
    operator int8_t() const {return (int8_t) (actual_value & apprx_mask);}
    operator int16_t() const {return (int16_t) (actual_value & apprx_mask);}
    operator int32_t() const {return (int32_t) (actual_value & apprx_mask);}
    operator int64_t() const {return (int64_t) (actual_value & apprx_mask);}
    operator uint8_t() const {return (uint8_t) (actual_value & apprx_mask);}
    operator uint16_t() const {return (uint16_t) (actual_value & apprx_mask);}
    operator uint32_t() const {return (uint32_t) (actual_value & apprx_mask);}
    operator uint64_t() const {return (uint64_t) (actual_value & apprx_mask);}

    ////////////////////////////////////////////////////////////////////////////
    /// Getter
    uint8_t getNab() const {return num_approx_bits;}
    uint64_t getMask() const {return apprx_mask;}
    uint8_t getMaxApprxGrade() const;
  
  private:
    enum internal_type_t{int8, int16, int32, uint8, uint16, uint32, int64, uint64};
    internal_type_t internal_type;
    uint8_t num_approx_bits;
    uint64_t actual_value;
    uint64_t apprx_mask;
    
    explicit ax_integer(uint8_t nab, internal_type_t type, uint64_t value);
    void axmask();
    inline bool is_signed() const;

};

}

#endif //TRUNC_H

