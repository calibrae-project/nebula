file(GLOB HEADERS "include/calibrae/account_history/*.hpp")

add_library( calibrae_account_history
             account_history_plugin.cpp
           )

target_link_libraries( calibrae_account_history calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
