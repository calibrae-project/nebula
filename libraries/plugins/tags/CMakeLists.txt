file(GLOB HEADERS "include/calibrae/tags/*.hpp")

add_library( calibrae_tags
             tags_plugin.cpp )

target_link_libraries( calibrae_tags calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_tags
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_tags

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
