add_executable(temperature "")
target_link_libraries(temperature ${CONAN_LIBS} communication producer)
target_sources(temperature 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
   )