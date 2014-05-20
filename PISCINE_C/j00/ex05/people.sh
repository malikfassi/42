#!/usr/bin/
ldapsearch  'objectclass=apple-user' | grep uid: | sort -r -f | cut -c6-
