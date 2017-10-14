file(GLOB HEADERS "include/calibrae/plugins/block_info/*.hpp")

add_library( calibrae_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( calibrae_block_info calibrae_app calibrae_chain calibrae_protocol fc )
target_include_directories( calibrae_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
