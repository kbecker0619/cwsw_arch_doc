# Stoplite Demo Application

This workspace illustrates how to use the CWSW component libraries.

* each reusable component is embedded herein as a Git submodule.
* The IDE projects can be found underneath the `test` folder.
* The Eclipse project requires GTK. Note that if you have installed MSYS2 (or the Git for Windows SDK which is built on MSYS2), this can be added by a simple invocation of `pacman`.
* The LabWindows/CVI project is for a truly ancient version of LW/CVI (7.1), and is used mainly only for the UI panel (different than GTK, easier to use than GTK, and has built-in widgets I want, such as LEDs, in contrast to GTK)
* The Visual Express 2010 project uses the "none" BSP (Board Support Package) and uses the console to show the status of LEDs. Keyboard interaction is missing.

