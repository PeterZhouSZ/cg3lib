exists($$(LIBIGL_HOME)){
    DEFINES += CG3_LIBIGL_DEFINED
    CONFIG += CG3_LIBIGL
    MODULES += CG3_LIBIGL

    exists($$(LIBIGL_STATIC_HOME)){
        #comment next line if libigl is not used in static mode
        #CONFIG += LIBIGL_STATIC
    }

    !contains(DEFINES, CG3_CORE_DEFINED){
        error(Igl module requires common module!)
    }

    unix:!macx{
        LIBS += -lboost_system -DBOOST_LOG_DYN_LINK -lboost_log -lboost_thread -lpthread
        INCLUDEPATH += $$(LIBIGL_HOME)/include/

        QMAKE_CXXFLAGS += -isystem $$(LIBIGL_HOME)/include/

        #newest versions of eigen are not supported by libigl
        #INCLUDEPATH -= /usr/include/eigen3
        #INCLUDEPATH += $$(LIBIGL_HOME)/external/nanogui/ext/eigen/

        LIBIGL_STATIC {
            DEFINES += IGL_STATIC_LIBRARY
            LIBS += -L$$(LIBIGL_STATIC_HOME) -ligl_cgal -ligl
        }
    }

    HEADERS += \
        $$PWD/libigl/internal/eigenmesh_libigl_algorithms.h \
        $$PWD/libigl/is_edge_manifold.h \
        $$PWD/libigl/is_vertex_manifold.h \
        $$PWD/libigl/face_adjacences.h \
        $$PWD/libigl/extract_manifold_patches.h \
        $$PWD/libigl/booleans.h\
        $$PWD/libigl/decimate.h \
        $$PWD/libigl/remove_unreferenced_vertices.h \
        $$PWD/libigl/connected_components.h \
        $$PWD/libigl/remove_duplicate_vertices.h\
        $$PWD/libigl/libigl.h

    SOURCES += \
        $$PWD/libigl/internal/eigenmesh_libigl_algorithms.cpp \
        $$PWD/libigl/is_edge_manifold.cpp \
        $$PWD/libigl/is_vertex_manifold.cpp \
        $$PWD/libigl/face_adjacences.cpp \
        $$PWD/libigl/extract_manifold_patches.cpp \
        $$PWD/libigl/booleans.cpp\
        $$PWD/libigl/decimate.cpp \
        $$PWD/libigl/remove_unreferenced_vertices.cpp \
        $$PWD/libigl/connected_components.cpp \
        $$PWD/libigl/remove_duplicate_vertices.cpp
}



