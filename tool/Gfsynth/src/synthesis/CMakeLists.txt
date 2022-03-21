set (CMAKE_CXX_STANDARD 14)

add_library(synthesis SHARED ExplicitStateDfa.cpp InputOutputPartition.cpp Stopwatch.cpp SymbolicStateDfa.cpp VarMgr.cpp LTLfGR1Synthesizer.cpp)
include_directories(${CUDD_INCLUDE_DIRS})

add_executable(Gfsynth Main.cpp)

target_link_libraries(Gfsynth synthesis ${CUDD_LIBRARIES})

install(TARGETS Gfsynth synthesis
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  )

INSTALL (
  DIRECTORY ${CMAKE_SOURCE_DIR}/src/synthesis
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
