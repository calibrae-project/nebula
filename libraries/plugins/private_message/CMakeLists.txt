file(GLOB HEADERS "include/calibrae/private_message/*.hpp")

add_library( calibrae_private_message
             private_message_plugin.cpp
           )

target_link_libraries( calibrae_private_message calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
