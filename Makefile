# Makefile for the lib3DGeo libray.
# Version: 1
#
# Authors      : Xavier Schmerber, Jean-Philippe Clipffel
# Creation date: 14/11/2014
# Last modified: 14/11/2014
#
#
# lib3DGeo
# Copyright (C) 2014 Xavier Schmerber
# Email: xavier.schmerber@gmail.com
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
# USA


# Variables
# =========
NAME 							= 		lib3DGeo.so
LIB_NAME 					= 		lib3DGeo.so
LIB_VERSION 			= 		1

PATH_ROOT 				= 		.
PATH_SOURCE 			= 		./source/3DGeo
PATH_INCLUDE 			= 		./include/3DGeo

INCLUDE 					= 		./include

INSTALL_LIB 			= 		/usr/local/lib
INSTALL_INCLUDE 	= 		/usr/local/include
INSTALL_SOURCES 	=			/usr/src/lib3DGeo



# lib3DGeo sources
# ================
SRC_3DGEO					=			$(PATH_SOURCE)/angle.cpp				\
												$(PATH_SOURCE)/gps.cpp					\
												$(PATH_SOURCE)/maths.cpp				\
												$(PATH_SOURCE)/orientation.cpp	\
												$(PATH_SOURCE)/position.cpp			\
												$(PATH_SOURCE)/vect.cpp


# Compilation options
# ===================
CC 						=		g++
CFLAGS 				=		-W -Wall -ansi -pedantic -O3
CLIBS 				=
3DGEOFLAGS		=


# Rules configuration
# ====================
.PHONY: 	help build clean 																				\
					install install-headers install-library install-sources \
					remove remove-headers remove-library remove-sources

.SILENT:	help build clean 																				\
					install install-headers install-library install-sources \
					remove remove-headers remove-library remove-sources



# Basic rules
# ===========
$(NAME):	help

help:
			@echo "lib3DGeo Makefile help"
			@echo "======================"

			@echo "See bellow for generic help. For help about using lib3DGeo, type 'make help-usage'"
			@echo ""
			@echo "[*] Compilation"
			@echo "    Type 'make build' to build the library. '$(LIB_NAME)' is then created."
			@echo ""
			@echo "[*] Installation"
			@echo "   To install the whole package (except sources): 'make install'"
			@echo "   To install only the headers: 'make install-headers'"
			@echo "   To install only the library: 'make install-library'"
			@echo "   To install the sources (disable by default): 'make install-sources'"
			@echo ""
			@echo "[*] Removing"
			@echo "   To remove the whole installation (except sources): 'make remove'"
			@echo "   To remove only the headers: 'make remove-headers'"
			@echo "   To remove only the library: 'make remove-library'"
			@echo "   To remove the sources (disable by default): 'make remove-sources'"
			@echo ""
			@echo "[*] Other"
			@echo "    You can remove temporary files using 'make clean'"

help-usage:
			@echo "Compile with lib3DGeo"
			@echo "====================="
			@echo ""
			@echo "You have two options:"
			@echo "1) Add $(INSTALL_LIB) to your LD_LIBRAY_PATH variable:"
			@echo "   'export LD_LIBRARY_PATH=/usr/local/lib:\$$LD_LIBRARY_PATH'"
			@echo "   From now, compile with 'g++ <sources> -l3DGeo'"
			@echo "OR"
			@echo "2) Compile with:"
			@echo "   'g++ <sources> -l3DGeo -Wl,-rpath $(INSTALL_LIB)'"


# Compilation rules
# =================
build:
			@echo "--------------------------------------------"
			@echo "Compiling $(LIB_NAME) version $(LIB_VERSION)"
			@echo "Compiler       : $(CC)"
			@echo "Compiler flags : $(CFLAGS)"
			@echo "KNM flags      : $(KNMFLAGS)"
			@echo "Libraires      : $(CLIBS)"
			@echo "--------------------------------------------"
			$(CC) $(CFLAGS) $(CLIBS) $(3DGEOFLAGS) -I $(INCLUDE) -fPIC -shared $(SRC_3DGEO) -o $(NAME)


# Installation rules
# ==================
install-headers:
			@echo "[*] Copying 3DGeo classes headers"
			mkdir -p $(INSTALL_INCLUDE)
			cp -r $(PATH_INCLUDE) $(INSTALL_INCLUDE)

			@echo "[*] Copying 3DGeo quick headers"
			cp $(QUICK_INCLUDES) $(INSTALL_INCLUDE)/KNM

install-library:
			@echo "[*] Copying 3DGEo library"
			cp $(LIB_NAME) $(INSTALL_LIB)/$(LIB_NAME)

install-sources:
			@echo "[*] Copying 3DGEo sources"
			mkdir -p $(INSTALL_SOURCES)
			cp -r $(PATH_SOURCE) $(INSTALL_SOURCES)/

install:
			@echo "---"
			@echo "Installing lib3DGeo version $(LIB_VERSION)"
			@echo "Library installation path: $(INSTALL_LIB)"
			@echo "Headers installation path: $(INSTALL_INCLUDE)"
			@echo "---"
			make --no-print-directory install-headers
			make --no-print-directory install-library
			@echo "Done."


# Removing & cleaning rules
# =========================
remove-headers:
			@echo "[*] Removing 3DGeo includes & headers"
			if [ -e $(INSTALL_INCLUDE) ]; then rm -r -I $(INSTALL_INCLUDE); fi

remove-library:
			@echo "[*] Removing 3DGeo library"
			if [ -e $(INSTALL_LIB)/$(LIB_NAME) ]; then rm -i $(INSTALL_LIB)/$(LIB_NAME); fi

remove-sources:
			@echo "[*] Removing 3DGeo sources"
			if [ -d $(INSTALL_SOURCES) ]; then rm -r -I $(INSTALL_SOURCES); fi

remove:
			@echo "---"
			@echo "Removing 3DGeo"
			@echo "Library installation path: $(INSTALL_LIB)"
			@echo "Headers installation path: $(INSTALL_INCLUDE)"
			@echo "---"
			make --no-print-directory remove-headers
			make --no-print-directory remove-library
			@echo "Done."

clean:
			if [ -e $(LIB_NAME) ]; then rm $(LIB_NAME); fi
