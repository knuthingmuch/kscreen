include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(kscreen-console main.cpp console.cpp)

target_link_libraries(kscreen-console
            Qt5::DBus
            Qt5::Gui
            KF5::CoreAddons
            KF5::I18n
            KF5::Screen)

install(TARGETS kscreen-console ${INSTALL_TARGETS_DEFAULT_ARGS})
