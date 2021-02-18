#include <iostream>
#include <time.h>
using namespace std;

short int func[64] = { 0 };
void createFunc(short int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		func[i] = rand() % 2;
		cout << func[i] << endl;
	}
}

void main() {
	//хранится число нулей среди параметров, соответственно строкам
	short int par2[4] = { 2,1,1,0 };
	/*short int par3[8] =  {																																			   3,2,2,1,||2,1,1,0 };
short int par4[16] = {																														   4,3,3,2,||3,2,2,1,||3,2,2,1,||2,1,1,0 };
short int par5[32] = {																				   5,4,4,3,||4,3,3,2,||4,3,3,2,||3,2,2,1,||4,3,3,2,||3,2,2,1,||3,2,2,1,||2,1,1,0 };
	short int par6[64] = { 6,5,5,4,5,4,4,3,5,4,4,3,4,3,3,2,5,4,4,3,4,3,3,2,4,3,3,2,3,2,2,1,5,4,4,3,4,3,3,2,4,3,3,2,3,2,2,1,4,3,3,2,3,2,2,1,3,2,2,1,2,1,1,0 };
	*/
	short int par6[64] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6 };
	short int sknf = 0;
	short int sdnf = 0;

	cout << "enter the quantity of parameters: ";
	int sizee = 0; cin >> sizee; cout << endl;
	short int sizeUnchanged = sizee;
	/*cout << "enter the function: ";
	for (int i = 0; i < sizee; i++) { cin >> func[i]; }*/
	sizee = pow(2, sizee);
	createFunc(sizee);
	sizee--;
	sizee *= 2;

	//jc -> 1, jnc -> 0
	_asm {
		mov ecx, sizee
		; SDNF
		xor ax, ax
		; SKNF
		xor dx, dx
		mainCycle :

			mov bx, func[ecx]
			cmp bx, 1
			jne sknff
			; SDNF
			mov bx, sizeUnchanged
			sub bx, par6[ecx]
			add ax, bx
			jmp endMainCycle
			; т.к.хранится количество единиц, то для получения числа нулей, вычтем его из числа параметров
		sknff :
			add dx, par6[ecx]
			endMainCycle :
			sub ecx, 2
			cmp ecx, 0
		jge mainCycle

			mov sdnf, ax
			mov sknf, dx
	}
	cout << endl << "SKNF: " << sknf << ", SDNF: " << sdnf << endl;
	if (sdnf > sknf) cout << "sKnf is better";
	if (sdnf < sknf) cout << "sDnf is better";
	if (sdnf == sknf) cout << "both sdnf and sknf are equal";
}