add_library (producer "")
target_link_libraries (producer ${CONAN_LIBS} communication)
target_sources (producer 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/producer.c
   )
target_include_directories (producer 
   PUBLIC 
   ${CMAKE_CURRENT_LIST_DIR}/
  )