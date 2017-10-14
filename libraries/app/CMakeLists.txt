file(GLOB HEADERS "include/calibrae/app/*.hpp")

add_library( calibrae_app
             database_api.cpp
             api.cpp
             application.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
           )

target_link_libraries( calibrae_app calibrae_chain calibrae_protocol calibrae_tags calibrae_follow calibrae_witness calibrae_mf_plugins fc graphene_net graphene_utilities )
target_include_directories( calibrae_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   calibrae_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/calibrae/app" )
