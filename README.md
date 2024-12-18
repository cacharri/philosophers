# Philosophers

El proyecto **Philosophers** es parte del currículo de 42 y tiene como objetivo explorar el problema clásico de los **filósofos comensales**, un problema fundamental en el estudio de la concurrencia y los sistemas distribuidos.

---

## 🚀 Descripción del Proyecto

El proyecto consiste en implementar una simulación del problema de los filósofos comensales utilizando threads y mutexes en C. El propósito es garantizar que los filósofos puedan comer y pensar sin caer en condiciones como **deadlocks** o **race conditions**, respetando las restricciones del problema.

---

## 🔧 Requisitos

### Entrada
- Número de filósofos.
- Tiempo hasta morir de hambre.
- Tiempo que tarda en comer.
- Tiempo que tarda en pensar.
- Opcional: número de veces que cada filósofo debe comer.

### Salida
- Eventos de los filósofos como "pensando", "comiendo", y "murió".

---

## 📁 Estructura del Proyecto

```plaintext
philosophers/
├── srcs/           # Código fuente principal
├── includes/       # Archivos de cabecera
├── Makefile        # Sistema de compilación
└── README.md       # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/philosophers.git
   cd philosophers
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta el programa:
   ```bash
   ./philo [número de filósofos] [tiempo hasta morir] [tiempo para comer] [tiempo para pensar] [veces que deben comer (opcional)]
   ```

   **Ejemplo:**
   ```bash
   ./philo 5 800 200 200
   ```

---

## 🌟 Características

- Manejo eficiente de concurrencia utilizando **threads**.
- Sincronización precisa mediante **mutexes**.
- Prevención de **deadlocks** y manejo de estados de carrera.

---

## 🧪 Testing

Puedes probar configuraciones diferentes para observar el comportamiento de los filósofos:

```bash
./philo 5 600 200 200
./philo 3 310 100 100 5
```

Prueba límites extremos para comprobar la robustez del programa.

---
