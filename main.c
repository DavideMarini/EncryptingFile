#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>

int64_t handle_error(FILE* file, const char* msg){
	perror(msg);
	if(file != NULL) fclose(file);
	return -1;
}

// 
int64_t get_file_size(FILE* file){
	if(fseek(file, 0, SEEK_END) != 0) return handle_error(file, "fseek error");
	long fileSize = ftell(file);
	if(fileSize == -1L) return handle_error(file, "ftell error");
	rewind(file);
	if(ferror(file)) return handle_error(file, "rewind error");
	
	return (int64_t)(fileSize);
}

int64_t encrypt_xor(const char* file_path, const char* password){
	
	FILE* file = fopen(file_path, "rb");
	if(file == NULL) return handle_error(NULL, "Open file error");
	
	int64_t file_size = get_file_size(file);
	printf("fileSize: %lld\n", file_size);
	
	size_t pass_len = strlen(password);
	printf("passwordLen: %zu\n", pass_len);
	
	fclose(file);
	
	
	return 1;			
}

int main(){
	
	char* filePath = "secrets.txt";
	
	bool res = encrypt_xor(filePath, "1234password");
	
	printf("%d\n", res);
	
	
	
	
	
	
	
	
	return 0;
}