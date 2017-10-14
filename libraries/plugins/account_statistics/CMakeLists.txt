file(GLOB HEADERS "include/calibrae/account_statistics/*.hpp")

add_library( calibrae_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( calibrae_account_statistics calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)