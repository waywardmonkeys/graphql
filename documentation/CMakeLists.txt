FIND_PACKAGE(Sphinx REQUIRED)
ADD_CUSTOM_TARGET(docs ALL)

IF(SPHINX_FOUND)
  INCLUDE(AddSphinxTarget)
  ADD_SUBDIRECTORY(user-manual)
ENDIF()
