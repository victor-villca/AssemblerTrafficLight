
include windows.inc
include kernel32.inc
include user32.inc
include Comctl32.inc
include shell32.inc

include SerialDriver.asm

includelib kernel32.lib
includelib user32.lib
includelib Comctl32.lib
includelib shell32.lib



menuP			PROTO	:HWND,:UINT,:WPARAM,:LPARAM
loginRegister	PROTO	:HWND,:UINT,:WPARAM,:LPARAM

.const

IDD_DIALOG1			equ 101
IDD_DIALOG2			equ 1000
LOGIN_BUTTON		equ 1005 
REGISTER_BUTTON		equ 1006
USER_TEXT			equ 1002
PASSWORD_TEXT		equ 1004
LOGOUT_BUTTON		equ 1002

OFF_BUTTON			equ 1001
ON_BUTTON 			equ 1003

PUSH_BUTTON_1		equ 1007
PUSH_BUTTON_2 		equ 1008


CHANGE_RED 			equ 1011
CHANGE_YELLOW 			equ 1011
CHANGE_GREEN 			equ 1011


  


;#########################################################################

.data?

hInstance			dd ?
inputUser 				db 32 dup('0')
inputPassword 			db 32 dup('0')

redTime					db 32 dup('0')
yellowTime				db 32 dup('0')
greenTime				db 32 dup('0')

;#########################################################################

.data
successLogin			db "Login Successful",0
successRegistration		db "Registration Successful",0
adminUser				db "admin",0
adminPassword			db "123456789",0
badUsernameMsg			db "Incorrect Username",0
badPasswordMsg			db "Incorrect Password",0
loginTitle				db "Registration",0
errorTitle				db "Error -  Bad Credentials",0
OffMessage 				db 13,10,"L",0
OnMessage				db 13,10,"H",0
PushMessage1			db 13,10,"1",0
PushMessage2			db 13,10,"2",0

driverMessage 			db "Driver Messenger",0
semophoreOn				db "The traffic light is on",0
semophoreOff			db "The traffic light is off",0
push1					db "Push 1 sent",0
push2					db "Push 2 sent",0

redTimePrefix				db "R-",0
yellowTimePrefix			db "Y-",0
greenTimePrefix				db "G-",0


