cmake_minimum_required(VERSION 3.14)
project(kubi_0_1)

set(CMAKE_CXX_STANDARD 17)

find_package( Boost REQUIRED )

# If ccache
#if( USE_CCACHE )
#    find_program(CCACHE_FOUND "ccache")
#    if( CCACHE_FOUND )
#        message( STATUS "Using ccash" )
#        set_property( GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache )
#        set_property( GLOBAL PROPERTY RULE_LAUNCH_LINK ccache )
#    endif( CCACHE_FOUND )
#endif()

message( STATUS "System platform: " ${CMAKE_HOST_SYSTEM_PROCESSOR} )
message( STATUS "Target platform is " ${CMAKE_SYSTEM_PROCESSOR} )
message( STATUS "Env plm include path: "  $ENV{PLM_INCLUDE_PATH} )
message( STATUS "Env plm link path: " $ENV{PLM_LIBRARY_PATH} )
message( STATUS "Env plm setting platform: " $ENV{PLM_SETTING_PLATFORM} )
message( STATUS "Build type: " ${CMAKE_BUILD_TYPE} )


include_directories( include )

#add_subdirectory - добавить директорию со своим смаке файлом
aux_source_directory( src/Server SERVER_SOURCES)
aux_source_directory( src/Client SERVER_SOURCES)
aux_source_directory( src/Common/ COMMON_SOURCES)
aux_source_directory( src/Common/Errors COMMON_SOURCES)

set( PLM_LINK_PARAMETERS boost_system
#        boost_thread boost_locale boost_regex
        )

add_executable(kubi_server src/main_server.cpp ${SERVER_SOURCES} ${COMMON_SOURCES} )
add_executable(kubi_client src/main_client.cpp ${CLIENT_SOURCES} ${COMMON_SOURCES} )

target_link_libraries( kubi_server ${PLM_LINK_PARAMETERS} )
target_link_libraries( kubi_client ${PLM_LINK_PARAMETERS} )