file(GLOB HEADERS "include/calibrae/account_by_key/*.hpp")

add_library( calibrae_account_by_key
             account_by_key_plugin.cpp
             account_by_key_api.cpp
           )

target_link_libraries( calibrae_account_by_key calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_account_by_key
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_account_by_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
