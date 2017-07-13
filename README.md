bsb-native-example
---

This is a quick demo project to showcase [bsb-native](https://github.com/bsansouci/bsb-native). This actually uses the [#ocamlfind-trial](https://github.com/bsansouci/bsb-native/tree/ocamlfind-trial) branch which allows you to depend on any package on opam.

For publishing on opam see [opam_of_packagejson](https://github.com/bsansouci/opam_of_packagejson/) as a helper.


## Install
`npm i`

## Build
`./node_modules/.bin/bsb -make-world`

## Run
`./lib/bs/index.byte`
