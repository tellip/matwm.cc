## Description

*matwm* (short for *Matrix Window Manager*) is a tilling window manager that represents windows as the leaves of a pure general, customizable tree.

It only responds to X events, and the messages it receives on a dedicated socket.

*matc* is a program that writes messages on *matwm*'s socket.

*matwm* doesn't handle any keyboard inputs: a third party program (e.g. *sxhkd*) is needed in order to translate keyboard events to *matc* invocations.

The outlined architecture is the following:

```
        PROCESS          SOCKET
sxhkd  -------->  matc  <------>  matwm
```

## Usage

```
cd [path_to_repo]

cmake .
make
cp mat* ~/bin # make sure '~/bin' is in environment variable 'PATH'

nano ~/.config/sxhkdrc          # refer to      *sample/sxhkdrc*
nano ~/.config/matwm/matwmrc    # refer to      *sample/matwmrc*
nano ~/.xinitrc                 # add           '~/.config/matwm/matwmrc &' and 'exec matwm'
startx
```
