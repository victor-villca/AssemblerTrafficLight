.386
.model flat, stdcall
option casemap:none


include SerialDriver.inc

.CODE
PUBLIC writeToSerial
 
writeToSerial PROC messageToSend:DWORD

    invoke CreateFile, addr compPort, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL    
    cmp eax, INVALID_HANDLE_VALUE
    je error_open_port
    mov hComTx, eax
    
    invoke WriteFile, hComTx, messageToSend, sizeof messageToSend, NULL, NULL
    test eax, eax
    jz error_write
    
    invoke Sleep, 500
    
    invoke CloseHandle, hComTx
    ret

error_open_port:
    invoke MessageBox, NULL, addr errorOpenSerialMessage, addr errorTitleSerial, MB_OK
    ret

error_write:
    invoke MessageBox, NULL, addr errorWriteSerialMessage, addr errorTitleSerial, MB_OK
    ret

writeToSerial ENDP
