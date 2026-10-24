# STM32F4 Bare-Metal Journey

> **From AVR to ARM Cortex-M4, one register at a time.**
>
> A hands-on learning journey building a modular, bare-metal driver library for the **STM32F401RCT6**—from scratch, without STM32 HAL or vendor standard libraries. This repository is both a practical embedded-systems project and a growing portfolio focused on clear interfaces, maintainable architecture, and professional coding practices.

![Platform](https://img.shields.io/badge/Platform-STM32F401RCT6-blue)
![Core](https://img.shields.io/badge/Core-ARM%20Cortex--M4-informational)
![Language](https://img.shields.io/badge/Language-C-lightgrey)
![Approach](https://img.shields.io/badge/Approach-Bare%20Metal-success)
![Status](https://img.shields.io/badge/Status-In%20Progress-orange)

## Repository Architecture

The project follows a layered structure to keep hardware access, reusable utilities, and application code clearly separated:

| Folder | Responsibility |
| --- | --- |
| `LIB/` | Shared low-level utilities and common definitions, such as standard types and bit-manipulation macros. |
| `MCAL/` | Microcontroller abstraction drivers that configure and control STM32 peripherals through their registers. |
| `HAL/` | Higher-level drivers that build on the MCAL and provide convenient interfaces for external hardware. |
| `APP/` | Application code that brings the drivers together into demonstrations and firmware behavior. |

The library is being developed incrementally. **RCC is the first driver in `MCAL/`;** the other layers are reserved for upcoming work.

## Learning Journey

### Milestones

- [x] **Milestone 1: RCC (Reset and Clock Control) Driver**
  - Mapped RCC hardware registers with C structures, using `volatile` members and precisely sized reserved fields to preserve register offsets.
  - Used bit masking to modify individual register fields while preserving unrelated settings.
  - Added pre-build configuration options for HSI, HSE, PLL, and AHB/APB bus prescalers.
  - Documented the driver API and configuration with Doxygen-style tags such as `@brief` and `@details`.
  - Established an initial MCAL interface for system clock initialization and peripheral clock enable/disable operations.

Each milestone is an opportunity to understand the hardware more deeply while improving the structure and quality of the driver library.

## Upcoming Milestones

- [ ] **GPIO Driver** — pin modes, output types, speed, pull configurations, and I/O operations.
- [ ] **NVIC Driver** — interrupt enable/disable, priority configuration, and pending-state control.
- [ ] **EXTI Driver** — external interrupt/event configuration and trigger selection.

More drivers and application examples will be added as the journey progresses.

## Getting Started

Clone the repository to explore the source:

```bash
git clone https://github.com/omar-920/STM32F4-BareMetal-Journey.git
cd STM32F4-BareMetal-Journey
```

This repository is an evolving learning project. Check the milestone tracker and source tree for the latest progress.

## Project Philosophy

The goal is to learn the STM32F401RCT6 from the register level upward: read the reference manual, make each hardware interaction explicit, and shape the resulting code into a reusable driver library. No HAL shortcuts—just disciplined, documented bare-metal development.
