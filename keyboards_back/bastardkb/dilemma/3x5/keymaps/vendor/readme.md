# Dilemma (3x5) `vendor` keymap

The Dilemma (3x5) `vendor` keymap is based on a QWERTY layout with [home row mods](https://precondition.github.io/home-row-mods) and [Miryoku-inspired layers](https://github.com/manna-harbour/miryoku), and some features and changes specific to the Dilemma.

This layout supports RGB matrix. However, due to space constraints on the MCU, only a limited number of effect can be enabled at once. Look at the `config.h` file and enable your favorite effect.

This layout also supports VIA.

## Key Differences from Charybdis

The Dilemma uses a **Cirque trackpad** instead of a trackball, which provides:
- Touch-based pointer control instead of rolling ball movement
- Tap-to-click functionality
- Gesture support (if enabled in firmware)

## Customizing the keymap

### Dynamic DPI scaling

Use the following keycodes to change the default DPI:

-   `POINTER_DEFAULT_DPI_FORWARD` (aliased as `DPI_MOD`): increases the DPI; decreases when shifted;
-   `POINTER_DEFAULT_DPI_REVERSE` (aliased as `DPI_RMOD`): decreases the DPI; increases when shifted.

There's a maximum of 16 possible values for the default DPI. See the [Dilemma documentation](https://docs.bastardkb.com/bg_dilemma/customize.html) for more information.

Use the following keycodes to change the sniping mode DPI:

-   `POINTER_SNIPING_DPI_FORWARD` (aliased as `S_D_MOD`): increases the DPI; decreases when shifted;
-   `POINTER_SNIPING_DPI_REVERSE`: decreases the DPI; increases when shifted.

There's a maximum of 4 possible values for the sniping mode DPI. See the [Dilemma documentation](https://docs.bastardkb.com/bg_dilemma/customize.html) for more information.

### Drag-scroll

Use the `DRAGSCROLL_MODE` (aliased as `DRGSCRL`) keycode to enable drag-scroll on hold. Use the `DRAGSCROLL_TOGGLE` keycode to enable/disable drag-scroll on key press.

When drag-scroll is enabled, trackpad movements are converted to scroll wheel movements.

### Sniping

Use the `SNIPING_MODE` (aliased as `SNIPING`) keycode to enable sniping mode on hold. Use the `SNIPING_MODE_TOGGLE` (aliased as `SNP_TOG`) keycode to enable/disable sniping mode on key press.

Sniping mode slows down the pointer movement for precise control, perfect for detailed work or targeting small UI elements.

Change the value of `DILEMMA_AUTO_SNIPING_ON_LAYER` to automatically enable sniping mode on layer change. By default, sniping mode is enabled on the pointer layer:

```c
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER
```

### Auto pointer layer

The pointer layer can be automatically enabled when moving the trackpad. To enable or disable this behavior, add or remove the following define in `config.h`:

```c
#define DILEMMA_AUTO_POINTER_LAYER_TRIGGER_ENABLE
```

By default, the layer is turned off 1 second after the last registered trackpad movement:

```c
#define DILEMMA_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
```

The trigger sensibility can also be tuned. The lower the value, the more sensible the trigger:

```c
#define DILEMMA_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
```

## Layout

This keymap uses the same layout structure as the Charybdis, with 6 layers:

1. **Base Layer (QWERTY)**: Main typing layer with home row mods
2. **Navigation Layer**: Arrow keys, page up/down, home/end
3. **Numeral Layer**: Numbers and function keys
4. **Coding Layer**: Symbols and brackets for programming
5. **Media Layer**: Media controls and RGB settings
6. **Pointer Layer**: Trackpad controls (DPI, sniping, drag-scroll)

The layout is optimized for daily use with a Cirque trackpad, providing easy access to pointer controls while maintaining a comfortable typing experience.
