cmake_minimum_required(VERSION 3.21)
project(csgo_cfg_manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/qt/6.2.3/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(csgo_cfg_manager source/main.cpp source/mainwindow.cpp source/windowsutils.cpp source/cfgmanager.cpp header/mainwindow.h header/windowsutils.h header/cfgmanager.h header/exceptions/files_does_not_exist_exception.h header/exceptions/invalid_path_exception.h header/exceptions/csgo_cfg_runtime_exception.h source/utils/Utils.cpp source/utils/Utils.h header/exceptions/reg_exception.h)
target_link_libraries(csgo_cfg_manager
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

set(SOURCES source/main.cpp source/mainwindow.cpp source/windowsutils.cpp source/cfgmanager.cpp)
set(HEADERS header/mainwindow.h header/windowsutils.h header/cfgmanager.h header/exceptions/files_does_not_exist_exception.h header/exceptions/invalid_path_exception.h header/exceptions/csgo_cfg_runtime_exception.h)
set(UI source/mainwindow.ui)

include_directories("D:\\DEV-TOOL\\boost_1_78_0\\boost")

if (WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
