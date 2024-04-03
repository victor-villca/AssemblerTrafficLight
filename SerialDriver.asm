.386
.model flat, stdcall
option casemap:none


.DATA
	file_handle HANDLE ?
	filename db "buffer.txt",0
	execute_path db "driver.exe",0
	error_serial_driver_message db "file not found",0
	
.CODE
writeToSerial PROC message:DWORD

    invoke CreateFileA, addr filename, GENERIC_WRITE, FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
    mov file_handle, eax 
    
    .if file_handle == INVALID_HANDLE_VALUE
        invoke MessageBoxA, 0, addr error_serial_driver_message, 0, MB_OK
        ret
    .endif
    invoke SetFilePointer, file_handle, 0, 0, FILE_END
    
    
    
      write_txt_file:
    	push message
    	call lstrlen 
    	push 0
    	push 0
    	push eax
    	push message
    	push file_handle
    	call WriteFile

    invoke CloseHandle, file_handle

    invoke WinExec, addr execute_path, SW_SHOWNORMAL

    ret

writeToSerial ENDP
