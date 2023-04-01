add_executable(barometry "")
target_link_libraries(barometry ${CONAN_LIBS} communication producer)
target_sources(barometry 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
   )