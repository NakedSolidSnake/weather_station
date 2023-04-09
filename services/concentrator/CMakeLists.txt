add_executable(concentrator "")
target_link_libraries(concentrator ${CONAN_LIBS} communication pthread cjson)
target_sources(concentrator 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/concentrator.c
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller/udp_controller.c
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller/udp_events.c
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller/web_controller.c
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller/handlers/handlers.c
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller/webserver/webserver.c
    ${CMAKE_CURRENT_LIST_DIR}/src/dto/sensor_message.c
    ${CMAKE_CURRENT_LIST_DIR}/src/data_provider/deserializer/sensor_message_deserializer.c
   )

target_include_directories (concentrator 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src/udp_controller
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller/handlers
    ${CMAKE_CURRENT_LIST_DIR}/src/web_controller/webserver
    ${CMAKE_CURRENT_LIST_DIR}/src/dto
    ${CMAKE_CURRENT_LIST_DIR}/src/data_provider/deserializer
   )


add_custom_command(TARGET concentrator POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/assets 
    ${CMAKE_BINARY_DIR}/bin/assets)