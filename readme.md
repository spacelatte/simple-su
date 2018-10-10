# simple-su: change user id without hassle

simple-su allows you to change user your user-id (uid) to anything you want. 
it needs to be `setuid` executable (aka. `chmod +s`)

it is compiled statically to allow embedded devices to have it (android and its friends)
uses plain old arm target to support as much as devices possible.

> tested to work on android 7.1 and 6.0.1

## requirements:

 - docker: uses docker image to compile binary
 
 
