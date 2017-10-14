file(GLOB HEADERS "include/calibrae/follow/*.hpp")

add_library( calibrae_follow
             follow_plugin.cpp
             follow_api.cpp
             follow_operations.cpp
             follow_evaluators.cpp
           )

target_link_libraries( calibrae_follow calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_follow
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_follow

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
