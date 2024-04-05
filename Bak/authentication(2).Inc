
include windows.inc
include kernel32.inc
include user32.inc
include Comctl32.inc
include shell32.inc

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


;#########################################################################

.data?

hInstance			dd ?
inputUser 				db 32 dup('0')
inputPassword 			db 32 dup('0')

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


