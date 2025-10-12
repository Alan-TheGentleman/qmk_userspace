# QMK Userspace - BastardKB Custom Keymaps

[English](#english) | [Español](#español)

---

## English

### Overview

This is a QMK Userspace repository containing custom keyboard configurations for BastardKB split ergonomic keyboards with integrated pointing devices (trackballs/cirque trackpads). The configurations are optimized for a comfortable typing experience with home row mods and intuitive layer switching.

### Keyboards Configured

#### 1. **Dilemma 4x6_4 Procyon**
- **Layout**: 4x6 split keyboard with 4 thumb keys per side
- **Pointing Device**: Cirque trackpad (Procyon variant)
- **Features**: RGB Matrix, Rotary Encoders

#### 2. **Charybdis 3x5**
- **Layout**: 3x5 compact split keyboard
- **Pointing Device**: Trackball
- **Features**: RGB Matrix, Auto Pointer Layer

### Key Features

#### Home Row Mods (GACS)
Both keyboards use home row modifications for comfortable access to modifiers:
- **G**ui (Super/Command)
- **A**lt
- **C**trl
- **S**hift

**Dilemma Layout** (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:54):
```
LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F)  // Left hand
RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN)  // Right hand
```

**Custom Tapping Terms**:
- GUI keys (A, ;): 180ms
- Shift keys (F, J): 120ms
- Alt/Ctrl keys (S, D, K, L): 200ms

#### Pointing Device Customizations

**Dilemma Procyon** - Inverted Vertical Scroll (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:144-147):
```c
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.v = -mouse_report.v;  // Invert scroll only, not cursor
    return mouse_report;
}
```

**Charybdis** - Auto Pointer Layer:
- Automatically activates pointer layer when trackball movement exceeds threshold
- 1000ms timeout after movement stops
- Visual feedback with RGB matrix (green color)

### Layer Structure

#### Dilemma 4x6_4 Procyon Layers

| Layer | Purpose | Key Features |
|-------|---------|--------------|
| **BASE** | QWERTY typing | Home row mods, numbers on top row |
| **MAGIC** | System controls | RGB controls, media keys, reset |
| **PROGRAMMING** | Symbols | Brackets, operators, special characters |
| **NUMBERS** | Numpad & Functions | F-keys on left, numpad on right |
| **NAV** | Navigation | Arrow keys, page up/down, home/end |
| **POINTER** | Trackpad controls | DPI adjustment, drag scroll, sniping |

**Layer Access**:
- `MAGIC`: Hold with thumb key (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:58)
- `PROG`: Hold thumb key
- `NUMBS`: Hold thumb key
- `NAV`: Layer-tap on Backspace (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:35)
- `POINTER`: Layer-tap on Z and / keys (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:36-37)

#### Charybdis 3x5 Layers

| Layer | Purpose | Key Features |
|-------|---------|--------------|
| **BASE** | QWERTY typing | Home row mods, compact 3x5 layout |
| **NUMERAL** | Numbers & Functions | F-keys mirrored with numbers |
| **CODING** | Programming symbols | Brackets, operators optimized for coding |
| **MEDIA** | Media & RGB | Volume, playback, RGB controls |
| **POINTER** | Trackball controls | DPI, drag scroll, sniping mode |
| **NAVIGATION** | Movement & Editing | Arrows, page nav, clipboard |

**Layer Access** (keyboards/bastardkb/charybdis/3x5/keymaps/vendor/keymap.c:47-51):
- `ESC_MED`: Layer-tap Escape for Media
- `SPC_COD`: Layer-tap Space for Coding
- `TAB_NUM`: Layer-tap Tab for Numeral
- `BSP_NAV`: Layer-tap Backspace for Navigation
- `POINTER`: Layer-tap on Z and / positions

### Encoder Configuration (Dilemma only)

**Left Encoder** (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:177):
- Base layer: Mouse wheel up/down
- Magic layer: RGB hue adjustment
- Other layers: Page up/down

**Right Encoder**:
- Base layer: Volume up/down
- Magic layer: RGB saturation adjustment
- Other layers: Volume up/down

### Configuration Details

#### Dilemma 4x6_4 Procyon (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/config.h:23-30)
```c
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define ENCODER_RESOLUTION 4
```

#### Charybdis 3x5 (keyboards/bastardkb/charybdis/3x5/keymaps/vendor/config.h:30-43)
```c
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
```

### Design Philosophy

This keymap configuration aims to:
1. **Minimize finger movement**: Home row mods keep hands on home position
2. **Intuitive layers**: Related functions grouped logically
3. **Comfortable ergonomics**: Split layout with natural hand positioning
4. **Efficient workflow**: Programming and navigation optimized for developers
5. **Integrated pointing**: Seamless trackball/trackpad integration without leaving keyboard

### Building the Firmware

#### Option 1: Using GitHub Actions (Recommended)

This repository is configured to automatically build firmware using GitHub Actions whenever you push to the repository.

**Configuring which keyboard to build:**

Edit the `qmk.json` file in the root directory to select which keyboard(s) to compile:

```json
{
    "userspace_version": "1.0",
    "build_targets": [
        ["bastardkb/dilemma/4x6_4_procyon", "vendor"],
        ["bastardkb/charybdis/3x5", "vendor"]
    ]
}
```

**To compile only one keyboard**, remove the other line:
- For **Dilemma only**: keep only `["bastardkb/dilemma/4x6_4_procyon", "vendor"]`
- For **Charybdis only**: keep only `["bastardkb/charybdis/3x5", "vendor"]`
- For **both keyboards**: keep both lines (current configuration)

After pushing your changes, GitHub Actions will automatically build the firmware. Download the compiled `.uf2` files from the Actions tab in your GitHub repository.

#### Option 2: Local Compilation

Follow the official BastardKB documentation:
[https://docs.bastardkb.com/fw/compile-firmware.html](https://docs.bastardkb.com/fw/compile-firmware.html)

**Quick build commands**:
```bash
# Dilemma 4x6_4 Procyon
qmk compile -kb bastardkb/dilemma/4x6_4_procyon -km vendor

# Charybdis 3x5
qmk compile -kb bastardkb/charybdis/3x5 -km vendor
```

### Contributing

Feel free to fork and adapt these keymaps to your needs. The configurations here represent a personal workflow optimized for software development with vim-style navigation.

---

## Español

### Descripción General

Este es un repositorio QMK Userspace que contiene configuraciones personalizadas para teclados ergonómicos divididos de BastardKB con dispositivos apuntadores integrados (trackballs/trackpads cirque). Las configuraciones están optimizadas para una experiencia de escritura cómoda con modificadores en la fila principal e intercambio intuitivo de capas.

### Teclados Configurados

#### 1. **Dilemma 4x6_4 Procyon**
- **Distribución**: Teclado dividido 4x6 con 4 teclas de pulgar por lado
- **Dispositivo Apuntador**: Trackpad Cirque (variante Procyon)
- **Características**: Matriz RGB, Encoders Rotativos

#### 2. **Charybdis 3x5**
- **Distribución**: Teclado dividido compacto 3x5
- **Dispositivo Apuntador**: Trackball
- **Características**: Matriz RGB, Capa de Puntero Automática

### Características Principales

#### Modificadores en Fila Principal (GACS)
Ambos teclados utilizan modificaciones en la fila principal para acceso cómodo a los modificadores:
- **G**ui (Super/Command)
- **A**lt
- **C**trl
- **S**hift

**Distribución Dilemma** (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:54):
```
LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F)  // Mano izquierda
RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN)  // Mano derecha
```

**Tiempos de Tapping Personalizados**:
- Teclas GUI (A, ;): 180ms
- Teclas Shift (F, J): 120ms
- Teclas Alt/Ctrl (S, D, K, L): 200ms

#### Personalizaciones del Dispositivo Apuntador

**Dilemma Procyon** - Scroll Vertical Invertido (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:144-147):
```c
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.v = -mouse_report.v;  // Invierte solo el scroll, no el cursor
    return mouse_report;
}
```

**Charybdis** - Capa de Puntero Automática:
- Activa automáticamente la capa de puntero cuando el movimiento del trackball excede el umbral
- Timeout de 1000ms después de detener el movimiento
- Retroalimentación visual con matriz RGB (color verde)

### Estructura de Capas

#### Capas Dilemma 4x6_4 Procyon

| Capa | Propósito | Características Clave |
|------|-----------|----------------------|
| **BASE** | Escritura QWERTY | Modificadores en fila principal, números en fila superior |
| **MAGIC** | Controles del sistema | Controles RGB, teclas multimedia, reset |
| **PROGRAMMING** | Símbolos | Paréntesis, operadores, caracteres especiales |
| **NUMBERS** | Teclado numérico y funciones | Teclas F a la izquierda, teclado numérico a la derecha |
| **NAV** | Navegación | Flechas, avance/retroceso de página, inicio/fin |
| **POINTER** | Controles del trackpad | Ajuste de DPI, scroll con arrastre, modo precisión |

**Acceso a Capas**:
- `MAGIC`: Mantener con tecla del pulgar (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:58)
- `PROG`: Mantener tecla del pulgar
- `NUMBS`: Mantener tecla del pulgar
- `NAV`: Layer-tap en Retroceso (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:35)
- `POINTER`: Layer-tap en teclas Z y / (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:36-37)

#### Capas Charybdis 3x5

| Capa | Propósito | Características Clave |
|------|-----------|----------------------|
| **BASE** | Escritura QWERTY | Modificadores en fila principal, diseño compacto 3x5 |
| **NUMERAL** | Números y funciones | Teclas F reflejadas con números |
| **CODING** | Símbolos de programación | Paréntesis, operadores optimizados para código |
| **MEDIA** | Media y RGB | Volumen, reproducción, controles RGB |
| **POINTER** | Controles del trackball | DPI, scroll con arrastre, modo precisión |
| **NAVIGATION** | Movimiento y edición | Flechas, navegación de página, portapapeles |

**Acceso a Capas** (keyboards/bastardkb/charybdis/3x5/keymaps/vendor/keymap.c:47-51):
- `ESC_MED`: Layer-tap Escape para Media
- `SPC_COD`: Layer-tap Espacio para Coding
- `TAB_NUM`: Layer-tap Tab para Numeral
- `BSP_NAV`: Layer-tap Retroceso para Navigation
- `POINTER`: Layer-tap en posiciones Z y /

### Configuración de Encoders (Solo Dilemma)

**Encoder Izquierdo** (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/keymap.c:177):
- Capa base: Rueda del ratón arriba/abajo
- Capa Magic: Ajuste de matiz RGB
- Otras capas: Página arriba/abajo

**Encoder Derecho**:
- Capa base: Volumen arriba/abajo
- Capa Magic: Ajuste de saturación RGB
- Otras capas: Volumen arriba/abajo

### Detalles de Configuración

#### Dilemma 4x6_4 Procyon (keyboards/bastardkb/dilemma/4x6_4_procyon/keymaps/vendor/config.h:23-30)
```c
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define ENCODER_RESOLUTION 4
```

#### Charybdis 3x5 (keyboards/bastardkb/charybdis/3x5/keymaps/vendor/config.h:30-43)
```c
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
```

### Filosofía de Diseño

Esta configuración de keymap busca:
1. **Minimizar movimiento de dedos**: Modificadores en fila principal mantienen las manos en posición de reposo
2. **Capas intuitivas**: Funciones relacionadas agrupadas lógicamente
3. **Ergonomía cómoda**: Diseño dividido con posicionamiento natural de las manos
4. **Flujo de trabajo eficiente**: Programación y navegación optimizadas para desarrolladores
5. **Apuntador integrado**: Integración perfecta de trackball/trackpad sin dejar el teclado

### Compilar el Firmware

#### Opción 1: Usando GitHub Actions (Recomendado)

Este repositorio está configurado para compilar automáticamente el firmware usando GitHub Actions cada vez que hagas push al repositorio.

**Configurar qué teclado compilar:**

Edita el archivo `qmk.json` en el directorio raíz para seleccionar qué teclado(s) compilar:

```json
{
    "userspace_version": "1.0",
    "build_targets": [
        ["bastardkb/dilemma/4x6_4_procyon", "vendor"],
        ["bastardkb/charybdis/3x5", "vendor"]
    ]
}
```

**Para compilar solo un teclado**, elimina la otra línea:
- Para **solo Dilemma**: mantén únicamente `["bastardkb/dilemma/4x6_4_procyon", "vendor"]`
- Para **solo Charybdis**: mantén únicamente `["bastardkb/charybdis/3x5", "vendor"]`
- Para **ambos teclados**: mantén ambas líneas (configuración actual)

Después de hacer push de tus cambios, GitHub Actions compilará automáticamente el firmware. Descarga los archivos `.uf2` compilados desde la pestaña Actions en tu repositorio de GitHub.

#### Opción 2: Compilación Local

Sigue la documentación oficial de BastardKB:
[https://docs.bastardkb.com/fw/compile-firmware.html](https://docs.bastardkb.com/fw/compile-firmware.html)

**Comandos rápidos de compilación**:
```bash
# Dilemma 4x6_4 Procyon
qmk compile -kb bastardkb/dilemma/4x6_4_procyon -km vendor

# Charybdis 3x5
qmk compile -kb bastardkb/charybdis/3x5 -km vendor
```

### Contribuciones

Siéntete libre de hacer fork y adaptar estos keymaps a tus necesidades. Las configuraciones aquí representan un flujo de trabajo personal optimizado para desarrollo de software con navegación estilo vim.

---

## License

This repository follows the same GPL-2.0-or-later license as QMK Firmware.

Copyright notices are maintained in individual files as per original authors.
