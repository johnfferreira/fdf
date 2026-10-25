# FdF (Fil de Fer)

**FdF** is a 42 school project focused on creating a simple 3D wireframe mesh generator. The program reads a coordinate map file (`.fdf`) containing altitude data and renders a graphic isometric projection of the landscape using the MiniLibX library.

---

## Key Features

* **Map Parsing:** Efficiently reads and validates coordinates and altitude heights from `.fdf` text files.
* **Line Drawing Algorithm:** Implementation of **Bresenham's line algorithm** (or DDA) to draw smooth lines connecting the grid dots.
* **Isometric Projection:** Converts 3D space coordinates $(X, Y, Z)$ into a 2D screen coordinate window mapping.
* **Color Blending:** Colors render dynamically based on altitude changes or custom map hex codes.

---

## Core Concepts Learned

* **Graphical Rendering:** Pixel manipulation via custom window image buffers in MiniLibX.
* **Matrix Coordinates:** Transforming and scaling three-dimensional vector mathematical spaces.
* **Performance Tuning:** Handling thousands of line renderings without leaking memory or causing screen frame stuttering.

---

## How to Use

**1. Clone and compile the project:**
```bash
make
```

**2. Execute the engine with a map file:**
```bash
./fdf maps/42.fdf
```
*(You can try various presets inside your map folder directories).*

**3. Completely clean all tracking objects:**
```bash
make fclean
```

---
 *Developed in full compliance with the 42 School Norm.*
