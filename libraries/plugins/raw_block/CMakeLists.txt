file(GLOB HEADERS "include/calibrae/plugins/raw_block/*.hpp")

add_library( calibrae_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( calibrae_raw_block calibrae_app calibrae_chain calibrae_protocol fc )
target_include_directories( calibrae_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
