# simple-su: change user id without hassle

simple-su allows you to change user your user-id (uid) to anything you want. 
it needs to be `setuid` executable (aka. `chmod +s`)

it is compiled statically to allow embedded devices to have it (android and its friends)
uses plain old arm target to support as much as devices possible.

> tested to work on android 7.1 and 6.0.1

### requirements:

 - docker: uses docker image to compile binary
 
 
### install:

 - run `make`
 - you can now use `su` executable
 - remember to make it setuid and owned by root to function properly
 
### setuid and root ownership:

 - `chown root:root su`
 - `chmod +srx su`
 - thats all!
 
 **WARNING**: this wont root your device, if its already rooted, but you want to bypass frontend checks (aka. SuperSU) or its only rooted when in `adb shell`, not inside device. You can put `su` binary to `/system/xbin` from `adb shell` then use it inside android apps.
 
 
