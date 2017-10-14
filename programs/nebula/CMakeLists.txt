add_executable( nebula main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling nebula with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( STEEM_STATIC_BUILD )
   target_link_libraries( nebula PRIVATE
      "-static-libstdc++ -static-libgcc"
      calibrae_plugins
      calibrae_mf_plugins
      calibrae_app
      calibrae_witness
      calibrae_account_history
      calibrae_chain
      calibrae_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( STEEM_STATIC_BUILD )
   target_link_libraries( nebula PRIVATE
      calibrae_plugins
      calibrae_mf_plugins
      calibrae_app
      calibrae_witness
      calibrae_account_history
      calibrae_chain
      calibrae_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( STEEM_STATIC_BUILD )

install( TARGETS
   nebula

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
