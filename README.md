# qtCheckBoxWordWrapPlugin
[![Build Status](https://travis-ci.org/thibDev/qtCheckBoxWordWrapPlugin.svg?branch=master)](https://travis-ci.org/thibDev/qtCheckBoxWordWrapPlugin)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)  

A Qt plugin to use graphically QCheckbox with word wrap in QtDesigner

|<div style="text-align:center;">In program</div>|<div style="text-align:center;">In designer</div>|
|------|------|
|<div style="text-align:center"><img src ="screenshots/plugins_result.png"/></div>|<div style="text-align:center"><img src ="screenshots/plugins_in_designer.png"/><img src ="screenshots/plugins_properties.png"/></div>|

## Requirements

* qt5-default
* libqt5designer5
* qttools5-dev

## Compile & install

```sh
mkdir build
cd build
qmake ../CheckBoxWordWrap.pro
make release
cp libcheckboxwordwrapplugin.so ~/Qt/Tools/QtCreator/lib/Qt/plugins/designer/
```
