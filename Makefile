#############################################################################
# Makefile for building: kalk.pro
# Generated by qmake (2.01a) (Qt 4.8.7) on: mar feb 6 18:26:37 2018
# Project:  kalk.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile kalk.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = GUI/IMPLEMENTATION/main.cpp \
		MODEL/IMPLEMENTATION/Dataset.cpp \
		MODEL/IMPLEMENTATION/Set.cpp \
		MODEL/IMPLEMENTATION/UniverseDataset.cpp \
		MODEL/IMPLEMENTATION/UniverseSet.cpp \
		GUI/IMPLEMENTATION/kalkmainwindow.cpp \
		MODEL/IMPLEMENTATION/ris.cpp \
		GUI/IMPLEMENTATION/extrapanel.cpp \
		MODEL/IMPLEMENTATION/kalk.cpp \
		MODEL/IMPLEMENTATION/advanced.cpp \
		MODEL/IMPLEMENTATION/UniverseAdvanced.cpp \
		GUI/IMPLEMENTATION/qcustomplot.cpp \
		MODEL/IMPLEMENTATION/numbers.cpp moc_kalkmainwindow.cpp \
		moc_extrapanel.cpp \
		moc_qcustomplot.cpp
OBJECTS       = main.o \
		Dataset.o \
		Set.o \
		UniverseDataset.o \
		UniverseSet.o \
		kalkmainwindow.o \
		ris.o \
		extrapanel.o \
		kalk.o \
		advanced.o \
		UniverseAdvanced.o \
		qcustomplot.o \
		numbers.o \
		moc_kalkmainwindow.o \
		moc_extrapanel.o \
		moc_qcustomplot.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		kalk.pro
QMAKE_TARGET  = kalk.pro
DESTDIR       = 
TARGET        = kalk.pro

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: kalk.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -o Makefile kalk.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -o Makefile kalk.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/kalk.pro1.0.0 || $(MKDIR) .tmp/kalk.pro1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/kalk.pro1.0.0/ && $(COPY_FILE) --parents MODEL/HEADER/advanced.h MODEL/HEADER/Dataset.h MODEL/HEADER/Set.h MODEL/HEADER/UniverseDataset.h MODEL/HEADER/UniverseSet.h GUI/HEADER/kalkmainwindow.h MODEL/HEADER/numbers.h GUI/HEADER/extrapanel.h MODEL/HEADER/kalk.h MODEL/HEADER/UniverseAdvanced.h GUI/HEADER/qcustomplot.h .tmp/kalk.pro1.0.0/ && $(COPY_FILE) --parents GUI/IMPLEMENTATION/main.cpp MODEL/IMPLEMENTATION/Dataset.cpp MODEL/IMPLEMENTATION/Set.cpp MODEL/IMPLEMENTATION/UniverseDataset.cpp MODEL/IMPLEMENTATION/UniverseSet.cpp GUI/IMPLEMENTATION/kalkmainwindow.cpp MODEL/IMPLEMENTATION/ris.cpp GUI/IMPLEMENTATION/extrapanel.cpp MODEL/IMPLEMENTATION/kalk.cpp MODEL/IMPLEMENTATION/advanced.cpp MODEL/IMPLEMENTATION/UniverseAdvanced.cpp GUI/IMPLEMENTATION/qcustomplot.cpp MODEL/IMPLEMENTATION/numbers.cpp .tmp/kalk.pro1.0.0/ && (cd `dirname .tmp/kalk.pro1.0.0` && $(TAR) kalk.pro1.0.0.tar kalk.pro1.0.0 && $(COMPRESS) kalk.pro1.0.0.tar) && $(MOVE) `dirname .tmp/kalk.pro1.0.0`/kalk.pro1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/kalk.pro1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_kalkmainwindow.cpp moc_extrapanel.cpp moc_qcustomplot.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_kalkmainwindow.cpp moc_extrapanel.cpp moc_qcustomplot.cpp
moc_kalkmainwindow.cpp: MODEL/HEADER/kalk.h \
		MODEL/HEADER/numbers.h \
		MODEL/HEADER/UniverseSet.h \
		MODEL/HEADER/Set.h \
		MODEL/HEADER/UniverseDataset.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/UniverseAdvanced.h \
		MODEL/HEADER/advanced.h \
		GUI/HEADER/qcustomplot.h \
		GUI/HEADER/extrapanel.h \
		GUI/HEADER/kalkmainwindow.h \
		GUI/HEADER/kalkmainwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/HEADER/kalkmainwindow.h -o moc_kalkmainwindow.cpp

moc_extrapanel.cpp: GUI/HEADER/kalkmainwindow.h \
		MODEL/HEADER/kalk.h \
		MODEL/HEADER/numbers.h \
		MODEL/HEADER/UniverseSet.h \
		MODEL/HEADER/Set.h \
		MODEL/HEADER/UniverseDataset.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/UniverseAdvanced.h \
		MODEL/HEADER/advanced.h \
		GUI/HEADER/qcustomplot.h \
		GUI/HEADER/extrapanel.h \
		GUI/HEADER/extrapanel.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/HEADER/extrapanel.h -o moc_extrapanel.cpp

moc_qcustomplot.cpp: GUI/HEADER/qcustomplot.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GUI/HEADER/qcustomplot.h -o moc_qcustomplot.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: GUI/IMPLEMENTATION/main.cpp GUI/HEADER/kalkmainwindow.h \
		MODEL/HEADER/kalk.h \
		MODEL/HEADER/numbers.h \
		MODEL/HEADER/UniverseSet.h \
		MODEL/HEADER/Set.h \
		MODEL/HEADER/UniverseDataset.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/UniverseAdvanced.h \
		MODEL/HEADER/advanced.h \
		GUI/HEADER/qcustomplot.h \
		GUI/HEADER/extrapanel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o GUI/IMPLEMENTATION/main.cpp

Dataset.o: MODEL/IMPLEMENTATION/Dataset.cpp MODEL/HEADER/Dataset.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Dataset.o MODEL/IMPLEMENTATION/Dataset.cpp

Set.o: MODEL/IMPLEMENTATION/Set.cpp MODEL/HEADER/Set.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Set.o MODEL/IMPLEMENTATION/Set.cpp

UniverseDataset.o: MODEL/IMPLEMENTATION/UniverseDataset.cpp MODEL/HEADER/UniverseDataset.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UniverseDataset.o MODEL/IMPLEMENTATION/UniverseDataset.cpp

UniverseSet.o: MODEL/IMPLEMENTATION/UniverseSet.cpp MODEL/HEADER/UniverseSet.h \
		MODEL/HEADER/Set.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UniverseSet.o MODEL/IMPLEMENTATION/UniverseSet.cpp

kalkmainwindow.o: GUI/IMPLEMENTATION/kalkmainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kalkmainwindow.o GUI/IMPLEMENTATION/kalkmainwindow.cpp

ris.o: MODEL/IMPLEMENTATION/ris.cpp MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ris.o MODEL/IMPLEMENTATION/ris.cpp

extrapanel.o: GUI/IMPLEMENTATION/extrapanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o extrapanel.o GUI/IMPLEMENTATION/extrapanel.cpp

kalk.o: MODEL/IMPLEMENTATION/kalk.cpp MODEL/HEADER/kalk.h \
		MODEL/HEADER/numbers.h \
		MODEL/HEADER/UniverseSet.h \
		MODEL/HEADER/Set.h \
		MODEL/HEADER/UniverseDataset.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/UniverseAdvanced.h \
		MODEL/HEADER/advanced.h \
		GUI/HEADER/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kalk.o MODEL/IMPLEMENTATION/kalk.cpp

advanced.o: MODEL/IMPLEMENTATION/advanced.cpp MODEL/HEADER/advanced.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o advanced.o MODEL/IMPLEMENTATION/advanced.cpp

UniverseAdvanced.o: MODEL/IMPLEMENTATION/UniverseAdvanced.cpp MODEL/HEADER/UniverseAdvanced.h \
		MODEL/HEADER/advanced.h \
		MODEL/HEADER/Dataset.h \
		MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UniverseAdvanced.o MODEL/IMPLEMENTATION/UniverseAdvanced.cpp

qcustomplot.o: GUI/IMPLEMENTATION/qcustomplot.cpp GUI/HEADER/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qcustomplot.o GUI/IMPLEMENTATION/qcustomplot.cpp

numbers.o: MODEL/IMPLEMENTATION/numbers.cpp MODEL/HEADER/numbers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o numbers.o MODEL/IMPLEMENTATION/numbers.cpp

moc_kalkmainwindow.o: moc_kalkmainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_kalkmainwindow.o moc_kalkmainwindow.cpp

moc_extrapanel.o: moc_extrapanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_extrapanel.o moc_extrapanel.cpp

moc_qcustomplot.o: moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qcustomplot.o moc_qcustomplot.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

