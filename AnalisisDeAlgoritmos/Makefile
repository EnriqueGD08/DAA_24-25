# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Diseño y Análisis de Algoritmos
# Curso: 3º
# Práctica 1
# Autor: Enrique Gómez Díaz
# Correo: alu0101550329@ull.edu.es
# Fecha: 11/02/2025
# archivo Makefile para compilar el programa

# Nombre del compilador
CXX = g++

# Directorios
SRC_DIR = src
BUILD_DIR = build

# Bandera del compilador
CXXFLAGS = -w -o -c -Wall -g -Wextra -pedantic -std=c++11

# Archivo ejecutable
TARGET = $(BUILD_DIR)/comparacionMultiplicacionMatrices

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
