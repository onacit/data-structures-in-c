#ifndef DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
#define DATA_STRUCTURES_IN_C_MISCELLANEOUS_H

int sprintf_ordinal_u(char *s, unsigned int c);

int snprintf_ordinal_u(char *s, size_t n, unsigned int c);

int sprintf_ordinal_lu(char *s, unsigned long int c);

int snprintf_ordinal_lu(char *s, size_t n, unsigned long int c);

int sprintf_ordinal_llu(char *s, unsigned long long int c);

int snprintf_ordinal_llu(char *s, size_t n, unsigned long long int c);

// https://stackoverflow.com/a/42698961/330457
//_Static_assert(__STDC__ == 1 && __STDC_VERSION >= 201112L);

// https://stackoverflow.com/a/42704051/330457
//_Static_assert(_Generic(0, default: 1), "we need _Generic");

#define sprintf_ordinal_g(S, C) _Generic((C), \
  unsigned char:          sprintf_ordinal_u,          \
  unsigned short int:     sprintf_ordinal_u,          \
  unsigned int:           sprintf_ordinal_u,          \
  unsigned long int:      sprintf_ordinal_lu,         \
  unsigned long long int: sprintf_ordinal_llu,        \
  default:                sprintf_ordinal_u           \
)(S, C)

#define snprintf_ordinal_g(S, N, C) _Generic((C), \
  unsigned char:          snprintf_ordinal_u,            \
  unsigned short int:     snprintf_ordinal_u,            \
  unsigned int:           snprintf_ordinal_u,            \
  unsigned long int:      snprintf_ordinal_lu,           \
  unsigned long long int: snprintf_ordinal_llu,          \
  default:                snprintf_ordinal_u             \
)(S, N, C)

#endif //DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
