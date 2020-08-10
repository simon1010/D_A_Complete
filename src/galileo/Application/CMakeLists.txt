set(INCROOT ${PROJECT_SOURCE_DIR}/include/Galileo/Application)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Galileo/Application)

# all source files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${Galileo_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${Galileo_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${Galileo_SOURCE_DIR}/bin")

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# Tell CMake to UI compiler when necessary:
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${Galileo_SOURCE_DIR}/design")

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
include_directories("${Galileo_SOURCE_DIR}/bin")

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

add_library(Application SHARED ${SRCS} ${INCS})

target_link_libraries(Application Framework qcustomplot Qt5::Widgets Qt5::Core Aquila iir)