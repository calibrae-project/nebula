file(GLOB HEADERS "include/calibrae/witness/*.hpp")

add_library( calibrae_witness
             witness_plugin.cpp
             witness_evaluators.cpp
             witness_operations.cpp
           )

target_link_libraries( calibrae_witness calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
