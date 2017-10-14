file(GLOB HEADERS "include/calibrae/delayed_node/*.hpp")

add_library( calibrae_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( calibrae_delayed_node calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   calibrae_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
