# GLoBES
contains a GLoBES-based simulation to study neutrino oscillation probabilities and compute chi-squared (χ²) statistics across different experimental scenarios.

## Overview

We analyze:

- Neutrino oscillation probabilities (in vacuum and matter)
- CP-even appearance channels
- χ² behavior with and without systematics/correlations
- A two-experiment setup: NuFact@3000 km and NuFact@7500 km (magic baseline)

## Oscillation Probabilities

### In Vacuum (Initial Flavor: νₑ)

| Transition | Probability    |
|------------|----------------|
| 1 → 1      | 0.999955       |
| 1 → 2      | 2.59032e-05    |
| 1 → 3      | 1.924e-05      |

### In Matter

| Transition | Probability    |
|------------|----------------|
| 1 → 1      | 0.999965       |
| 1 → 2      | 1.99581e-05    |
| 1 → 3      | 1.48288e-05    |

## χ² Statistics (Single Experiment at 3000 km)

| Description                               | χ² Value  |
|-------------------------------------------|-----------|
| With systematics only                     | 21.6747   |
| CP-even appearance only                   | 20.4597   |
| All rules summed                          | 21.6747   |
| With correlations                         | 2.03269   |
| With non-δ<sub>CP</sub> correlations only | 4.03406   |
| With δ<sub>CP</sub> correlation only      | 2.79027   |
| With statistics only                      | 35.2241   |
| χ² at minimum                             | 4.55838   |

**Best-fit Oscillation Parameters (at χ² minimum):**

theta12 = 0.586039
theta13 = 0.0276251
theta23 = 0.724505
delta   = 1.04785
sdm     = 7.83936e-05
ldm     = -0.0019132
rho     = 0.977281
Iterations = 7435

**Note**: sin²2θ₁₃ fixed at 0.0015.

## Two-Experiment Setup: NuFact@3000 km + NuFact@7500 km

- **Magic baseline**: 7500 km
- **Average matter density**: 4.25286 g/cm³

### χ² Values with Systematics

| Experiment    | χ² Value  |
|---------------|-----------|
| Total (both)  | 28.2466   |
| 3000 km only  | 21.6747   |
| 7500 km only  | 6.57182   |

_Total matches the sum of individual contributions._

### χ² with Correlations

**3000 km Baseline:**

χ² = 2.03269
theta12 = 0.541392
theta13 = 0.0193698
theta23 = 0.745194
delta   = 1.74802
sdm     = 6.64569e-05
ldm     = 0.00200549
rho     = 1.00384
Iterations = 1963


**7500 km Baseline:**

χ² = 1.73017
theta12 = 0.557918
theta13 = 0.0193698
theta23 = 0.769648
delta   = 4.52235
sdm     = 6.98309e-05
ldm     = 0.0020012
rho     = 1.01884
Iterations = 1237

### Combined Correlation Fit

Combined χ² = 3.58266
theta12 = 0.543766
theta13 = 0.0193698
theta23 = 0.770083
delta   = 1.75695
sdm     = 6.61429e-05
ldm     = 0.00199925
rho     = 1.00389
Normalization = 1.03203
Iterations = 2404

**Note**: Sum of individual χ²s is 3.76286, slightly above the combined value due to correlations.

## χ² at Specific Points

| Scenario                                   | χ² Value  |
|--------------------------------------------|-----------|
| Minimum at 3000 km baseline                | 5.42618   |
| χ² for combination at that same parameter  | 58.3386   |

**Fit Parameters at 3000 km Minimum:**

theta12 = 0.594425
theta13 = 0.0222309
theta23 = 0.769443
delta   = 1.21436
sdm     = 8.07948e-05
ldm     = -0.00189549
rho     = 0.974845
Normalization = 1.14084
Iterations = 1112

## Requirements

Ensure the following dependencies are installed:

- [GLoBES](http://www.mpi-hd.mpg.de/personalhomes/globes/) (version ≥ 3.0.11)
- GCC with C99 complex number support
- GNU Scientific Library (`libgsl-dev`)
- GLib 2.0 (`libglib2.0-dev`)
- Bison and Flex (`bison`, `flex`)

### Compilation Example

```bash
gcc -o run_globes main.c -I/usr/local/include -L/usr/local/lib \
    -lglobes -lgsl -lgslcblas -lm
````

## References

* GLoBES User Manual: [GLoBES Website](https://www.mpi-hd.mpg.de/personalhomes/globes/)
* Magic baseline paper: [arXiv\:hep-ph/0109215](https://arxiv.org/abs/hep-ph/0109215)
