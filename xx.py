#!/usr/bin/python
#encoding=utf-8

str1 = '\u4f60\u597d'  
print str1.decode('unicode_escape')  

#encoding=utf-8
f=file("test.txt","r")
print f.readline().decode('unicode_escape')  
f.close
