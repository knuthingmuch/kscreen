include_directories(${CMAKE_BUILD_DIR}/kded)

set(kscreen_daemon_SRCS
    daemon.cpp
    main.cpp
    testapp.cpp
    serializer.cpp
    generator.cpp
    device.cpp
)

qt4_add_dbus_interface(kscreen_daemon_SRCS
    org.freedesktop.UPower.xml
    upower_interface)

kde4_add_plugin(kded_kscreen
    ${kscreen_daemon_SRCS}
)

target_link_libraries(kded_kscreen
    ${QT_QTCORE_LIBRARIES}
    ${QT_QTGUI_LIBRARIES}
    ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${LibKScreen_LIBRARY} ${QJSON_LIBRARIES} qjson
)

install(TARGETS kded_kscreen DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES kscreen.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded)

set(daemon_testapp_SRCS
    main.cpp
    testapp.cpp
    serializer.cpp
    generator.cpp
    device.cpp
    daemon.cpp
)

qt4_add_dbus_interface(daemon_testapp_SRCS
    org.freedesktop.UPower.xml
    upower_interface)

kde4_add_executable(kscreen_daemon_testapp ${daemon_testapp_SRCS})
target_link_libraries(kscreen_daemon_testapp ${QT_QTCORE_LIBRARIES} ${QT_QTGUI_LIBRARIES} ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${LibKScreen_LIBRARY} ${QJSON_LIBRARIES} qjson)