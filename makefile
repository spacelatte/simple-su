#!/usr/bin/env make -f

all: su

clean:
	rm -f su

su: su.c
	docker run --rm -t -v $$(pwd):/data pvtmert/python:3.5 arm-linux-gnueabi-gcc -static -o /data/$@ /data/$<

adb: su
	adb push $< /data/local/tmp
	adb shell su 0 mount -o remount,rw /system
	adb shell su 0 cp /data/local/tmp/su /system/su
	adb shell su 0 chown root:root /system/su
	adb shell su 0 chmod 0000 /system/su
	adb shell su 0 chmod +srx /system/su
	adb shell su 0 mount -o remount,ro /system
	adb shell /system/su 0 ls -la /system/su
	adb shell /system/su 0 /system/bin/id
	adb shell rm /data/local/tmp/su
