# Dilemma Max `vendor` keymap

Este keymap combina la configuración base del Dilemma con **home row mods** del Charybdis y capas adaptadas del Glove80.

## Home Row Mods (GACS)

Los home row mods están configurados con las mismas velocidades que el Charybdis:

**Mano izquierda:**
- **A** → GUI (180ms tapping term)
- **S** → ALT (200ms tapping term)
- **D** → CTRL (200ms tapping term)
- **F** → SHIFT (120ms tapping term)

**Mano derecha:**
- **J** → SHIFT (120ms tapping term)
- **K** → CTRL (200ms tapping term)
- **L** → ALT (200ms tapping term)
- **;** → GUI (180ms tapping term)

## Capas

Este keymap tiene 6 capas:

### 1. Base Layer (QWERTY)
- Layout QWERTY con home row mods
- **Thumb keys:**
  - Left: Mouse Click 1, Space, Programming layer, Numbers layer
  - Right: Magic layer, Enter, NAV layer (hold backspace), Mute
- **Acceso a Pointer layer:** Hold Z o /

### 2. Magic Layer (Media del Charybdis)
- **RGB Controls** (simétricos en ambas manos):
  - RGB_TOG, RGB_MOD, RGB_RMOD
- **Media controls** (simétricos en ambas manos):
  - Previous, Volume Down, Mute, Volume Up, Next
  - Play/Pause (KC_MPLY), Stop (KC_MSTP) en thumbs
- **Dynamic Typing:**
  - DT_UP, DT_DOWN, DT_PRNT
- **System:**
  - QK_BOOT (bootloader)
  - EE_CLR (EEPROM clear)
  - TO(0) (return to base)

### 3. Programming Layer
- **Símbolos para código:**
  - Brackets: `()`, `{}`, `[]`, `<>`
  - Operators: `@`, `#`, `%`, `&`, `*`, `$`
  - Special: `` ` ``, `^`, `=`, `!`, `\`, `?`, `-`

### 4. Numbers Layer
- **Números 1-9 y 0** en mano derecha
- **F-keys** (F1-F9) en mano izquierda
- **Mods** en home row para combos

### 5. NAV Layer
- **Navegación:**
  - Arrows: Left, Down, Up, Right
  - Home, End, PgUp, PgDn
  - Insert, Caps Lock
- **Mods** en home row izquierdo

### 6. Pointer Layer (estilo Charybdis)
- **DPI Controls** (top row, simétricos):
  - DPI_RMOD: Reverse DPI (con Shift invierte dirección)
  - DPI_MOD: Ajuste de DPI
  - S_D_MOD: Scroll/DPI modes
- **Mods en home row** (ambas manos):
  - GUI, ALT, CTRL, SHIFT para combos con mouse
- **Pointer modes** (bottom row):
  - DRGSCRL: Drag-scroll
  - SNIPING: Modo preciso
- **Mouse buttons** (thumbs, simétricos):
  - BTN2 (right click), BTN1 (left click), BTN3 (middle)
- Acceso: Hold Z o /

## Encoders

| Capa | Encoder Izquierdo | Encoder Derecho |
|------|-------------------|-----------------|
| Base | Scroll | Volume |
| Magic | RGB Hue | RGB Saturation |
| Programming | Page Up/Down | Volume |
| Numbers | Page Up/Down | Volume |
| NAV | Page Up/Down | Volume |
| Pointer | RGB Hue | RGB Saturation |

## Trackpad Cirque

### Natural Scroll (estilo macOS)

El trackpad está configurado con **natural scroll** (eje Y invertido), igual que macOS:
- Desliza hacia arriba → contenido sube
- Desliza hacia abajo → contenido baja

Para deshabilitar y volver a scroll tradicional, comenta en `config.h`:
```c
// #define POINTING_DEVICE_INVERT_Y
```

### DPI scaling

- **DPI_MOD**: Incrementa DPI
- **S_D_MOD**: Ajusta DPI de sniping

### Drag-scroll

- **DRGSCRL**: Activa drag-scroll
- Convierte movimientos en scroll

### Sniping mode

- **SNIPING**: Modo preciso
- Movimiento lento y controlado

### Auto-sniping

Para auto-activar sniping en la capa Pointer, descomenta en `keymap.c`:
```c
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER
```

## VIA Support

Soporta VIA con 6 capas configurables.

## Características técnicas

- **Tapping term base**: 120ms
- **Tapping term per key**: Personalizado para cada home row mod
- **Split features**: Layer state y LED state sincronizados
