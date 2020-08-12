# Getting Started

## Background - Approach to this workspace

This project configuration is WAY more complex than it would be for a specific project, because I'm trying to support multiple build tools within one project workspace, as a development environment and showcase for reusability / redeployability.

My primary development environment is based on Eclipse, though I also am using
* an ancient version of LabWindows/CVI (v7.1);
* an old version of Visual Studio (2010, still downloadable from MS as of the time of this writing);
* MPLAB X (current version as of this writing);
* NetBeans (I've been using v8.2 but will upgrade soon).

I have also experimented with other IDEs (e.g., CodeLite).
 
Within Eclipse, the build configuration is available as an IDE variable named `${ConfigName}`. This can be put into a command-line define, for use in the code itself: within this project's settings, this is done by defining a command-line define named

    XPRJ_${ConfigName}"

This symbol can be used by preprocessor code, as in 

	#if defined(XPRJ_Debug)

Within MPLAB X, the equivalent mechanism is to detect the command-line define "XPRJ_NB_${CONF}", created by the new-project wizard

	#if defined(XPRJ_Debug)

Note the name of the default configuration created by MPLAB X' New Project wizard is `default` - if you want a configuration named `Debug`, you need to create it.


Within Visual Studio, the environment variable to tap is `$(Configuration)`, as in

    #define XPRJ_Win_MSVC_$(Configuration)



Within my development environment, I let Eclipse' New Project Wizard create its standard Debug and Release configurations, then create new ones for on-target debugging, as required. I assume my Windows/Linux Debug configuration is also intended for unit tests, so I rather indiscriminately print things to the console.


## Another word

ANSI/ISO C says that the preprocessor evaluates an undefined symbol as having the value `0` - however, many of the environments i'm targeting, and also many static analysis tools, emit warnings about usage of undefined symbols in normal C code. Even though I do it when necessary, I have a rather strong aversion to using `#if defined(x)` mechanisms in normal code. Therefore, I'll here define all of the non-active build targets.
