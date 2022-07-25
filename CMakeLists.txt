cmake_minimum_required(VERSION 3.0.2)
project(rqt_question_box)

set(CMAKE_CXX_STANDARD 14)


## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    message_generation
)

###########
## Build ##
###########

add_service_files(
  FILES
  GetGui.srv
)

generate_messages(DEPENDENCIES std_msgs)

include_directories(
    include
    ${catkin_INCLUDE_DIRS})

catkin_package(
    CATKIN_DEPENDS
    roscpp
    message_runtime
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(QT_LIBRARIES Qt5::Widgets)

add_executable(
    ${PROJECT_NAME}
        src/main.cpp
        src/message_box/MessageBox.cpp
        src/ServiceHandle.cpp
        src/App.cpp)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${QT_LIBRARIES})

install(DIRECTORY include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    )

install(FILES DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})