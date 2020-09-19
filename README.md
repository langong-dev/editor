# LanGong Text Editor

This editor is for Windows, MacOS, Linux.

- System need
  - Windows >= 7
  - MacOS >= catalina
  - Linux != arm
- Qt need
  - Qt >= 5
  


## Install

MacOS/Linux: Install `qt5-base` first

```
$ git clone https://github.com/langong-dev/editor.git
$ cd editor
$ qmake Editor.pro
$ make
# cp Editor /usr/bin/editor
# mkdir -p /usr/share/editor
# cp * /usr/share/editor
```

Windows: 

Download the setup file on releases page.
