#ifndef DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
#define DATA_STRUCTURES_IN_C_MISCELLANEOUS_H

int ordinal_hhu(char *s, unsigned char c);

int ordinal_hhu_n(char *s, size_t n, unsigned char c);

int ordinal_hu(char *s, unsigned short c);

int ordinal_hu_n(char *s, size_t n, unsigned short c);

int ordinal_u(char *s, unsigned int c);

int ordinal_u_n(char *s, size_t n, unsigned int c);

int ordinal_lu(char *s, unsigned long c);

int ordinal_lu_n(char *s, size_t n, unsigned long int c);

int ordinal_llu(char *s, unsigned long long int c);

int ordinal_llu_n(char *s, size_t n, unsigned long long int c);

#define ordinal_numeral(S, C) _Generic((C), \
  unsigned char: ordinal_hhu,         \
  unsigned short int: ordinal_hu,     \
  unsigned int: ordinal_u,            \
  unsigned long int: ordinal_lu,      \
  unsigned long long int: ordinal_llu \
)(S, C)

#define ordinal_numeral_n(S, N, C) _Generic((C), \
  unsigned char: ordinal_hhu_n,         \
  unsigned short int: ordinal_hu_n,     \
  unsigned int: ordinal_u_n,            \
  unsigned long int: ordinal_lu_n,      \
  unsigned long long int: ordinal_llu_n \
)(S, N, C)

#endif //DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
