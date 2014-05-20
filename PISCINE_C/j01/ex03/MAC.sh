#!/bin/sh
ifconfig | grep ether | cut -c8- | sed "s/ //"
