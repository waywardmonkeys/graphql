PROJECT(graphql C)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

SET(graphql_SOURCES
    schema.c
    types.c
)

SET(graphql_HEADERS
    ../include/graphql/schema.h
    ../include/graphql/types.h
)

ADD_LIBRARY(graphql
            SHARED
            ${graphql_SOURCES}
            ${graphql_HEADERS})
ADD_LIBRARY(graphqlSTATIC
            STATIC
            ${graphql_SOURCES}
            ${graphql_HEADERS})
SET_TARGET_PROPERTIES(graphqlSTATIC PROPERTIES OUTPUT_NAME graphql)
IF(NOT CMAKE_SYSTEM_NAME MATCHES "Emscripten")
  SET_TARGET_PROPERTIES(graphql PROPERTIES VERSION ${GRAPHQL_VERSION})
  SET_TARGET_PROPERTIES(graphqlSTATIC PROPERTIES VERSION ${GRAPHQL_VERSION})
ENDIF()

IF (NOT WIN32)
  INSTALL(TARGETS graphqlSTATIC DESTINATION lib)
ENDIF()
