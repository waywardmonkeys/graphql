#ifndef GRAPHQL_TYPES_H_
#define GRAPHQL_TYPES_H_

#include <stdbool.h>
#include <stddef.h>

typedef bool (*graphql_is_type_of_fun_t)(void);
typedef void (*graphql_parse_literal_fun_t)(void);
typedef void (*graphql_parse_value_fun_t)(void);
typedef void (*graphql_resolve_field_fun_t)(void);
typedef void (*graphql_resolve_type_fun_t)(void);
typedef void (*graphql_serialize_fun_t)(void);

typedef struct graphql_type_s
{
  const char *name;
  const char *description;
} graphql_type_t;

typedef struct graphql_scalar_type_s
{
  const char *name;
  const char *description;
  graphql_serialize_fun_t *serialize;
  graphql_parse_value_fun_t *parse_value;
  graphql_parse_literal_fun_t *parse_literal;
} graphql_scalar_type_t;

extern graphql_scalar_type_t *graphql_int_type;
extern graphql_scalar_type_t *graphql_float_type;
extern graphql_scalar_type_t *graphql_string_type;
extern graphql_scalar_type_t *graphql_boolean_type;
extern graphql_scalar_type_t *graphql_id_type;

typedef struct graphql_interface_s graphql_interface_t;
typedef struct graphql_field_s
{
  const char *name;
  const char *description;
  graphql_type_t *type;
  void *args;
  graphql_resolve_field_fun_t resolve;
  const char *deprecation_reason;
} graphql_field_t;

typedef struct graphql_object_type_s
{
  const char *name;
  const char *description;
  size_t interface_count;
  graphql_interface_t *interfaces;
  size_t field_count;
  graphql_field_t *fields;
  graphql_is_type_of_fun_t is_type_of;
} graphql_object_type_t;

typedef struct graphql_union_type_s
{
  const char *name;
  const char *description;
  size_t union_types_count;
  graphql_type_t *union_types;
  graphql_resolve_type_fun_t resolve_type;
} graphql_union_type_t;

#endif /* GRAPHQL_TYPES_H_ */
