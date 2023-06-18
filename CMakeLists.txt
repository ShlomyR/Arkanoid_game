cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_COMPILER gcc)
project(main)


set(CMAKE_CXX_STANDARD 17)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(SFML_DIR "C:/lib/SFML/lib/cmake/SFML")
    set(BOOST_DIR "C:/lib/BOOST/lib/cmake/boost_filesystem-1.82.0")

    find_package(SFML 2.4 REQUIRED COMPONENTS system window graphics network audio)

    find_package(Boost 1.8 REQUIRED COMPONENTS filesystem system)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 -O2") 
endif()


# Set the directories for source and header files
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_DIR_MAIN ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles)
set(HEADER_DIR_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Commands)
set(HEADER_DIR_PARSER ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Parser)
set(HEADER_DIR_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Interfaces)
set(HEADER_DIR_INPUT_LOGIC ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/InputLogic)
set(HEADER_DIR_MENU ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Menu)
set(HEADER_DIR_PLAYER_INTERACTIV_OBJ ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/PlayerInteractivObjects)
set(HEADER_DIR_SCORE_LOGIC ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/ScoreLogic)
set(HEADER_DIR_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Options)
set(HEADER_DIR_DIFFICULTY ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Difficulty)
set(HEADER_DIR_VIDEO ${CMAKE_CURRENT_SOURCE_DIR}/src/hederfiles/Video)
set(HEADER_DIR_MAIN ${CMAKE_CURRENT_SOURCE_DIR})

# set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCE ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE MAIN ${SRC_DIR_MAIN}/main.cpp)

file(GLOB_RECURSE HEADER ${HEADER_DIR}/*.hpp)
file(GLOB_RECURSE HEADER_COMMAND ${HEADER_DIR_COMMAND}/*.hpp)
file(GLOB_RECURSE HEADER_PARSER ${HEADER_DIR_PARSER}/*.hpp)
file(GLOB_RECURSE HEADER_INTERFACES ${HEADER_DIR_INTERFACES}/*.hxx)
file(GLOB_RECURSE HEADER_INPUT_LOGIC ${HEADER_DIR_INPUT_LOGIC}/*.hpp)
file(GLOB_RECURSE HEADER_MENU ${HEADER_DIR_MENU}/*.hpp)
file(GLOB_RECURSE HEADER_PLAYER_INTERACTIV_OBJ ${HEADER_DIR_PLAYER_INTERACTIV_OBJ}/*.hpp)
file(GLOB_RECURSE HEADER_SCORE_LOGIC ${HEADER_DIR_SCORE_LOGIC}/*.hpp)
file(GLOB_RECURSE HEADER_OPTIONS ${HEADER_DIR_OPTIONS}/*.hpp)
file(GLOB_RECURSE HEADER_DIFFICULTY ${HEADER_DIR_DIFFICULTY}/*.hpp)
file(GLOB_RECURSE HEADER_VIDEO ${HEADER_DIR_VIDEO}/*.hpp)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}
# )


add_executable(${PROJECT_NAME} ${MAIN} ${SOURCE}  ${HEADER})

# Check if the system is macOS
if (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${HEADER_DIR} 
        ${HEADER_DIR_COMMAND}
        ${HEADER_DIR_INTERFACES} 
        ${HEADER_DIR_PARSER} 
        ${HEADER_DIR_INPUT_LOGIC}  
        ${HEADER_DIR_MENU}  
        ${HEADER_DIR_PLAYER_INTERACTIV_OBJ}  
        ${HEADER_DIR_SCORE_LOGIC}  
        ${HEADER_DIR_OPTIONS}  
        ${HEADER_DIR_DIFFICULTY} 
        ${HEADER_DIR_VIDEO}
        ${HEADER_DIR_MAIN}
        /opt/homebrew/Cellar/sfml/2.5.1_2/include
        /opt/homebrew/Cellar/boost/1.82.0/include
    )
    # Add your library dependencies here
    target_link_libraries(${PROJECT_NAME}
        pthread
        /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-graphics.dylib
        /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-window.dylib
        /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-system.dylib
        /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-audio.dylib
        /opt/homebrew/Cellar/boost/1.82.0/lib/libboost_filesystem.dylib
    )

elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${HEADER_DIR} 
        ${HEADER_DIR_COMMAND}
        ${HEADER_DIR_INTERFACES} 
        ${HEADER_DIR_PARSER} 
        ${HEADER_DIR_INPUT_LOGIC}  
        ${HEADER_DIR_MENU}  
        ${HEADER_DIR_PLAYER_INTERACTIV_OBJ}  
        ${HEADER_DIR_SCORE_LOGIC}  
        ${HEADER_DIR_OPTIONS}  
        ${HEADER_DIR_DIFFICULTY} 
        ${HEADER_DIR_VIDEO}
        ${HEADER_DIR_MAIN}
    )

    # Add your library dependencies here
    target_link_libraries(${PROJECT_NAME}
        pthread
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        boost_filesystem
    )

# Check if the system is Windows
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${HEADER_DIR}
        ${HEADER_DIR_COMMAND}
        ${HEADER_DIR_INTERFACES}
        ${HEADER_DIR_PARSER}
        ${HEADER_DIR_INPUT_LOGIC}
        ${HEADER_DIR_MENU}
        ${HEADER_DIR_PLAYER_INTERACTIV_OBJ}
        ${HEADER_DIR_SCORE_LOGIC}
        ${HEADER_DIR_OPTIONS}
        ${HEADER_DIR_DIFFICULTY}
        ${HEADER_DIR_VIDEO}
        ${HEADER_DIR_MAIN}
        C:/lib/BOOST
        C:/msys64/mingw64/bin
        C:/lib/SFML/include
        C:/lib/SFML/bin

    )

    # Add your library dependencies here
    target_link_libraries(${PROJECT_NAME}
        sfml-graphics sfml-system sfml-window sfml-audio C:/msys64/mingw64/bin/libboost_filesystem-mt.dll
    )
    
endif()

