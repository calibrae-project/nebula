file(GLOB HEADERS "include/calibrae/market_history/*.hpp")

add_library( calibrae_market_history
             market_history_plugin.cpp
             market_history_api.cpp
           )

target_link_libraries( calibrae_market_history calibrae_chain calibrae_protocol calibrae_app )
target_include_directories( calibrae_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   calibrae_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)