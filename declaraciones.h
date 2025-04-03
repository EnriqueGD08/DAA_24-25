#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

const float INFINITO = std::numeric_limits<float>::max();

class Algoritmo {
 public:
  Algoritmo(Problema problema) : problema_(problema) {}
  virtual ~Algoritmo() {}
  virtual void resolver() = 0;
  Solucion obtener_solucion() const {
    return solucion_;
  }
 
 protected:
  Problema problema_;
  Solucion solucion_;
  int puede_visitar(Nodo& nodo, float tiempo_actual, float carga_actual);
};

class Grafo {
 public:
  Grafo() {}
  Grafo(int velocidad): velocidad_(velocidad) {}
  ~Grafo() {}
  float calcular_coste(int vertice1, int vertice2) {
    return adyacencias_[vertice1].first.get_posicion().calcular_distancia(adyacencias_[vertice2].first.get_posicion()) * velocidad_;
  }
  float calcular_coste_basura(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_descarga(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }
  float calcular_coste_deposito(int vertice1, int vertice2) { return calcular_coste(vertice1, vertice2); }

  void agregar_adyacencia(const Nodo& nodo) {
    adyacencias_.emplace_back(nodo, 1);
  }

  std::vector<std::pair<Nodo, float>>& get_adyacencias() {
    return adyacencias_;
  }

  void print() const {
    std::cout << "Grafo:" << std::endl;
    for (const auto& adyacencia : adyacencias_) {
      std::cout << "Nodo: " << adyacencia.first.get_id() << ", Peso: " << adyacencia.first.get_peso() << std::endl;
    }
  }

  void set_velocidad(int velocidad) {
    velocidad_ = velocidad;
  }

 private:
  std::vector<std::pair<Nodo, float>> adyacencias_;
  int velocidad_;
};

class GRASP : public Algoritmo {
 public:
  GRASP(Problema problema) : Algoritmo(problema) {}
  ~GRASP() {}
  void resolver() override;
};

class Nodo {
 public:
  Nodo(int id = 0, Posicion posicion = Posicion(), float peso = 0)
      : identificador_(id), posicion_(posicion), peso_(peso) {}
  ~Nodo() {}
  int get_id() const { return identificador_; }
  int get_peso() const { return peso_; }
  Posicion get_posicion() const { return posicion_; }

  bool operator==(const Nodo& otro) const { return identificador_ == otro.identificador_; }
 
 private:
  Posicion posicion_;
  int peso_;
  int identificador_;
};

class Posicion {
 public:
  Posicion(float x = 0, float y = 0) : x_(x), y_(y) {}
  ~Posicion() {}
  float calcular_distancia(const Posicion& posicion) {
    return abs(static_cast<int>(x_) - static_cast<int>(posicion.x_)) + abs(static_cast<int>(y_) - static_cast<int>(posicion.y_));
  }
  float get_x() const { return x_; }
  float get_y() const { return y_; }

 private:
  float x_;
  float y_;
};

class Problema {
  public:
   Problema(float tiempo_maximo, float peso_maximo, Grafo grafo, Nodo deposito, int velocidad):
            tiempo_maximo_(tiempo_maximo), peso_maximo_(peso_maximo), grafo_(grafo),
            deposito_(deposito), velocidad_(velocidad) {grafo_.set_velocidad(velocidad_);}
   ~Problema() {}
   float obtener_tiempo_maximo() const { return tiempo_maximo_; }
   float obtener_peso_maximo() const { return peso_maximo_; }
   Grafo& obtener_grafo() { return grafo_; }
   Nodo obtener_deposito() const { return deposito_; }
   std::vector<Nodo> obtener_nodos() const { return nodos_; }
   void agregar_nodo(Nodo nodo) { grafo_.agregar_adyacencia(nodo);
                                 nodos_.push_back(nodo); } 
 
  private:
   float tiempo_maximo_;
   float peso_maximo_;
   int velocidad_;
   Grafo grafo_;
   Nodo deposito_;
   std::vector<Nodo> nodos_;
 };

class Solucion {
public:
  Solucion() : subrutas_(0) {}
  ~Solucion() {}

  void agregar_camion() { camiones_++; }

  void set_nodos(const std::vector<Nodo>& nodos) { nodos_ = nodos; }
  void set_subrutas(int subrutas) { subrutas_ = subrutas; }
  const std::vector<Nodo>& get_nodos() const { return nodos_; }
  int get_subrutas() const { return subrutas_; }
  int get_camiones() const { return camiones_; }

private:
  std::vector<Nodo> nodos_;
  int subrutas_;
  int camiones_ = 0;
};

class Voraz : public Algoritmo {
  public:
   Voraz(Problema problema) : Algoritmo(problema) {}
   ~Voraz() {}
   void resolver() override;
 };
 
Problema leer_archivo(const std::string& nombre_archivo);
void mostrar_solucion(const Solucion& solucion);