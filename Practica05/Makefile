# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Diseño y Análisis de Algoritmos
# Curso: 3º
# Práctica 5
# Autor: Enrique Gómez Díaz
# Correo: alu0101550329@ull.edu.es
# Fecha: 25/03/2025
# archivo Makefile para compilar el programa

# Nombre del compilador
CXX = g++

# Directorios
SRC_DIR = src
HEADER_DIR = include
BUILD_DIR = build

# Bandera del compilador
CXXFLAGS = -w -o -c -Wall -g -O3 -Wextra -pedantic -std=c++17 -I$(HEADER_DIR)

# Archivo ejecutable
TARGET = recogida-basura

# Recoge todos los archivos .cc de la carpeta src
SRCS = $(wildcard $(SRC_DIR)/*.cc)

# Convierte los .cc en archivos objeto .o en la carpeta build
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS))

# Regla por defecto: compila el programa
all: $(TARGET)

# Regla para crear el ejecutable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar cada archivo .cc en su correspondiente archivo .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de limpieza
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
