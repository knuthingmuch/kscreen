add_definitions(-DTRANSLATION_DOMAIN=\"kcm_displayconfiguration\")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/declarative")

set(kcm_kscreen_SRCS
    declarative/qmloutput.cpp
    declarative/qmloutputcomponent.cpp
    declarative/qmlscreen.cpp

    collapsablebutton.cpp
    controlpanel.cpp
    debug.cpp
    outputconfig.cpp
    primaryoutputcombo.cpp
    unifiedoutputconfig.cpp
    resolutionslider.cpp
    utils.cpp
    widget.cpp
    previewwidget.cpp
    scalingconfig.cpp
)

ki18n_wrap_ui(kcm_kscreen_SRCS stylepreview.ui scaling.ui)

add_library(kcm_kscreen MODULE kcm_kscreen.cpp ${kcm_kscreen_SRCS})

target_link_libraries(kcm_kscreen
    Qt5::QuickWidgets
    Qt5::Widgets
    KF5::Screen
    KF5::I18n
    KF5::ConfigCore
    KF5::ConfigWidgets
    KF5::WidgetsAddons
)

install(TARGETS kcm_kscreen DESTINATION ${PLUGIN_INSTALL_DIR} )

add_executable(kcm_testapp kcm_testapp.cpp ${kcm_kscreen_SRCS})
set_target_properties(kcm_testapp PROPERTIES COMPILE_FLAGS "-DQT_DECLARATIVE_DEBUG")
target_link_libraries(kcm_testapp
        Qt5::QuickWidgets
        Qt5::Widgets
        KF5::CoreAddons
        KF5::I18n
        KF5::ConfigCore
        KF5::Screen
        KF5::WidgetsAddons
)
