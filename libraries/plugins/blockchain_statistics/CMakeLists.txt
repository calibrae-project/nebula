file(GLOB HEADERS "include/calibrae/blockchain_statistics/*.hpp")

add_library( calibrae_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( calibrae_blockchain_statistics calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)