file(GLOB HEADERS "include/calibrae/plugins/auth_util/*.hpp")

add_library( calibrae_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( calibrae_auth_util calibrae_app calibrae_chain calibrae_protocol fc )
target_include_directories( calibrae_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
