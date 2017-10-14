file(GLOB HEADERS "include/calibrae/plugins/debug_node/*.hpp")

add_library( calibrae_debug_node
             ${HEADERS}
             debug_node_plugin.cpp
             debug_node_api.cpp
           )

target_link_libraries( calibrae_debug_node calibrae_app calibrae_chain calibrae_protocol fc )
target_include_directories( calibrae_debug_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS calibrae_debug_node
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
       )
INSTALL( FILES ${HEADERS} DESTINATION "include/calibrae/plugins/debug_node" )
