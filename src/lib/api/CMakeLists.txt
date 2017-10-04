cmake_minimum_required(VERSION 3.9)
set(PWD "${CMAKE_CURRENT_SOURCE_DIR}")

project(scribe C CXX)
# build on qt4 or qt5? true go qt4
SET(BUILD_AS_QTOLD false)

set(SHA_LIBXSLT_NAME "qt_framexslt_api")
set(STA_LIBXSLT_NAME "qt_framexslt")



set(MYLIB_VERSION_MAJOR 1)
set(MYLIB_VERSION_MINOR 5)
set(MYLIB_VERSION_PATCH 0)
set(MYLIB_VERSION_STRING ${MYLIB_VERSION_MAJOR}.${MYLIB_VERSION_MINOR}.${MYLIB_VERSION_PATCH})


set(PROJECT_COMPANY_NAME “Avasoft Switzerland”)
set(PROJECT_DESCRIPTION “Convert XSLT1 xml file in any diretion ”)
set(PROJECT_URL "https://www.qt.io/")
string(TIMESTAMP PROJECT_COPYRIGHT "Copyright © 1999-%Y P.Kopp All Rights Reserved." UTC)
set(PROJECT_COPYRIGHT ${PROJECT_COPYRIGHT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")




IF(BUILD_AS_QTOLD)
# only qt4 build
SET(USENEWQT5 false)
find_package (Qt4 COMPONENTS QtCore QtGui QtNetwork  QtSvg QtDeclarative QtXml QtOpengl QtHelp QtUiTools QtSql  QtScriptTools QtScript QtMultimedia )
INCLUDE(${QT_USE_FILE})
add_definitions(-DQTVERSION4)
set(PROJECT_NAME "scribe4")
set(CMAKE_AUTOMOC ON)
ELSE()
SET(USENEWQT5 true)
set(PROJECT_NAME "scribe5")
#build as qt5 all sources
message(STATUS "BUILD SOURCE AS QT5 FROM XXXXstartXXXX")
# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)
# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})
# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})
# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.  Widgets
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Xml REQUIRED )
find_package( Qt5Svg REQUIRED )
find_package( Qt5PrintSupport REQUIRED) 
#find_package(Qt5::Core 5.1.0 CONFIG REQUIRED) PrintSupport Core Widgets Gui Xml Svg
get_target_property(QtCore_location Qt5::Core LOCATION)
message(STATUS "QtCore_location ${QtCore_location}")
SET(QMAKEEXE ${QtCore_location}/bin/qmake)
set(QT5_DIR ${QtCore_location})	
add_definitions(-DQTVERSION5)
set(CMAKE_AUTOMOC ON)


message(STATUS "Qt5Core_INCLUDE_DIRS ${Qt5Core_INCLUDE_DIRS}")
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
message(STATUS "Qt5Core_INCLUDE_DIRS ${Qt5Core_INCLUDE_DIRS}")
message(STATUS "Qt5Widgets_INCLUDE_DIRS ${Qt5Widgets_INCLUDE_DIRS}")
message(STATUS "BUILD SOURCE AS QT5 FROM XXXXendXXXX")
# swap in code old new #define Q_WS_MAC  Q_OS_MAC
ENDIF()


find_package( ZLIB 1.2.5 REQUIRED )
 if ( ZLIB_FOUND )
     include_directories( ${ZLIB_INCLUDE_DIRS} )
  SET(BUILDZLIB false)
else ()
SET(BUILDZLIB true )
endif( ZLIB_FOUND )


# lib extra to insert
FIND_PACKAGE(LibXml2 2.9.5 REQUIRED)
FIND_PACKAGE(LibXslt 1.1.29 REQUIRED)
INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${LIBXSLT_INCLUDE_DIR})
find_path(LIBXML2_INCLUDE_DIR libxml/xpath.h
          HINTS ${PC_LIBXML_INCLUDEDIR} ${PC_LIBXML_INCLUDE_DIRS}
          PATH_SUFFIXES libxml2 )

message(STATUS "LIBXML2_INCLUDE_DIR ${LIBXML2_INCLUDE_DIR}")	
message(STATUS "LIBXSLT_INCLUDE_DIR ${LIBXSLT_INCLUDE_DIR}")	



IF(BUILD_AS_QTOLD)
SET(CurrentWork_LIBRARIES
    ${LIBXML2_LIBRARIES}
    ${LIBXSLT_LIBRARIES}
    ${ZLIB_LIBRARIES}
	${QT_LIBRARIES}
)
ELSE()
SET(CurrentWork_LIBRARIES
	 ${LIBXML2_LIBRARIES}
        ${LIBXSLT_LIBRARIES}
	 ${ZLIB_LIBRARIES}
)	
ENDIF()



#find_package( Qt5Core REQUIRED ) LibXslt
set (CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES({PWD}/)

INCLUDE_DIRECTORIES(/usr/local/include)
INCLUDE_DIRECTORIES(/opt/local/include)

function(Generate_Qmake arg10 filelista filelist_cpp )
    set(PNAMEWORK ${arg10})
    set(listVar "# Generated qmake pri file  \n")
    FOREACH(infilesrc ${filelist_cpp})
                set(SRCsfile ${infilesrc} )
                get_filename_component(ITEM_RPATH ${SRCsfile} DIRECTORY)
                get_filename_component(ITEM_R ${SRCsfile} NAME)
                MESSAGE( STATUS "CPP Source read: " ${ITEM_R})
                string(APPEND listVar "SOURCES +=$PWD/${ITEM_R} \n")
    ENDFOREACH(infilesrc)
	
    FOREACH(infileName ${filelista})
                set(HEADERsfile ${infileName} )
                get_filename_component(ITEM_PATH ${HEADERsfile} DIRECTORY)
                get_filename_component(ITEM_H ${HEADERsfile} NAME)
                MESSAGE( STATUS "H Header read: " ${ITEM_H})
                string(APPEND listVar "HEADERS +=$PWD/${ITEM_H} \n")
                string(APPEND listVar "INCLUDEPATH += ${ITEM_PATH} \n")
    ENDFOREACH(infileName)


    set (PRICOMPFILE ${listVar} PARENT_SCOPE)
endfunction()

set(CMAKE_BUILD_TYPE Release)






set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)




INCLUDE_DIRECTORIES("./")
INCLUDE_DIRECTORIES("./page")

file (GLOB HEAD_FILES ${PWD}/*.h )
file (GLOB SRCBASE_FILES ${PWD}/*.cpp ${PWD}/*.qrc )
set(Source_Cpp ${SRCBASE_FILES})

INCLUDE_DIRECTORIES(${PWD}/page)
file (GLOB page_FILES ${PWD}/page/*.cpp )
list(APPEND Source_Cpp ${page_FILES})



MESSAGE( STATUS "Header file read p: ${STA_LIBXSLT_NAME} XXXXstartXXXX ")
Generate_Qmake(${PROJECT_NAME} "${HEAD_FILES}"  "${Source_Cpp}" )
MESSAGE( STATUS "Header file read p: ${STA_LIBXSLT_NAME}  XXXXstopXXXX ")

exec_program(pwd  OUTPUT_VARIABLE _PWD_)
file(COPY ${PWD}/key.xml DESTINATION ${_PWD_} )
file(COPY ${PWD}/key.xsl DESTINATION ${_PWD_} )
file(COPY ${PWD}/key.zip DESTINATION ${_PWD_} )


add_executable(${PROJECT_NAME} ${Source_Cpp} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CurrentWork_LIBRARIES})
IF(USENEWQT5)
qt5_use_modules(${PROJECT_NAME} PrintSupport Core Widgets Gui Xml Svg )
string(APPEND PRICOMPFILE "QT +=core svg xml widgets gui printsupport \n")
ENDIF()

message(STATUS "LIBXML2_INCLUDE_DIR ${LIBXML2_INCLUDE_DIR}")	
message(STATUS "LIBXSLT_INCLUDE_DIR ${LIBXSLT_INCLUDE_DIR}")	
set(uselib   "${CurrentWork_LIBRARIES}" )
string(APPEND PRICOMPFILE "QT +=${LIBXML2_INCLUDE_DIR} \n")
string(APPEND PRICOMPFILE "QT +=${LIBXSLT_INCLUDE_DIR} \n")
string(APPEND PRICOMPFILE "QT +=${ZLIB_INCLUDE_DIRS} \n")
string(APPEND PRICOMPFILE "QT +=${uselib} \n")
string(APPEND PRICOMPFILE "QT4 +=QtCore QtGui QtNetwork  QtSvg QtDeclarative QtXml QtOpengl QtHelp QtUiTools QtSql  QtScriptTools QtScript QtMultimedia \n")

# MESSAGE( STATUS "Read as: ${PRICOMPFILE}")
file(WRITE ${_PWD_}/${STA_LIBXSLT_NAME}.gen.pri ${PRICOMPFILE})
file(WRITE ${PWD}/${STA_LIBXSLT_NAME}.gen.pri ${PRICOMPFILE})


#target_link_libraries(${PROJECT_NAME} /opt/local/libexec/qt4/lib/libQtCore.4.8.7.dylib )

#qt5_use_modules(${PROJECT_NAME} Core)

#add_library(${SHA_LIBXSLT_NAME} SHARED ${SRC_FILES})
#target_link_libraries(${SHA_LIBXSLT_NAME} Qt5::Core)

#add_library(${STA_LIBXSLT_NAME} STATIC ${SRC_FILES})
#target_link_libraries(${STA_LIBXSLT_NAME} Qt5::Core)
# only SHARED stamp version! 
#set_target_properties(${SHA_LIBXSLT_NAME} PROPERTIES VERSION ${MYLIB_VERSION_STRING} SOVERSION 1)















