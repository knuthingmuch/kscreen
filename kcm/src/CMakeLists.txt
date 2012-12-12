set(kcm_displayconfiguration_SRCS
	qmloutputcomponent.cpp
	qmloutput.cpp
	displayconfiguration.cpp
	modesproxymodel.cpp
	modeselectionwidget.cpp
	resolutionsortmodel.cpp
)

qt4_automoc(${kcm_displayconfiguration_SRCS})

kde4_add_plugin(kcm_displayconfiguration
	${kcm_displayconfiguration_SRCS})

target_link_libraries(kcm_displayconfiguration
	${QT_QTDECLARATIVE_LIBRARY}
	${KDE4_KDEUI_LIBS}
	${KDE4_PLASMA_LIBS}
	${LibKScreen_LIBRARY})

install(TARGETS kcm_displayconfiguration DESTINATION ${PLUGIN_INSTALL_DIR} )