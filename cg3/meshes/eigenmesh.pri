DEFINES += CG3_EIGENMESH_DEFINED
CONFIG += CG3_EIGENMESH
MODULES += CG3_EIGENMESH

!contains(DEFINES, CG3_CORE_DEFINED){
    error(EigenMesh module requires cg3_core with eigen!)
}

unix:!macx{
    LIBS += -lboost_system -DBOOST_LOG_DYN_LINK -lboost_log -lboost_thread -lpthread
}

HEADERS += \
    $$PWD/eigenmesh/simpleeigenmesh.h \
    $$PWD/eigenmesh/eigenmesh.h \
    $$PWD/eigenmesh/algorithms/eigenmesh_algorithms.h


SOURCES += \
    $$PWD/eigenmesh/simpleeigenmesh.cpp \
    $$PWD/eigenmesh/eigenmesh.cpp \
    $$PWD/eigenmesh/algorithms/eigenmesh_algorithms.cpp

