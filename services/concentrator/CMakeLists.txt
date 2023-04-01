add_executable(concentrator "")
target_link_libraries(concentrator ${CONAN_LIBS} communication)
target_sources(concentrator 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/concentrator.c
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller/udp_controller.c
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller/udp_events.c
   )

target_include_directories (concentrator 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller
   )
