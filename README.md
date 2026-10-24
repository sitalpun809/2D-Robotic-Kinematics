# 2D Forward Kinematics (2-Link Robotic Arm)

A C project that calculates the exact Cartesian coordinates $(x, y)$ of a 2-link robotic arm's end-effector (fingertip) based on joint angles and link lengths. The system models physical kinematics using trigonometric rotation matrices, homogeneous transformations, and modular C architecture.

---

## Table of Contents
- [Physics & Mathematics](#physics--mathematics)
  - [Forward Kinematics Overview](#forward-kinematics-overview)
  - [Homogeneous Transformation Matrix](#homogeneous-transformation-matrix)
- [Project Architecture](#project-architecture)
- [Building & Running](#building--running)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Execution](#execution)
- [Example Usage](#example-usage)

---

## Physics & Mathematics

### Forward Kinematics Overview
Forward Kinematics solves the direct mapping problem: given joint angles $(\theta_1, \theta_2)$ and link lengths $(L_1, L_2)$, determine the Cartesian position $(x, y)$ of the end-effector relative to the base origin $(0,0)$.

The geometric equations for the 2-link planar arm are:

$$x = L_1 \cos(\theta_1) + L_2 \cos(\theta_1 + \theta_2)$$
$$y = L_1 \sin(\theta_1) + L_2 \sin(\theta_1 + \theta_2)$$

Where:
* $L_1, L_2$: Lengths of Link 1 and Link 2.
* $\theta_1$: Absolute joint angle of Link 1 relative to the positive x-axis.
* $\theta_2$: Relative joint angle of Link 2 with respect to Link 1.

---

### Homogeneous Transformation Matrix
To generalize multi-link transformations linearly, each link is modeled using a $3 \times 3$ homogeneous transformation matrix $T_i$:

$$T_i = \begin{bmatrix} 
\cos\theta_i & -\sin\theta_i & L_i \cos\theta_i \\ 
\sin\theta_i & \cos\theta_i & L_i \sin\theta_i \\ 
0 & 0 & 1 
\end{bmatrix}$$

Multiplying the transformation matrices yields the complete forward kinematics transform:

$$T_{\text{total}} = T_1 \cdot T_2$$

The final Cartesian coordinates $(x, y)$ are extracted directly from the translation column of $T_{\text{total}}$:
* $x = T_{\text{total}}[0][2]$
* $y = T_{\text{total}}[1][2]$

---

## Project Architecture

The repository is modularly structured across clean header and implementation files:

| File | Purpose |
| :--- | :--- |
| `matrix.h` | Header file defining the `Matrix3x3` structure and custom function prototypes. |
| `matrix.c` | Implements matrix multiplication, transformation generation, and matrix printing logic. |
| `main.c` | Handles user inputs, angle conversions (degrees to radians), matrix chaining, and output display. |

---

## Building & Running

### Prerequisites
* A C compiler (`gcc` or `clang`).
* Standard C Math Library (`libm`).

### Compilation
Compile all `.c` source files together using `gcc`:

```bash
gcc main.c matrix.c -o fk_arm -lm
```

> **Note:** The `-lm` flag links C's standard math library required for trigonometric functions (`cos`, `sin`).

### Execution
Run the compiled executable using the `./` current directory prefix:

```bash
./fk_arm
```

---

## Example Usage

```text
Enter the length for the Link 1(L1): 5 
Enter the length for the Link 2(L2): 3
Enter the angle for the joint 1(in degree): 45
Enter the angle for the joint 2(in degree): 30
-------------------------------
Final transformation matrix: 
[  0.2588 -0.9659  4.3120]
[  0.9659  0.2588  6.4333]
[  0.0000  0.0000  1.0000]
End-factor position:
x = 4.312
y = 6.433
-------------------------------
```

---

## Author
Created by **Sital Pun**