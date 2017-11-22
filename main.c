#include<stdio.h>
#include<conio.h>
#include "DES.h"

_64Bit encrypt(_64Bit inp, _64Bit key){
	_64Bit res=initialPermutation(inp);
	_64Bit keySet[16];
	generateKey(key,keySet);
	short i;
	for(i=0;i<16;i++){
		res=round(i,res,keySet[i]);
		printf("%016llX\n",keySet[i]);
	}
	res=((res&0xffffffff)<<32)+(res>>32);
	res=finalPermutation(res);
	return res;
}

_64Bit decrypt(_64Bit inp, _64Bit key){
	_64Bit res=initialPermutation(inp);
	_64Bit keySet[16];
	generateKey(key,keySet);
	short i;
	for(i=15;i>=0;i--){
		res=round(i,res,keySet[i]);
		printf("%016llX\n",keySet[i]);
	}
	res=((res&0xffffffff)<<32)+(res>>32);
	res=finalPermutation(res);
	return res;
}

int main() {
	_64Bit data_p,data_c,data_r,key;
	// INPUT
	data_p=0x9d31a0ee3e72c809;
	key=   0x9977543311bbcdff;
	encrypt(data_p,key);
	/*
	printf("Plaintext : %016llX\n",data_p);
	printf("Key       : %016llX\n\n",key);
	// ENCRYPTION
	data_c=encrypt(data_p,key);
	printf("Ciphertext is : %016llX\n\n",data_c);
	// DECRYPTION
	data_r=decrypt(data_c,key);
	printf("Plaintext (recover) is : %016llX\n\n",data_r);*/
	return 0;
}