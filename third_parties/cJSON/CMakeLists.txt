add_library(cjson "")
target_sources (cjson
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/cJSON.c
    ${CMAKE_CURRENT_LIST_DIR}/cJSON_Utils.c
)
target_include_directories (cjson
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)