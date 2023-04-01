add_executable(humidity "")
target_link_libraries(humidity ${CONAN_LIBS} communication producer)
target_sources(humidity 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
   )